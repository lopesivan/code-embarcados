#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix A = createMatrix(6, 6);

  puts("A:");
  randMatrix   (A);
  printMatrix  (A);

  puts("A:");
  transposeMatrix  (A);
  printMatrix  (A);


  puts("B:");
  Matrix B = cloneMatrix(A);
  destroyMatrix(A);
  printMatrix  (B);

  destroyCloned(B);

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
