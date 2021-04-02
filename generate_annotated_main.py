from json import load
from sys import argv

from pycparser import c_parser, c_ast, c_generator

def usage():
    print('usage')

def generate_main():
    parser = c_parser.CParser()
    fun_ast = parser.parse('')

    body = []

    for cnx in ['cnx', 'cnx0']:
        # Add : picoquic_cnx_t <cnx>;
        body.append(c_ast.Decl(cnx, [], [], [], c_ast.TypeDecl(cnx, [], c_ast.IdentifierType(['picoquic_cnx_t'])), None, None))

    # Add : init__picoquic_cnx_t(&cnx);
    body.append(c_ast.FuncCall(c_ast.ID('init__picoquic_cnx_t'), c_ast.ExprList([c_ast.ID('&cnx')])))

    # Add : assume(cnx.protoop_inputc == <nb inputc>);
    body.append(c_ast.Assignment('=', c_ast.StructRef(c_ast.ID('cnx'), '.', c_ast.ID('protoop_inputc')), c_ast.Constant('int', str(len(protoop_specs['inputs']))), c_ast.ExprList([])))

    # Add : assume_cp__picoquic_cnx_t(&cnx, &cnx0);
    body.append(c_ast.FuncCall(c_ast.ID('assume_cp__picoquic_cnx_t'), c_ast.ExprList([c_ast.ID('&cnx'), c_ast.ID('&cnx0')])))

    idx = 0
    for input_name, input_type in protoop_specs['inputs'].items():
        # Add : <type> <name>;
        body.append(c_ast.Decl(input_name, [], [], [], c_ast.TypeDecl(input_name, [], c_ast.IdentifierType([input_type[0]])), None, None))
        left = c_ast.ArrayRef(c_ast.StructRef(c_ast.ID('cnx'), '.', c_ast.ID('protoop_inputv')), c_ast.Constant('int', str(idx)))
        if '*' in input_type:
            # Add : <type> <name>0;
            body.append(c_ast.Decl('%s0' % input_name, [], [], [], c_ast.TypeDecl('%s0' % input_name, [], c_ast.IdentifierType([input_type[0]])), None, None))
            # Add : init__<type>(&<name>);
            body.append(c_ast.FuncCall(c_ast.ID('init__%s' % input_type[0]), c_ast.ExprList([c_ast.UnaryOp('&', c_ast.ID(input_name))])))
            body.append(c_ast.FuncCall(c_ast.ID('assume_cp__%s' % input_type[0]), c_ast.ExprList([c_ast.ID('&%s' % input_name), c_ast.UnaryOp('&', c_ast.ID('%s0' % input_name))])))
            right = c_ast.Cast(c_ast.Typename(None, [], c_ast.TypeDecl(None, [], c_ast.IdentifierType(['protoop_arg_t']))), c_ast.UnaryOp('&', c_ast.ID(input_name)))
        else:
            body.append(c_ast.Assignment('=', c_ast.ID(input_name), c_ast.FuncCall(c_ast.ID('dummy__%s' % input_type[0]), c_ast.ExprList([]))))
            right = c_ast.ID(input_name)

        body.append(c_ast.Assignment('=', left, right, None))

        idx += 1

    # Add : <plugin>(cnx);
    body.append(c_ast.FuncCall(c_ast.ID(protoop_specs['name']), c_ast.ExprList([c_ast.ID('&cnx')])))

    idx = 0
    for input_name, input_type in protoop_specs['inputs'].items():
        # right_ref = cnx.protoop_inputv[idx]
        right_ref = c_ast.ArrayRef(c_ast.StructRef(c_ast.ID('cnx'), '.', c_ast.ID('protoop_inputv')), c_ast.Constant('int', str(idx)))
        right = c_ast.Cast(c_ast.Typename(None, [], c_ast.TypeDecl(None, [], c_ast.IdentifierType([input_type[0]]))), right_ref)
        if '*' in input_type:
            if input_name not in protoop_specs['effects']:
                flag = 'ASSERT_NONE' 
            else:
                flag = ' | '.join([str.upper('assert_%s__%s' % (input_type[0], field)) for field in  protoop_specs['effects'][input_name]])
            
            cnx_input = c_ast.Cast(c_ast.Typename(None, [], c_ast.PtrDecl([], c_ast.TypeDecl(None, [], c_ast.IdentifierType([input_type[0]])))), right_ref)
            
            body.append(c_ast.FuncCall(c_ast.ID('sassert'), c_ast.ExprList([c_ast.BinaryOp('==', c_ast.UnaryOp('&', c_ast.ID(input_name)), cnx_input)])))

            body.append(c_ast.FuncCall(c_ast.ID('assert_cp__%s' % input_type[0]), 
                c_ast.ExprList([
                    cnx_input,
                    c_ast.UnaryOp('&', c_ast.ID('%s0'%input_name)),
                    c_ast.ID(flag)
                ])))
        else:
            body.append(c_ast.FuncCall(c_ast.ID('sassert'), c_ast.ExprList([c_ast.BinaryOp('==', c_ast.ID(input_name), right)])))
        idx += 1



    # Add : assert_cp__picoquic_cnx_t(&cnx, &cnx0, ASSERT_NONE);
    flag = 'ASSERT_NONE' if 'cnx' not in protoop_specs['effects'] else ' | '.join([str.upper('assert_%s__%s' % ('picoquic_cnx_t', field)) for field in  protoop_specs['effects']['cnx']])
    body.append(c_ast.FuncCall(c_ast.ID('assert_cp__picoquic_cnx_t'), c_ast.ExprList([c_ast.ID('&cnx'), c_ast.ID('&cnx0'), c_ast.ID(flag)])))

    # Add : return 0;
    body.append(c_ast.Return(c_ast.Constant('int', '0')))
    
    protoop_params = [c_ast.Decl('cnx', [], [], [], c_ast.PtrDecl([], c_ast.TypeDecl('cnx', [], c_ast.IdentifierType(['picoquic_cnx_t']))), None, None)] 
    protoop_decl = c_ast.FuncDecl(c_ast.ParamList(protoop_params), c_ast.TypeDecl(protoop_specs['name'], [], c_ast.IdentifierType(['protoop_arg_t'])))
    protoop_signature = c_ast.Decl(protoop_specs['name'], [], [], [], protoop_decl, None, None)
    fun_ast.ext.append(protoop_signature)

    main_decl = c_ast.FuncDecl(c_ast.ParamList([]), c_ast.TypeDecl('main', [], c_ast.IdentifierType(['int'])))
    main_signature = c_ast.Decl('main', [], [], [], main_decl, None, None)
    fun_ast.ext.append(c_ast.FuncDef(main_signature, [], c_ast.Compound(body)))

    return fun_ast


if __name__ == '__main__':
    if len(argv) != 2:
        usage()
        exit(1)

    # TODO : check that argv1 is a reachable file
    fn = argv[1]

    with open(fn, 'r') as fp:
        protoop_specs = load(fp)

    main_ast = generate_main()
    generator = c_generator.CGenerator()

    with open('checks/specs_check__%s.c' % protoop_specs['name'], 'w') as output:
        output.write('#include "../verifier/verifier.h"\n\n')
        output.write(generator.visit(main_ast))

