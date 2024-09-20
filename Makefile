CC=gcc
AR=ar

OUTDIR=.

SRC=$(shell find . -name "*.c")
OBJ=$(SRC:%=%.o)

OPTIONS=

FLAGS=-g -Wall $(OPTIONS)
CFLAGS=$(FLAGS)

LIB=$(OUTPUT)/libcbase.a

.PHONY: lib clean

lib: $(LIB)

clean:
	rm -f $(OBJ) $(LIB)

$(LIB): $(OBJ)
	$(AR) r $@ $^

%.c.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
