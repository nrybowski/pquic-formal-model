#include "seahorn/seahorn.h"
#include <stdlib.h>

extern unsigned int nd();
extern char nd2();

typedef struct st_my_struct {
        unsigned int length;
        char *buf;
} my_struct;

inline void init(my_struct * s) {
        s->length = nd();
        s->buf = malloc(sizeof(char) * s->length);
        assume(s->buf != NULL);
        for (int i=0; i<s->length; i++)
                *(s->buf+i) = nd2();
}

inline void clean(my_struct * s) {
        free(s->buf);
}

inline void duplicate(my_struct *src, my_struct *dst) {
        dst->length = src->length;
        dst->buf = malloc(sizeof(char) * dst->length);
        assume(dst->buf != NULL);
        for (int i=0; i<src->length; i++)
                *(dst->buf+i) = *(src->buf+i);
}

inline void check(my_struct *src, my_struct *dst) {
        sassert(dst->length == src->length);
        for (int i=0; i<src->length; i++)
                sassert(*(dst->buf+i) == *(src->buf+i));
}

int main() {
        my_struct s, s0;

        init(&s);
        duplicate(&s, &s0);
        check(&s, &s0); // should unsat

        // choose a position in the buffer to change
        unsigned int b = nd();
        assume(b<s.length);

        // choose a byte different from the one currently at the position
        char x = nd2();
        assume(x != *(s.buf+b));

        // set byte
        *(s.buf+b) = x;

        check(&s, &s0); // should sat

        clean(&s);
        clean(&s0);

        return 0;
}
