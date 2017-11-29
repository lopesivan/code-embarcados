#include "complex.h"

  static
int test (int argc, char *argv[])
{

  if (argc != 3)
    return EXIT_FAILURE;

  Complex A = createComplex__mag_angle(atos(argv[1]), atos(argv[2]));
  Complex cis = NULL;

  cis = cisp(120);
  Matrix B = mulComplex(A, cis);
  destroyComplex(cis);

  cis = cisn(120);
  Matrix C = mulComplex(A, cis);
  destroyComplex(cis);

  printMatrix(A);
  printMatrix(B);
  printMatrix(C);

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
