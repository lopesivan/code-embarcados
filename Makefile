# Makefile: A standard Makefile for main.c
CFLAGS = -g -ansi -Wall
# CFLAGS = -ansi -Wall -Werror

SRCS = $(shell ls *.c)
INCS = $(shell ls *.h)
EXT  = o
OUT  = $(foreach s,$(SRCS), $(addprefix $(s:.c=.), $(EXT)))

all   : tags main
main  : main.o list.o ulist.o
tags  : $(SRCS) $(INCS)
	ctags -R ./*

run   : main
	./main

mem   : main
	valgrind --leak-check=full -v  ./main

test-1: main
	gdb --batch --command=$@.gdb --args ./main

clean :
	/bin/rm -rf $(OUT)
	/bin/rm -rf main tags

# END OF FILE
