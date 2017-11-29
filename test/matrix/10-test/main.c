#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  puts("a:");
  Array a = createArray(12);
  randArray(a);
  printArray  (a);

  /* MatrixPtr A = createMatrixWithArray(a, 3, 4); */
  Matrix A = cloneArray(a, 3, 4);

  puts("A:");
  printMatrix  (A);

  destroyCloned(A);
  destroyArray(a);

  return EXIT_SUCCESS;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int main(int argc, char *argv[])
{

  if (test(argc, argv) == EXIT_FAILURE)
    exit(EXIT_FAILURE);

  return EXIT_SUCCESS;

}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
