#include "init.h"

// sea bpf -m64 -g --bmc=mono --inline --track=mem --dsa=sea-cs --cex=harness.ll --log=cex --bv-cex --horn-bv-part-mem --enable-nondet-init --internalize /mount/init.c -DTEST"${TEST}" && sea exe -DTEST"${TEST}" -g -m64 --alloc-mem --enable-nondet-init --internalize /mount/init.c witness.ll -o out && ./out

void test1(my_struct2 *s) {
        s->a = 0;
}

void test2(my_struct2 *s) {
        s->a = 10;
}

void test3(my_struct2 *s) {
        s->b.a = 0;
}

void test4(my_struct2 *s) {
        s->b.a = 10;
}

void test5(my_struct2 *s) {
        s->b.b = 0;
}

void test6(my_struct2 *s) {
        s->b.b = 1;
}

void test7(my_struct2 *s) {
#ifdef PTR
        s->c->b = 0;
#endif
}

void test8(my_struct2 *s) {
#ifdef PTR
        s->c->b = 1;
#endif
}

void test9(my_struct2 *s) {
#ifdef PTR
        s->c->a = 0;
#endif
}

void test10(my_struct2 *s) {
#ifdef PTR
        s->c->a = 10;
#endif
}

int main(void) {
        my_struct2 s = sh_my_struct2(), s0;
        s.a = sh_uint8();
        s.b.a = sh_uint8();
        s.b.b = sh_uint8();
        s.b.c = sh_uint8();
#ifdef PTR_INIT
        my_struct i = sh_my_struct();
        i.a = sh_uint8();
        i.b = sh_uint8();
        i.c = sh_uint8();
        s.c = &i;
#endif
        dup2(&s, &s0);

#ifdef TEST1
        test1(&s);
#elif TEST2
        test2(&s);
#elif TEST3
        test3(&s);
#elif TEST4
        test4(&s);
#elif TEST5
        test5(&s);
#elif TEST6
        test6(&s);
#elif TEST7
        test7(&s);
#elif TEST8
        test8(&s);
#elif TEST9
        test9(&s);
#elif TEST10
        test10(&s);
#endif

        cmp2(&s, &s0);
#ifdef FAIL
        sassert(0);
#endif
#ifdef PTR
        free(s0.c);
#endif
        return 0;
}
