#include "complex.h"

  static
int test (int argc, char *argv[])
{

  Complex A = createComplex__mag_angle(127, 180);
  Complex cis = NULL;

  cis = cisp(120);
  Array B = mulComplex(A, cis);
  destroyComplex(cis);

  cis = cisn(120);
  Array C = mulComplex(A, cis);
  destroyComplex(cis);

  printArray(A);
  printArray(B);
  printArray(C);

  printComplex(A);
  printComplex(B);
  printComplex(C);

  destroyComplex(A);
  destroyComplex(B);
  destroyComplex(C);

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
