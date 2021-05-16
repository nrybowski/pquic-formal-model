#include "seahorn/seahorn.h"

int test(void) {
	int i;
	for (i=0; i<20; i++) {}
	return i;
}

int main(void) {
	int i = test();
	sassert(i == 20);
        while(1) {}
        sassert(0);
	return 0;
}
