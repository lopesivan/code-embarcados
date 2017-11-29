cmake_minimum_required(VERSION 3.2.2)
project(uff)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ansi -Werror")

# Bring the headers into the project
#include_directories(/workspace/docker-hpgcc/libs/hpstack/common)

set(HEADERS list.h narray.h array.h complex.h matrix.h datatype.h except.h real.h util.h)
set(SOURCES main.c list.c)
add_executable(main ${SOURCES} ${HEADERS})
