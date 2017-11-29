# Makefile: A standard Makefile for main.c
CFLAGS = -ggdb3 -ansi -Wall
LIBS   =
#LIBS   = -lm

SRCS    = main.c\
		  parser.c

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
