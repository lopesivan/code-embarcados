#include "polynomial.h"

  static
int test (int argc, char *argv[])
{

  Poly         poly;

  unsigned int degree = 2;

  array_t coefficientsOfPolynomial =
    new_polynomial_coefficients("1 -6 9");

  poly = polynomial(degree, coefficientsOfPolynomial);

  print_poly(&poly);

  printf("P("data_no_fmt") = "data_fmt"\n",
      5.0,
      polynomial_evaluate(5.0, &poly));

  printf("->P("data_no_fmt") = "data_fmt"\n",
      5.0,
      (5.0 * 5.0 - 6 * 5.0 + 9));

  array_destroy(coefficientsOfPolynomial);

  poly_destroy(&poly);

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
