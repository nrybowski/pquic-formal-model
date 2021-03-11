#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "seahorn/seahorn.h"

extern uint8_t dummy__uint8_t();
extern unsigned int dummy__unsigned_int();

typedef struct st_my_struct_t {
	uint8_t a;
} my_struct_t;

/*void init(my_struct_t *src, uint8_t val) {
	src->a = val;
}

void cp(my_struct_t *src, my_struct_t *dst) {
	dst->a = src->a;
}

void cmp(my_struct_t *src, my_struct_t *dst) {
	sassert(src->a == dst->a);
}*/

inline void init_list(my_struct_t **src, unsigned int size, uint8_t val) {
	src = (my_struct_t**) malloc(size*sizeof(my_struct_t*));
	my_struct_t *tmp;
	for (unsigned int i=0; i<size; i++) {
		tmp = (my_struct_t*) malloc(sizeof(my_struct_t));
		//init(tmp, val);
		tmp->a = val;
		src[i] = tmp;
	}
}

/*void cp_list(my_struct_t **src, my_struct_t **dst, uint8_t val, unsigned int size) {
	src = (my_struct_t**) malloc(size*sizeof(my_struct_t*));
	my_struct_t *tmp;
	for (unsigned int i=0; i<size; i++) {
		tmp = (my_struct_t*) malloc(sizeof(my_struct_t));
		init(tmp, val);
		src[i] = tmp;
	}
}*/

int main(void) {
	my_struct_t **s, **s0, *tmp;
	unsigned int size = dummy__unsigned_int(), i;
	uint8_t val = dummy__uint8_t();

	s = (my_struct_t**) malloc(size*sizeof(my_struct_t*));
	assume(s != NULL);
	for (unsigned int i=0; i<size; i++) {
		s[i] = (my_struct_t*) malloc(sizeof(my_struct_t));
		assume(s[i] != NULL);
		s[i]->a = val;
	}

	sassert(s != NULL);
	for (i=0; i<size; i++) {
		sassert(s[i] != NULL);
		sassert(s[i]->a == val);
	}

	s0 = (my_struct_t**) malloc(size*sizeof(my_struct_t*));
	assume(s0 != NULL);
	for (unsigned int i=0; i<size; i++) {
		s0[i] = (my_struct_t*) malloc(sizeof(my_struct_t));
		assume(s0[i] != NULL);
		s0[i]->a = s[i]->a;
	}

	sassert(s0 != NULL);
	for (i=0; i<size; i++)
		sassert(s0[i]->a == s[i]->a);

	i = dummy__unsigned_int();
	assume(i<size);
	uint8_t t2 = dummy__unint8_t();
	assume(t2 != val);
	s[i]->a = t2;

	sassert(s0 != NULL);
	for (i=0; i<size; i++)
		sassert(s0[i]->a == s[i]->a);

	for (i=0; i<size; i++) {
		free(s0[i]);
		free(s[i]);
	}

	free(s0);
	free(s);

	return 0;
}
