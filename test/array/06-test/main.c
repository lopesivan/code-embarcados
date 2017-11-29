#include "array.h"

  static
int test (int argc, char *argv[])
{

  Array A = createArray(2);
  Array B = createArray(2);
  Array C = NULL;

  puts("A:");
  randArray(A);
  printArray(A);

  sleep(2);

  puts("B:");
  randArray(B);
  printArray(B);

  C = Add(A, B);
  if ( !(is_null(C)) )
  {
    printf("%s:\n", "C = Add(A, B)");
    printArray(C);
    destroyArray(C);
  }

  C = Mul(A, B);
  if ( !(is_null(C)) )
  {
    printf("%s:\n", "C = Mul(A, B)");
    printArray(C);
    destroyArray(C);
  }

  Scalar  ans = Dot(A,B);
  printf("\nDot(A,B) = "data_fmt"\n", ans);

  puts("reverse A:");
  reverseArray(A);
  printArray(A);

  destroyArray(A);
  destroyArray(B);

  puts("D:");
  Array D = createArray(4);
  set_array_w_split_string(getData(D), "1 2.3 -3 4");
  printArray(D);
  destroyArray(D);

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
