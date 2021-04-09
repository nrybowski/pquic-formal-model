SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

CFLAGS=-I../../picoquic -DDISABLE_PROTOOP_PRINTF -DACK_DELAY_MULT=$(ACK_DELAY_MULT) -DACK_DELAY_DIV=$(ACK_DELAY_DIV) -DACK_THRESHOLD=$(ACK_THRESHOLD) -fno-stack-protector

CLANG?=clang-6.0
LLC?=llc-6.0

all: $(SRC) $(OBJ)

$(OBJ): %.o

%.o: %.c
	$(CLANG) $(CFLAGS) -O2 -fno-gnu-inline-asm -emit-llvm -c $< -o - | $(LLC) -march=bpf -filetype=obj -o $@

clean:
	rm -rf *.o

.PHONY: %.o
