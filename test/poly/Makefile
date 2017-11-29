all: test-1 test-2 test-3 test-4

test-1:
	make -C 01-test
test-2:
	make -C 02-test
test-3:
	make -C 03-test
test-4:
	make -C 04-test

clean:
	make -C 01-test $@
	make -C 02-test $@
	make -C 03-test $@
	make -C 04-test $@

test:
	make -C 01-test $@
	make -C 02-test $@
	make -C 03-test $@
	make -C 04-test $@

run:
	make -C 01-test $@
	make -C 02-test $@
	make -C 03-test $@
	make -C 04-test $@
