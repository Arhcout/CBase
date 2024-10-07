CC=gcc
AR=ar

override OUTDIR=$(shell,echo $$OUTDIR)

SRC=$(shell find . -name "*.c")
OBJ=$(SRC:%=%.o)

OPTIONS=

FLAGS=-g -Wall $(OPTIONS)
CFLAGS=$(FLAGS)

LIB=../libcbase.a

.PHONY: lib clean

lib: $(LIB)

clean:
	rm -f $(OBJ) $(LIB)

$(LIB): $(OBJ)
	$(AR) r $@ $^

%.c.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
