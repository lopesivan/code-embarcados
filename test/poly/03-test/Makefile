# Makefile: A standard Makefile for main.c
UP_DIR = ../../..
CFLAGS = -g -ansi -Wall -DDOUBLE_PRECISION -DBOOLTYPE -I$(UP_DIR) -I$(UP_DIR)/kernel
LIBS   = -lm

SRCS    = main.c \
	$(UP_DIR)/array.c       \
	$(UP_DIR)/matrix.c      \
	$(UP_DIR)/kernel/list.c \
	$(UP_DIR)/kernel/polynomial.c \
	$(UP_DIR)/kernel/narray.c     \
	$(UP_DIR)/kernel/karray.c     \
	$(UP_DIR)/kernel/kmatrix.c

EXT     = o
OBJECTS = $(foreach s,$(SRCS), $(addprefix $(s:.c=.), $(EXT)))

all   : main
main  : $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

run   : main
	./main

test: main
	./main
	valgrind --leak-check=full -v  ./main

clean :
	/bin/rm -rf $(OBJECTS)
	/bin/rm -rf main

# END OF FILE
