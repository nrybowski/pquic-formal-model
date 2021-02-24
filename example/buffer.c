#include "seahorn/seahorn.h"
#include <string.h>
#include <stdlib.h>

extern int nd();
extern char nd2();

int main() {
        unsigned int s = nd();
        size_t size = sizeof(int) * s;
        char *buf, *buf0;
        buf = (char*) malloc(size);
        buf0 = (char*) malloc(size);
        assume(buf != NULL);
        assume(buf0 != NULL);

        // init
        for (int i=0; i<s; i++)
                *(buf+i) = nd2();

        // duplicate
        //buf0 = memcpy(buf0, buf, size); // do not work
        for (int i=0; i<s; i++)
                *(buf0+i) = *(buf+i);

        // comparaison with witeness buffer, should unsat
        for (int i=0; i<s; i++)
                sassert(*(buf+i) == *(buf0+i));

        // choose a position in the buffer to change
        unsigned int b = nd();
        assume(b<s);

        // choose a byte different from the one currently at the position
        char x = nd2();
        assume(x != *(buf+b));

        // set byte
        *(buf+b) = x;

        // comparaison with witeness buffer, should sat
        for (int i=0; i<s; i++)
                sassert(*(buf+i) == *(buf0+i));

        free(buf);
        free(buf0);

        return 0;
}
