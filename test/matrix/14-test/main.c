#include "matrix.h"

  static
int test (int argc, char *argv[])
{

  Array a = createArray(3);
  Array b = createArray(3);

  array_t array_data_a = getData(a);
  array_t array_data_b = getData(b);

  array_data_a[0] =  4;
  array_data_a[1] = -2;
  array_data_a[2] =  1;

  array_data_b[0] =  1;
  array_data_b[1] = -1;
  array_data_b[2] =  3;

  Array c  = Cross(a,b);

  printArray(c);

  destroyArray(a);
  destroyArray(b);
  destroyArray(c);

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
