#include "seahorn/seahorn.h"

typedef void (*callback1)(void *ctx);
typedef void (*callback2)(void *ctx);

typedef struct st_my_struct {
        callback1 cb1;
        callback2 cb2;
} my_struct;

extern void useless1 (void* ctx);
extern void useless2 (void* ctx);
extern void useless3 (void* ctx);

inline void init(my_struct *s) {
        s->cb1 = useless1;
        s->cb2 = useless2;
}

inline void duplicate(my_struct *src, my_struct *dst) {
        dst->cb1 = src->cb1;
        dst->cb2 = src->cb2;
}

inline void check(my_struct *src, my_struct *dst) {
        sassert(dst->cb1 == src->cb1);
        sassert(dst->cb2 == src->cb2);
}

int main() {
        my_struct s, s0;

        init(&s);
        duplicate(&s, &s0);
        
        // compare with witness structure
        check(&s, &s0); // should unsat

        // change function reference
        s.cb2 = useless3;

        // compare with witness structure
        check(&s, &s0); // should sat

        return 0;
}
