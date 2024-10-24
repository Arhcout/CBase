include ../../Makefile.in
PREFIX=../../

override OUTDIR=$(shell,echo $$OUTDIR)

SRC=$(shell find . -name "*.c")
OBJ=$(SRC:%=%.o)

HDRS=$(shell find . -name "*.h")

OPTIONS=

FLAGS=-g -Wall $(OPTIONS)
CFLAGS=$(FLAGS)

LIB=$(PREFIX)ext/lib/libcbase.a

.PHONY: lib clean

lib: $(LIB)
	cp $(HDRS) $(PREFIX)ext/include

clean:
	rm -f $(OBJ) $(LIB)

$(LIB): $(OBJ)
	$(AR) r $@ $^

%.c.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@
