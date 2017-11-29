#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  puts("A:");
  Matrix A = createMatrix(7, 7);
  randMatrix   (A);
  printMatrix  (A);

  printf("DET(A): "data_fmt"\n",Det(A));
  printf("DET(A): "data_fmt"\n",determinantMatrix(A));

  destroyMatrix(A);

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
