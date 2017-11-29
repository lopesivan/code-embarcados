#include "array.h"

  static
int test (int argc, char *argv[])
{

  Array A = createArray(4);

  randArray(A);
  printArray(A);
  printf("product = "data_fmt"\n", productArray(A));

  destroyArray(A);

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
