#include "array.h"

  static
int test (int argc, char *argv[])
{

  Array A = createArray(4);

  oneArray(A);
  printArray(A);

  twoArray(A);
  printArray(A);

  threeArray(A);
  printArray(A);

  randArray(A);
  printArray(A);

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
