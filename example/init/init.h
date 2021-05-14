#include <stdint.h>
#include <stdlib.h>

#include "seahorn/seahorn.h"

extern uint8_t sh_uint8();

typedef struct {
	uint8_t b : 1;
	uint8_t c : 2;
	uint8_t a;
} my_struct;

typedef struct {
	uint8_t a;
	my_struct b;
#ifdef PTR
	my_struct *c;
#endif
} my_struct2;

extern my_struct sh_my_struct();
extern my_struct2 sh_my_struct2();

inline void dup(my_struct *src, my_struct *dst) {
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}

inline void dup2(my_struct2 *src, my_struct2 *dst) {
	dst->a = src->a;
	dup(&src->b, &dst->b);
#ifdef PTR
	dst->c = (my_struct*) malloc(sizeof(my_struct));
	dup(src->c, dst->c);
#endif
}

inline void cmp(my_struct *src, my_struct *dst) {
	unsigned int cond = 1;
	cond &= dst->a == src->a;
	cond &= dst->b == src->b;
	cond &= dst->c == src->c;
	sassert(cond);
}

inline void cmp2(my_struct2 *src, my_struct2 *dst) {
	unsigned int cond = 1;
	cond &= dst->a == src->a;
	cmp(&dst->b, &src->b);
#ifdef PTR
	cmp(dst->c, src->c);
#endif
	sassert(cond);
}
