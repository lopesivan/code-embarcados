#include "complex.h"

  static
int test (int argc, char *argv[])
{
  Complex A = NULL;
  Complex B = NULL;
  Complex C = NULL;

  A = createComplex (2, 3);
  B = createComplex (12, 4);

  printf("mag    = "data_fmt"\n", magComplex(A));
  printf("angulo = "data_fmt"\n", argComplex(A));

  puts("A:");
  printMatrix(A);
  puts("");
  printComplex(A);

  puts("B:");
  printMatrix(B);
  puts("");
  printComplex(B);

  C = divComplex(A,B);
  puts("C:");
  printMatrix(C);
  puts("");
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
