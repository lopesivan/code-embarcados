#include "complex.h"

  static
int test (int argc, char *argv[])
{

  if (argc != 3)
    return EXIT_FAILURE;

  Complex Vx  = NULL;
  Complex Vx1 = NULL;
  Complex Vx2 = NULL;
  Complex ans = NULL;

  Complex cis = NULL;

  Vx = createComplex__mag_angle(atos(argv[1]), atos(argv[2]));

  cis = cisn(120);
  Vx1 = mulComplex(Vx, cis);
  destroyComplex(cis);

  cis = cisp(120);
  Vx2 = mulComplex(Vx, cis);
  destroyComplex(cis);

  printComplex (Vx);
  printComplex (Vx1);
  printComplex (Vx2);

  puts("");

  /* horário */
  ans = subComplex(Vx1, Vx);
  printComplex   (ans);
  destroyComplex (ans);

  ans = subComplex(Vx2, Vx1);
  printComplex   (ans);
  destroyComplex (ans);

  ans = subComplex(Vx, Vx2);
  printComplex   (ans);
  destroyComplex (ans);

  puts("");

  /* trigonometrico */
  ans = subComplex(Vx2, Vx);
  printComplex   (ans);
  destroyComplex (ans);

  ans = subComplex(Vx1, Vx2);
  printComplex   (ans);
  destroyComplex (ans);

  ans = subComplex(Vx, Vx1);
  printComplex   (ans);
  destroyComplex (ans);

  destroyComplex (Vx);
  destroyComplex (Vx1);
  destroyComplex (Vx2);

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
