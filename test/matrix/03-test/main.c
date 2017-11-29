#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix A = createMatrix(3, 4);

  puts("A:");
  printMatrix(A);

  puts("A:");
  zeroMatrix  ( A );
  printMatrix ( A );

  puts("A:");
  oneMatrix   ( A );
  printMatrix ( A );

  puts("A:");
  twoMatrix   ( A );
  printMatrix ( A );

  puts("A:");
  threeMatrix ( A );
  printMatrix ( A );

  puts("A:");
  randMatrix  ( A );
  printMatrix ( A );

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
