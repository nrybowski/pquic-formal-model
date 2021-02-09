from pycparser import parse_file, c_ast, c_generator, c_parser

C_DEFINES = ['unsigned int', 'int', 'unsigned long']
# TODO : TMP
C_DEFINES += ['uint8_t', 'uint16_t', 'uint64_t', 'uint32_t', 'size_t']

DUMMIES = []
FTYPES = {'assume': 'assume_cp__', 'assert': 'assert_cp__', 'init': 'init__', 'dummy_cp': 'dummy_cp__', 'dummy_init': 'dummy__'}

""" ############### """
""" Generation part """
""" ############### """

def gen_ptr_access(struct, field, make_pointer=False):
    return c_ast.StructRef(c_ast.ID('%s%s' % ('&' if make_pointer else '',struct)), '->', c_ast.ID(field))

def gen_field_comp(st1, st2, field):
    left = gen_ptr_access(st1, field)
    right = gen_ptr_access(st2, field)
    return c_ast.BinaryOp('==', left, right)

def gen_signature(ftype, name, params, extern=False):
    """ Generate a function signature in the pycparser format
        @in ftype : the function type (@see FTYPES)
        @in name : the structure which requires this function's signature
        @in params : the list of params to generate in the signature
        @in extern : is the function declared as extern 

        @return : the function's signature
    """

    # Generate function's name
    try:
        fname = '%s%s' % (FTYPES[ftype], name if ' ' not in name else '_'.join(name.split(' ')))
    except KeyError:
        print('Unknown function type %s' % ftype)
        return None

    # Function's parameters declaration
    l = [c_ast.Decl(param, [], [], [], c_ast.PtrDecl([], c_ast.TypeDecl(param, [], c_ast.IdentifierType([name]))), None, None) for param in params]
    param_list = c_ast.ParamList(l)

    # Function's output type declaration
    output_type = []
    if not extern:
        output_type.append('inline')
    if ftype == 'dummy_init':
        #output_type.append(name if ' ' not in name else '_'.join(name.split(' ')))
        output_type.append(name)
    else:
        output_type.append('void')
    func_type = c_ast.TypeDecl(fname, [], c_ast.IdentifierType(output_type))

    # Function's signature declaration
    func_decl = c_ast.FuncDecl(param_list, func_type)
    signature = c_ast.Decl(fname, [], ['extern'] if extern else [], [], func_decl, None, None)

    return signature

def gen_body(name, ftype, param_names, struct_decls):
    def gen_body_init():

        i = ' '.join(data['subtype'])
        a = '_'.join(data['subtype'])
        if i not in DUMMIES and i in C_DEFINES:
            # Add dummy init__<subtype>() declaration in the header file
            DUMMIES.append(i)

        func_call = c_ast.ID('dummy__%s' % a)

        if data['type'] == c_ast.TypeDecl:
            # param1-><field> = dummy__<data['id']>();
            body.append(c_ast.Assignment('=', gen_ptr_access(st1, field), c_ast.FuncCall(func_call, None), None))

        elif data['type'] == c_ast.Struct:
            body.append(c_ast.FuncCall(c_ast.ID('init__%s' % '_'.join(data['subtype'])), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True)])))

        elif data['type'] == c_ast.ArrayDecl:
            if ' '.join(data['subtype']) not in C_DEFINES:
                # TODO : currently skip array of user defined types since it requires new init functions
                return
            for entry in range(0, data['dim']):
                # param1-><field>[<entry>] = dummy__<data['id']>();
                body.append(c_ast.Assignment('=', c_ast.ArrayRef(gen_ptr_access(st1, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))), c_ast.FuncCall(func_call, None)))

        # elif data['type'] == c_ast.PtrDecl:
        #    # TODO : currently unsupported
        #    pass


    def gen_body_assume():
        if data['type'] == c_ast.TypeDecl:
            # assume(src-><field> == dst-><field>);
            #body.append(c_ast.FuncCall(c_ast.ID(ftype), c_ast.ExprList([gen_field_comp(st1, st2, field)])))
            body.append(c_ast.Assignment('=', gen_ptr_access(st2, field), gen_ptr_access(st1, field)))


        elif data['type'] == c_ast.Struct:
            # assume_cp__<subtype>(&src->field, &dst-field);
            body.append(c_ast.FuncCall(c_ast.ID('%s_cp__%s' % (ftype, ' '.join(data['subtype']))), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True), gen_ptr_access(st2, field, make_pointer=True)])))
        elif data['type'] == c_ast.ArrayDecl:
            if ' '.join(data['subtype']) not in C_DEFINES:
                # TODO : currently skip array of user defined types since it requires new init functions
                return
            for entry in range(0, data['dim']):
                # assume(src-><field>[<entry>] == dst-><field>[<entry>]);
                body.append(c_ast.Assignment('=', c_ast.ArrayRef(gen_ptr_access(st2, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))), c_ast.ArrayRef(gen_ptr_access(st1, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry)))))
                #body.append(
                #    c_ast.FuncCall(c_ast.ID(ftype), 
                #                   c_ast.ExprList([c_ast.BinaryOp('==', 
                #                       c_ast.ArrayRef(gen_ptr_access(st1, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))),
                #                       c_ast.ArrayRef(gen_ptr_access(st2, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))))])))

    def gen_body_assert():
        if data['type'] == c_ast.TypeDecl:
            # cond &= src-><field> == dst->field
            body.append(c_ast.Assignment('&=', c_ast.ID('cond'), gen_field_comp(st1, st2, field)))

        elif data['type'] == c_ast.Struct:
            # if struct field is another struct, call assume_cp__<sub_struct>
            body.append(c_ast.FuncCall(c_ast.ID('%s_cp__%s' % (ftype, ' '.join(data['subtype']))), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True), gen_ptr_access(st2, field, make_pointer=True)])))

        elif data['type'] == c_ast.ArrayDecl:
            if ' '.join(data['subtype']) not in C_DEFINES:
                # TODO : currently skip array of user defined types since it requires new init functions
                return
            for entry in range(0, data['dim']):
                body.append(c_ast.Assignment('&=', c_ast.ID('cond'), c_ast.BinaryOp('==', 
                                       c_ast.ArrayRef(gen_ptr_access(st1, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))),
                                       c_ast.ArrayRef(gen_ptr_access(st2, field), c_ast.Constant(c_ast.ID(data['subtype']), str(entry))))))

    body = []
    accepted = list(FTYPES.keys())
    if ftype not in accepted:
        return body

    # Unpack parameters for comparisons
    st1, st2 = param_names if len(param_names) == 2 else (param_names[0], None)

    # Set the first line of the body if required
    if ftype == accepted[0]:
        # Add : dummy_cp__<name>(src, dst);
        #body.append(c_ast.FuncCall(c_ast.ID('dummy_cp__%s' % name), c_ast.ExprList([c_ast.ID(st1), c_ast.ID(st2)])))
        pass
    elif ftype == accepted[1]:
        # Add : unsigned int cond = 1;
        body.append(c_ast.Decl('cond', [], [], [], c_ast.TypeDecl('cond', [], c_ast.IdentifierType(['unsigned', 'int'])), c_ast.Constant('int', '1'), None))

    if ftype == accepted[0]:
        field_fun = gen_body_assume
    elif ftype == accepted[1]:
        field_fun = gen_body_assert
    elif ftype == accepted[2]:
        field_fun = gen_body_init

    for field, data in struct_decls.items():
        # For each field, generates the appropriate data
        field_fun()

     # Set the last line of the body if required
    if ftype == accepted[1]:
        # Add : sassert(cond);
        body.append(c_ast.FuncCall(c_ast.ID('sassert'), c_ast.ExprList([c_ast.ID('cond')])))

    return body

def gen_function(ftype, name, params, struct):
    # Generate signature
    signature = gen_signature(ftype, name, params)

    # Generate function body
    body = gen_body(name, ftype, params, struct)

    # Return whole function definition
    func_def = c_ast.FuncDef(signature, [], c_ast.Compound(body))

    return (func_def, signature)

# TODO : put dummy generation in assume generation
def gen_dummy_cp(name):
    ftype = 'dummy_cp'
    params = ['src', 'dst']

    return gen_signature(ftype, name, params, extern=True)

def gen_assume_cp(name, struct):
    ftype = 'assume'
    params = ['src', 'dst']

    return gen_function(ftype, name, params, struct)

def gen_assert_cp(name, struct):
    ftype = 'assert'
    params = ['param1', 'param2']

    return gen_function(ftype, name, params, struct)

def gen_init(name, struct):
    ftype = 'init'
    params = ['param1']

    return gen_function(ftype, name, params, struct)


""" ############ """
""" Parsing part """
""" ############ """

def parse_ast(ast):
    """ Parse a pycparser AST into a dict representation
    """
    ast_dic = {}
    for decl in ast:

        # Get C defined data like stdint
        if type(decl) == c_ast.Typedef and type(decl.type) == c_ast.TypeDecl and type(decl.type.type) == c_ast.IdentifierType:
            #C_DEFINES.append(decl.name)
            pass

        elif type(decl) == c_ast.Typedef and type(decl.type) == c_ast.TypeDecl and type(decl.type.type) == c_ast.Struct:
            # Got a structure definition
            struct = decl.type.type

            # TODO : change to look if identifier in C_DEFINES
            if struct.name is None or 'picoquic' not in struct.name:
                # Remove useless structure definitions
                continue
          
            parsed_struct_decls = {}
            if struct.decls is not None:
                # If any field in the structure
                for field_decl in struct:
                    # Parse each field of the structure

                    # Get main type of the field
                    field = field_decl.type

                    data = {}
                    subtype = None
                    field_subtype = field.type
                    t = type(field)

                     # Override the subtype if required
                    if type(field_subtype) == c_ast.IdentifierType:
                        subtype = field_subtype.names
                    elif type(field_subtype) == c_ast.Struct:
                        subtype = [field_subtype.name]


                    if type(field) == c_ast.TypeDecl:
                        # Main type is a "simple" field
                        field_name = field.declname
                        field_subtype = field.type
                        t = type(field) if ' '.join(subtype) in C_DEFINES else c_ast.Struct

                    elif type(field) == c_ast.PtrDecl:
                        # Main type is a pointer

                        # handle double pointers
                        field_name = field_subtype.declname if type(field_subtype) != c_ast.PtrDecl else field_subtype.type.declname
                        subtype = field_subtype.type.names if type(field_subtype.type) == c_ast.IdentifierType else 'UNKOWN'

                        # TODO : Need to define subtype of the pointer

                    elif type(field) == c_ast.ArrayDecl:
                        # Main type is an array

                        if type(field_subtype) == c_ast.PtrDecl:
                            # Currently skip the array of pointers case
                            continue

                        field_name = field_subtype.declname
                        subtype = field_subtype.type.names

                        if type(field.dim) == c_ast.Constant:
                            # If array has a defined size
                            data['dim'] = int(field.dim.value)
                        sub = field_subtype.type
                    else:
                        # TODO : handler other fields types
                        continue

                    parsed_struct_decls[field_name] = {**{'type': t}, **data}

                    if subtype is not None:
                        parsed_struct_decls[field_name]['subtype'] = subtype


            ast_dic[decl.name] = parsed_struct_decls

    return ast_dic

ast = parse_file('../pquic/picoquic/picoquic_internal.h', use_cpp=True, cpp_path='clang', cpp_args=['-E', r'-I../pycparser/utils/fake_libc_include'])
old_ast = parse_ast(ast)
print(old_ast['picoquic_packet_context_t'])

# Create empty AST
new_parser = c_parser.CParser()
new_ast_c = new_parser.parse('')
new_ast_h = new_parser.parse('')

generated = []
ungenerable = []
init_signatures = []
init_implems = []
assume_signatures = []
sassert_signatures = []
assume_implems = []
sassert_implems = []

def fgen(name, struct):
    print('Generating %s' % name)
    # Helper already generated
    if name not in generated:
        generated.append(name)

    # Add dummy helper in header file
    new_ast_h.ext.append(gen_dummy_cp(name))

    # Collect additional helper required for current helper
    collect = []
    for data in struct.values():
        if data['type'] == c_ast.Struct and ' '.join(data['subtype']) not in collect:
                collect.append(data['subtype'][0])

    # For each additional helper, generated it if possible
    for new_name in collect:
        if new_name in old_ast.keys():
            if new_name not in generated:
                print('\tRequires %s' % new_name)
                fgen(new_name, old_ast[new_name])
            else:
                print('Already generated : %s' % new_name)
        else:
            print('Error: %s' % new_name)
            ungenerable.append(new_name)

    cleaned_struct = {i: j for i, j in struct.items() if ' '.join(j['subtype']) not in ungenerable}

    init_fun, init_sig = gen_init(name, cleaned_struct)
    assume_fun, assume_sig = gen_assume_cp(name, cleaned_struct)
    assert_fun, assert_sig = gen_assert_cp(name, cleaned_struct)

    init_signatures.append(init_sig)
    init_implems.append(init_fun)
    assume_signatures.append(assume_sig)
    assume_implems.append(assume_fun)
    sassert_signatures.append(assert_sig)
    sassert_implems.append(assert_fun)

for struct in ['picoquic_cnx_t', 'picoquic_packet_context_t', 'picoquic_path_t']:
    fgen(struct, old_ast[struct])

print('ungenerable %s' % ungenerable)

TMP_DUMMIES = []
for dummy in DUMMIES:
    TMP_DUMMIES.append(gen_signature('dummy_init', dummy, [], extern=True))
new_ast_h.ext += TMP_DUMMIES

new_ast_h.ext += init_signatures
new_ast_c.ext += init_implems
new_ast_h.ext += assume_signatures
new_ast_c.ext += assume_implems
new_ast_h.ext += sassert_signatures
new_ast_c.ext += sassert_implems

# Generate C code from the new AST
generator = c_generator.CGenerator()

"""print('\nHeader file')
print(generator.visit(new_ast_h))
print('C file')
print(generator.visit(new_ast_c))"""

print(C_DEFINES)

with open('verifier/verifier.c', 'w') as fp:
    fp.write('#include "verifier/verifier.h"\n\n')
    fp.write('/* WARNING : this file is automagically generated. */\n\n')
    fp.write(generator.visit(new_ast_c))

with open('verifier/verifier.h', 'w') as fp:
    fp.write('#include "picoquic_internal.h"\n')
    fp.write('#include "seahorn/seahorn.h"\n\n')
    fp.write('/* WARNING : this file is automagically generated. */\n\n')
    fp.write(generator.visit(new_ast_h))
