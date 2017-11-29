#include "complex.h"

  static
int test (int argc, char *argv[])
{

  Complex A = createComplex(2,4);

  printMatrix(A);
  destroyComplex(A);

  Complex B = createComplex__mag_angle(127, 180);

  printComplex(B);
  destroyComplex(B);
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
