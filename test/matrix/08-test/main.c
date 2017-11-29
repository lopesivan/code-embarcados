#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix A = createMatrix(3, 2);
  Matrix B = createMatrix(3, 2);

  puts("A:");
  randMatrix   (A);
  printMatrix  (A);

  puts("B:");
  printMatrix (B);

  copyMatrix(A, B);
  puts("B:");
  printMatrix (B);

  destroyMatrix(A);
  destroyMatrix(B);

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
