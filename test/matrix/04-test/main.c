#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Matrix matrix = createMatrix(3, 4);
  Array array   = NULL;

  randMatrix  ( matrix );

  puts("matrix:");
  printMatrix(matrix);

  puts("array:");
  array = toArray(matrix);
  printArray(array);

  free(array);

  destroyMatrix(matrix);

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
