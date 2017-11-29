#include "polynomial.h"

  static
int test (int argc, char *argv[])
{

  Poly    poly,
          poly2;

  Size    degreeOfPolynomial = 5;

  array_t coefficientsOfPolynomial = new_array(degreeOfPolynomial + 1);

  coefficientsOfPolynomial[0] = 1;
  coefficientsOfPolynomial[1] = 1;
  coefficientsOfPolynomial[2] = 0;
  coefficientsOfPolynomial[3] = 0;
  coefficientsOfPolynomial[4] = 0;
  coefficientsOfPolynomial[5] = 1;

  poly = polynomial(degreeOfPolynomial, coefficientsOfPolynomial);

  print_poly(&poly);
  printf("P("data_no_fmt") = "data_fmt"\n",
      2.0,
      polynomial_evaluate(2.0, &poly));

  array_reverse(coefficientsOfPolynomial, degreeOfPolynomial+1);
  poly2 = polynomial(degreeOfPolynomial, coefficientsOfPolynomial);
  printf("P("data_no_fmt") = "data_fmt"\n",
      2.0,
      horner_evaluate(2.0, &poly2) );

  array_destroy(coefficientsOfPolynomial);
  list_destroy(&poly);
  list_destroy(&poly2);

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
