#include "complex.h"

  static
int test (int argc, char *argv[])
{
  Complex A = NULL;

  A = createComplex(atos(argv[1]), atos(argv[2]));

  printf("angulo = "data_fmt"\n", argComplex(A));

  destroyComplex(A);

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
