#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix A = createMatrix(2, 3);
  Matrix B = createMatrix(2, 4);


  puts("A:");
  randMatrix   (A);
  printMatrix  (A);

  puts("A+A:");
  timesTwoMatrix (A);
  printMatrix    (A);

  destroyMatrix(A);

  puts("B:");
  twoMatrix  (B);
  printMatrix (B);

  puts("B^3:");
  powerNMatrix (3, B);
  printMatrix  (B);

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
