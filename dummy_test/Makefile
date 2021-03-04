SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS+=-I../../picoquic -fno-stack-protector

all: $(SRC) $(OBJ)

$(OBJ): %.o

%.o: %.c
	clang-11 $(CFLAGS) -g -O2 -fno-gnu-inline-asm -emit-llvm -c $< -o - | llc -march=bpf -filetype=obj -o $@

clean:
	rm -rf *.o

.PHONY: %.o
