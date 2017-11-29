# Makefile: A standard Makefile for main.c
UP_DIR = ../../..
CFLAGS = -g -ansi -Wall -DDOUBLE_PRECISION -I$(UP_DIR)
LIBS   = -lm

SRCS    = main.c \
	$(UP_DIR)/complex.c     \
	$(UP_DIR)/array.c       \
	$(UP_DIR)/matrix.c      \
	$(UP_DIR)/pythagoras.c  \
	$(UP_DIR)/narray.c      \
	$(UP_DIR)/karray.c      \
	$(UP_DIR)/kmatrix.c

EXT     = o
OBJECTS = $(foreach s,$(SRCS), $(addprefix $(s:.c=.), $(EXT)))

all   : main
main  : $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

ARGS = 220 45

run   : main
	./main $(ARGS)

test: main
	valgrind --leak-check=full -v ./main $(ARGS)

clean :
	/bin/rm -rf $(OBJECTS)
	/bin/rm -rf main

# END OF FILE
