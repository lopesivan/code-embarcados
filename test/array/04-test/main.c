#include "array.h"

Scalar times_two(Scalar s);

Scalar times_two(Scalar s)
{
  return 2*s;
}

  static
int test (int argc, char *argv[])
{

  Array A = createArray(10);

  randArray(A);
  printArray(A);

  printf("Sum         = "data_fmt"\n", sumArray(A));
  printf("seq_sum     = "data_fmt"\n", seq_sumArray(A, times_two));
  printf("seq_product = "data_fmt"\n", seq_productArray(A, times_two));

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
