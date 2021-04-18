#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// sea bpf --cpu=300 --mem=1000 -m64 -g --bmc=mono --inline --track=mem --dsa=sea-cs --bv-cex --horn-bv-part-mem -DTEST /mount/dbl_ptr.c (-DFAIL)

// gcc /mount/dbl_ptr.c -o main && valgrind ./main 

#ifdef TEST
#include "seahorn/seahorn.h"
extern uint8_t sh_uint8();
extern unsigned int sh_uint();
#endif

typedef struct {
        uint8_t a;
        uint8_t b : 1;
        uint8_t c : 3;
} my_struct;

void init(my_struct *ptr) {
#ifdef TEST
        ptr->a = sh_uint8();
        ptr->b = sh_uint8();
        ptr->c = sh_uint8();
#else
        ptr->a = 8;
        ptr->b = 1;
        ptr->c = 5;
#endif
}

void dup(my_struct *src, my_struct *dst) {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
}

unsigned int cmp(my_struct *src, my_struct *dst) {
        unsigned int cond = 1;
        cond &= dst->a == src->a;
        cond &= dst->b == src->b;
        cond &= dst->c == src->c;
        return cond;
}

int main(void) {
        unsigned int size;
#ifdef TEST
        size = sh_uint();
        assume(size > 10);
#else
        size = 10;
#endif

        my_struct **ptr = (my_struct**) malloc(sizeof(my_struct*)*size), **ptr0;

        for (int i=0; i<size; i++) {
                ptr[i] = (my_struct*) malloc(sizeof(my_struct));
                init(ptr[i]);
        }
        
        ptr0 = (my_struct**) malloc(sizeof(my_struct*)*size);

        for (int i=0; i<size; i++) {
                ptr0[i] = (my_struct*) malloc(sizeof(my_struct));
                dup(ptr[i], ptr0[i]);
        }
        
        unsigned int o;
#ifdef TEST
        sh_uint();
        assume(o < size);
#else
        o = 1;
#endif
        ptr[o]->a = 0;

        unsigned int cond;
        my_struct **tmp = ptr, **tmp0 = ptr0;
        for (int i=0; i<size; i++) {
                cond = cmp(*tmp, *tmp0);        // warning
                //cond = cmp(ptr[i], ptr0[i]);  // warning
#ifndef TEST
                printf("%i: %i\n", i, cond);
                printf("%p : %p\n", ptr[i], *tmp);
                printf("%p : %p\n", ptr0[i], *tmp0);

#else
                sassert(cond);
#endif
                tmp++;
                tmp0++;
        }

#ifdef TEST
#ifdef FAIL
        sassert(0);
#endif
#endif


        // clean
        for (int i=0; i<size; i++) {
                if(ptr0[i])
                        free(ptr0[i]);
                if(ptr[i])
                        free(ptr[i]);
        }
        if(ptr)
                free(ptr);
        if(ptr0)
                free(ptr0);
}
