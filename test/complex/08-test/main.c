#include "complex.h"

  static
int test (int argc, char *argv[])
{
  Complex A = NULL;
  Complex B = NULL;

  A = createComplex (2, 3);
  B = conjComplex (A);

  printf("mag    = "data_fmt"\n", magComplex(A));
  printf("angulo = "data_fmt"\n", argComplex(A));

  puts("A:");
  printMatrix(A);
  puts("");
  printComplex(A);

  printf("mag    = "data_fmt"\n", magComplex(B));
  printf("angulo = "data_fmt"\n", argComplex(B));
  puts("B:");
  printMatrix(B);
  puts("");
  printComplex(B);

  printf("mag    = "data_fmt"\n", sqrt(Det(B)));
  destroyComplex(A);
  destroyComplex(B);

  Complex C    = NULL;
  Complex invC = NULL;
  Complex ans  = NULL;
  C = createComplex (6, 8);
  invC = Inv(C);
  ans = mulComplex(C, invC);
  puts("");
  printMatrix(ans);

  destroyComplex(C   );
  destroyComplex(invC);
  destroyComplex(ans );

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
