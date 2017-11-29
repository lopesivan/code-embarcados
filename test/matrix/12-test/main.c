#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Scalar a1, a2, a3;
  a1 =  4;
  a2 = -2;
  a3 =  1;

  Scalar b1, b2, b3;
  b1 =  1;
  b2 = -1;
  b3 =  3;

  Matrix A = createMatrix(3,3);
  Matrix B = createMatrix(3,1);

  matrix_t a = getDataMatrix  (A);

  a[0][1] = -a3;
  a[0][2] =  a2;
  a[1][0] =  a3;

  a[1][2] = -a1;
  a[2][0] = -a2;
  a[2][1] =  a1;

  matrix_t b = getDataMatrix  (B);

  b[0][0] =  b1;
  b[1][0] =  b2;
  b[2][0] =  b3;

  printMatrix (A);

  puts("");
  printMatrix (B);

  Matrix C = mulMatrix(A, B);
  puts("");
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
