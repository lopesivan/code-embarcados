#include "matrix.h"

Scalar foo (Scalar value);

Scalar foo (Scalar value)
{
  return 3*value;
}

  static
int test (int argc, char *argv[])
{

  puts("a:");
  Array a = createArray(4);
  randArray(a);
  printArray  (a);

  puts("3*a:");
  mapArray(a, foo);
  printArray  (a);

  destroyArray(a);


  puts("A:");
  Matrix A = createMatrix(2, 3);
  randMatrix   (A);
  printMatrix  (A);
  puts("3*A:");
  mapMatrix(A, foo);
  printMatrix  (A);
  destroyMatrix(A);

  puts("B:");
  Matrix B = createMatrix(3, 3);
  randMatrix   (B);
  printMatrix  (B);
  printf("DET(B): "data_fmt"\n",Det(B));
  destroyMatrix(B);

  puts("C:");
  Matrix C = createMatrix(4, 4);
  randMatrix   (C);
  printMatrix  (C);
  Matrix D = Inv(C);
  puts("D:");
  printMatrix  (D);

  puts("E:");
  Matrix E = MatMul(C, D);
  printMatrix  (E);

  destroyMatrix(C);
  destroyMatrix(D);
  destroyMatrix(E);

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
