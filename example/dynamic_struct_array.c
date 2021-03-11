#include <stdint.h>
#include <stdlib.h>

#ifdef CHECK
#include "seahorn/seahorn.h"
#define ASSERT(cond) sassert(cond);
#define ASSUME(cond) assume(cond);
extern uint8_t dummy__uint8_t();
extern unsigned int dummy__unsigned_int();
#else
#include <stdio.h>
#define ASSERT(cond) printf("CHECK : %i\n", cond);
#define ASSUME(cond)  
uint8_t dummy__uint8_t() {
        return 1;
}

unsigned int dummy__unsigned_int() {
        return 10;
}
#endif

typedef struct st_my_struct1_t {
        uint8_t a;
} my_struct1_t;

typedef struct st_my_struct2_t {
        unsigned int size;
        my_struct1_t **array;
} my_struct2_t;

void init1(my_struct1_t *s) {
        s->a = dummy__uint8_t();
}

inline void cp1(my_struct1_t *src, my_struct1_t *dst) {
        dst->a = src->a;
}

void check1(my_struct1_t *src, my_struct1_t *dst) {
        sassert(src != dst);
        ASSERT(dst->a == src->a);
}

void init2(my_struct2_t *s) {
        s->size = dummy__unsigned_int();
        s->array = (my_struct1_t **) malloc(s->size*sizeof(my_struct1_t*));
        assume(s->array != NULL);
        for (unsigned int i=0; i<s->size; i++) {
                s->array[i] = (my_struct1_t*) malloc(sizeof(my_struct1_t));
                assume(s->array[i] != NULL);
                init1(s->array[i]);
        }
}

void free2(my_struct2_t *s) {
        for (unsigned int i=0; i<s->size; i++)
                free(s->array[i]);
        free(s->array);
}

inline void cp2(my_struct2_t *src, my_struct2_t *dst) {
        dst->size = src->size;
        dst->array = (my_struct1_t **) malloc(dst->size*sizeof(my_struct1_t*));
        assume(dst->array != NULL);
        for (unsigned int i=0; i<dst->size; i++) {
                dst->array[i] = (my_struct1_t*) malloc(sizeof(my_struct1_t));
                assume(dst->array[i] != NULL);
                assume(dst->array[i] != src->array[i]);
                cp1(src->array[i], dst->array[i]);
        }
}

void check2(my_struct2_t *src, my_struct2_t *dst) {
        sassert(src->array != dst->array);
        ASSERT(dst->size == src->size);
        for (int i=0; i<dst->size; i++) {
                check1(src->array[i], dst->array[i]);
        }
}

int main(void) {
        my_struct2_t s, s0;
        init2(&s);
        cp2(&s, &s0);

        check2(&s, &s0); // should unsat

        // chose a random entry in the source array
        unsigned int i = dummy__unsigned_int();
        ASSUME(i < s.size);

        // change randomly the value of the entry
        uint8_t x = dummy__uint8_t();
        ASSUME(x != s.array[i]->a);
        s.array[i]->a = x;

        check2(&s, &s0); // should sat

        free2(&s);
        free2(&s0);

        return 0;
}
