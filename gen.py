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

    body = []
    print(struct_decls)
    """
    accepted = ['assume', 'sassert', 'init']
    if ftype not in accepted:
        return body
    """
    accepted = list(FTYPES.keys())
    if ftype not in accepted:
        return body

    # Unpack parameters for comparisons
    st1, st2 = param_names if len(param_names) == 2 else (param_names[0], None)

    if ftype == accepted[0]:
        body.append(c_ast.FuncCall(c_ast.ID('dummy_cp__%s' % name), c_ast.ExprList([c_ast.ID(st1), c_ast.ID(st2)])))
    elif ftype == accepted[1]:
        body.append(c_ast.Decl('cond', [], [], [], c_ast.TypeDecl('cond', [], c_ast.IdentifierType(['unsigned', 'int'])), c_ast.Constant('int', '1'), None))

    for field, data in struct_decls.items():
        if data['type'] == c_ast.TypeDecl:
            # if struct field is not a ptr nor a structure
            if ftype == accepted[0]:
                # assume field copy
                body.append(c_ast.FuncCall(c_ast.ID(ftype), c_ast.ExprList([gen_field_comp(st1, st2, field)])))
            elif ftype == accepted[1]:
                # compare fields and store the result in cond
                body.append(c_ast.Assignment('&=', c_ast.ID('cond'), gen_field_comp(st1, st2, field)))
            elif ftype == accepted[2]:
                # ftype = 'init'
                i = ' '.join(data['id'])
                a = '_'.join(data['id'])
                if i in C_DEFINES:
                    func_call = c_ast.ID('dummy__%s' % a)
                    body.append(c_ast.Assignment('=', gen_ptr_access(st1, field), c_ast.FuncCall(func_call, None), None))
                    if i not in DUMMIES:
                        DUMMIES.append(i)
                else:
                    pass
                    #body.append(c_ast.FuncCall(c_ast.ID('init__%s' % a), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True)])))
        elif data['type'] == c_ast.Struct:
            if ftype == accepted[2]:
                body.append(c_ast.FuncCall(c_ast.ID('init__%s' % '_'.join(data['id'])), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True)])))
            else:
                # if struct field is another struct, call assume_cp__<sub_struct>
                body.append(c_ast.FuncCall(c_ast.ID('%s_cp__%s' % (ftype, data['id'][-1])), c_ast.ExprList([gen_ptr_access(st1, field, make_pointer=True), gen_ptr_access(st2, field, make_pointer=True)])))
        elif data['type'] == c_ast.PtrDecl:
            # currently unsupported
            pass

    if ftype == accepted[1]:
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
    #return gen_signature(ftype, name, params)

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

ast = parse_file('../pquic/picoquic/picoquic_internal.h', use_cpp=True, cpp_path='clang', cpp_args=['-E', r'-I../pycparser/utils/fake_libc_include'])

# Create empty AST
new_parser = c_parser.CParser()
new_ast_c = new_parser.parse('')
new_ast_h = new_parser.parse('')

def parse_ast(ast):
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
            #decl.type.show()
            #print()

            parsed_struct_decls = {}
            if struct.decls is not None:
                for struct_decl in struct:
                    decl_type = struct_decl.type
                    #decl_type.show()
                    #print()

                    if type(decl_type) == c_ast.TypeDecl:
                        n = decl_type.declname
                        t = 'type'
                        sub = decl_type.type

                    elif type(decl_type) == c_ast.PtrDecl:
                        # handle double pointers
                        n = decl_type.type.declname if type(decl_type.type) != c_ast.PtrDecl else decl_type.type.type.declname
                        t = 'ptr'
                        id = decl_type.type.type.names if type(decl_type.type.type) == c_ast.IdentifierType else 'UNKOWN'
                        sub = decl_type.type.type
                    else:
                        # TODO : handler other fields types
                        # ArrayDecl
                        # PtrDecl
                        continue

                    if type(sub) == c_ast.IdentifierType:
                        # field is a variable
                        id = sub.names
                    elif type(sub) == c_ast.Struct:
                        # field is a structure
                        id = [sub.name]
                    else:
                        id = 'Unkown'

                    if type(decl_type) == c_ast.TypeDecl:
                        t = type(decl_type) if 'picoquic' not in ' '.join(id) else c_ast.Struct
                    else:
                        t = type(decl_type)

                    parsed_struct_decls[n] = {'type': t, 'id': id}

            ast_dic[decl.name] = parsed_struct_decls
    return ast_dic

        # For each generated function, add it into the AST
        #new_ast_c.ext.append(gen_dummy_cp(decl.name, parsed_struct_decls))
        #new_ast_c.ext.append(gen_assume_cp(decl.name, parsed_struct_decls))

old_ast = parse_ast(ast)

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
        if data['type'] == c_ast.Struct and data['id'][0] not in collect:
                collect.append(data['id'][0])

    # For each additional helper, generated it if possible
    for new_name in collect:
        if new_name in old_ast.keys():
            if new_name not in generated:
                fgen(new_name, old_ast[new_name])
            else:
                print('Already generated : %s' % new_name)
        else:
            print('Error: %s' % new_name)
            ungenerable.append(new_name)

    cleaned_struct = {i: j for i, j in struct.items() if j['id'][0] not in ungenerable}

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

print('\nHeader file')
print(generator.visit(new_ast_h))
print('C file')
print(generator.visit(new_ast_c))

print(C_DEFINES)

"""tmp = new_parser.parse('')
tmp.ext.append(gen_sassert_cmp('picoquic_packet_context_t', old_ast['picoquic_packet_context_t'])[0])
print(generator.visit(tmp))
"""

with open('verifier/verifier.c', 'w') as fp:
    fp.write('#include "verifier/verifier.h"\n\n')
    #fp.write('#include "tmp.h"\n\n')
    fp.write(generator.visit(new_ast_c))

with open('verifier/verifier.h', 'w') as fp:
    fp.write('#include "picoquic_internal.h"\n')
    fp.write('#include "seahorn/seahorn.h"\n\n')
    fp.write(generator.visit(new_ast_h))
