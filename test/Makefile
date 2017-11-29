all: build

build:         build-array build-matrix build-poly build-complex

build-array:
	make -C array
build-matrix:
	make -C matrix
build-complex:
	make -C complex
build-poly:
	make -C poly
clean:
	make -C array $@
	make -C matrix $@
	make -C complex $@
	make -C poly $@
