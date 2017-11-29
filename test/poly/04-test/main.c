#include "polynomial.h"

  static
int test (int argc, char *argv[])
{

  Size         degreeOfPolynomial = 5;

  array_t      coefficientsOfPolynomial = new_array(degreeOfPolynomial + 1);

  Scalar       x =  5.0;

  unsigned int i;

  printf("P("data_no_fmt") = "data_fmt"\n",
      2.0,
      pval(2.0, 1, "4 -2"));

  printf("P("data_no_fmt") = "data_fmt"\n",
      x,
      pval(x, 2, "1 -6 9"));


  for (i = 0; i < 5; ++i)
  {
    x = (Scalar)i;
    printf("P("data_no_fmt") = "data_fmt"\n",
        x,
        pval(x, 2, "1 -6 9"));
  }

  array_t array = new_array(25);
  for (i = 0; i < 25; ++i)
  {
    x = (Scalar)i;
    array[i] = pval(x, 2, "1 -6 9");
  }

  print_array(array, 25);
  printf("soma dos termos: "data_fmt"\n", sum(array, 25));
  printf("produto dos termos: "data_fmt"\n", product(array, 25));


  array_destroy(array);

  array_destroy(coefficientsOfPolynomial);

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
