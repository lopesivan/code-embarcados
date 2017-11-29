#include "polynomial.h"

  static
int test (int argc, char *argv[])
{

  Poly         poly;


  Size degreeOfPolynomial = 2;

  array_t coefficientsOfPolynomial = new_array(degreeOfPolynomial + 1);

  /*  -> x^2 + 3*x + 15  */
  coefficientsOfPolynomial[0] = 15;
  coefficientsOfPolynomial[1] = 3;
  coefficientsOfPolynomial[2] = 1;

  poly = polynomial(degreeOfPolynomial, coefficientsOfPolynomial);

  print_poly(&poly);

  array_destroy(coefficientsOfPolynomial);
  list_destroy(&poly);

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
