#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Array array_a = createArray(3);
  Array array_b = createArray(3);

  array_t array_data_a = getData(array_a);
  array_t array_data_b = getData(array_b);

  array_data_a[0] =  4;
  array_data_a[1] = -2;
  array_data_a[2] =  1;

  array_data_b[0] =  1;
  array_data_b[1] = -1;
  array_data_b[2] =  3;

  Matrix A = createMatrix(3,3);
  Matrix B = createMatrix(3,1);

  matrix_t a = getDataMatrix  (A);

  a[0][1] =  - array_data_a[2];
  a[0][2] =    array_data_a[1];
  a[1][0] =    array_data_a[2];

  matrix_t b = getDataMatrix  (B);

  b[0][0] =  array_data_b[0];
  b[1][0] =  array_data_b[1];
  b[2][0] =  array_data_b[2];

  printMatrix (A);

  puts("");
  printMatrix (B);

  Matrix C = mulMatrix(A, B);
  puts("");
  printMatrix (C);

  destroyMatrix(A);
  destroyMatrix(B);
  destroyMatrix(C);

  destroyArray(array_a);
  destroyArray(array_b);

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
