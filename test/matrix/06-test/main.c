#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix A = createMatrix(2, 3);
  Matrix B = createMatrix(2, 3);


  puts("A:");
  randMatrix   (A);
  printMatrix  (A);

  sleep(2);

  puts("B:");
  randMatrix  (B);
  printMatrix (B);

  printf("\nMatDot(A,B) = "data_fmt"\n", MatDot(A,B));

  puts("C:");
  Matrix C = MatAdd(A, B);
  printMatrix (C);

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
