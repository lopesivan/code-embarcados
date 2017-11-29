CC = gcc
LD = $(CC)

CFLAGS   = -c -Wall -Werror -ansi
LDFLAGS  = -o
GDBFLAGS = -g

target  := \
factorial \
example1 \
example2 \
example3 \
example4 \
example5 \
example6 \
example7 \
example8

targets := $(target)

# Compile
.c.o:
	$(CC) $(GDBFLAGS) $(CFLAGS) $<

all: $(targets)

factorial: factorial.o decNumber.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example1: example1.o decNumber.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example2: example2.o decNumber.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example3: example3.o decNumber.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example4: example4.o decNumber.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example5: example5.o decNumber.o decContext.o decimal64.o
	$(CC) $(LDFLAGS) $@ $^
example6: example6.o decNumber.o decContext.o decPacked.c
	$(CC) $(LDFLAGS) $@ $^
example7: example7.o decQuad.o decContext.o
	$(CC) $(LDFLAGS) $@ $^
example8: example8.o decNumber.o decContext.o  decQuad.o decimal128.o decimal64.o
	$(CC) $(LDFLAGS) $@ $^

clean:
	/bin/rm -rf $(targets) *.o
# END OF FILE
