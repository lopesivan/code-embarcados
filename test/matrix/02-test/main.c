#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  puts("A:");
  Matrix A = createMatrix(2, 3);
  printMatrix(A);

  puts("B:");
  Matrix B = createMatrix(3, 2);
  printMatrix(B);

  puts("C:");
  Matrix C = NULL;
  C = mulMatrix(A, B);
  printMatrix(C);

  destroyMatrix(A);
  destroyMatrix(B);
  destroyMatrix(C);

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
