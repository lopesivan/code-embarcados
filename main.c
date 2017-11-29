#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

  static
int test1 (int argc, char *argv[])
{
  Array a = new_array(10);
  zero(a, 10);
  print_array(a, 10);

  free(a);

  return EXIT_SUCCESS;
}

  static
int test2 (int argc, char *argv[])
{
  Array a = new_array(10);
  one(a, 10);
  print_array(a, 10);

  free(a);

  return EXIT_SUCCESS;
}

  static
int test3 (int argc, char *argv[])
{
  Array a = new_array(10);
  two(a, 10);
  print_array(a, 10);

  free(a);

  return EXIT_SUCCESS;
}

  static
int test4 (int argc, char *argv[])
{
  Array a = new_array(10);
  three(a, 10);
  print_array(a, 10);

  free(a);

  return EXIT_SUCCESS;
}

  static
int test5 (int argc, char *argv[])
{
  Array a = new_array(10);
  grand(a, 10);
  print_array(a, 10);

  free(a);

  return EXIT_SUCCESS;
}

  static
int test6 (int argc, char *argv[])
{
  Array a = new_array(10);
  one(a, 10);
  print_array(a, 10);
  printf("Sum = "data_fmt"\n", sum(a,10));

  free(a);

  return EXIT_SUCCESS;
}

  static
int test7 (int argc, char *argv[])
{
  Array a = new_array(5);
  grand(a, 5);
  print_array(a, 5);
  printf("Sum = "data_fmt"\n", sum(a,5));

  free(a);

  return EXIT_SUCCESS;
}

Scalar times_two(Scalar s);
Scalar times_two(Scalar s)
{
  return 2*s;
}

  static
int test8 (int argc, char *argv[])
{
  Array a = new_array(10);
  grand(a, 10);
  print_array(a, 10);
  printf("Sum_seq = "data_fmt"\n", seq_sum(a, 0, 5, times_two));

  free(a);

  return EXIT_SUCCESS;
}

  static
int test9 (int argc, char *argv[])
{
  Array a = new_array(10);
  grand(a, 10);
  print_array(a, 10);
  printf("Sum_seq = "data_fmt"\n", seq_product(a, 0, 5, times_two));

  free(a);

  return EXIT_SUCCESS;
}

  static
int test10 (int argc, char *argv[])
{
  Array a = new_array(4);
  Array b = new_array(4);
  grand(a, 4);
  grand(b, 4);
  print_array(a, 4);
  print_array(b, 4);

  printf("dot = "data_fmt"\n", dot(a, b, 4));

  free(a);
  free(b);

  return EXIT_SUCCESS;
}

  static
int test11 (int argc, char *argv[])
{
  Array a = new_array(4);
  grand(a, 4);
  print_array(a, 4);

  printf("dot = "data_fmt"\n", product(a, 4));

  free(a);

  return EXIT_SUCCESS;
}

  static
int test12 (int argc, char *argv[])
{
  Array a = new_array(4);
  Array b = new_array(4);
  Array c = new_array(4);
  grand(a, 4);
  grand(b, 4);
  zero(c, 4);
  print_array(a, 4);
  print_array(b, 4);
  print_array(c, 4);

  array_add(a, b, c, 4);

  print_array(c, 4);

  free(a);
  free(b);
  free(c);

  return EXIT_SUCCESS;
}

  static
int test13 (int argc, char *argv[])
{
  Array a = new_array(4);
  Array b = new_array(4);
  Array c = new_array(4);
  grand(a, 4);
  grand(b, 4);
  zero(c, 4);
  print_array(a, 4);
  print_array(b, 4);
  print_array(c, 4);

  array_dot(a, b, c, 4);

  print_array(c, 4);

  free(a);
  free(b);
  free(c);

  return EXIT_SUCCESS;
}


  static
int test14 (int argc, char *argv[])
{
  Array a = new_array(4);
  grand(a, 4);
  print_array(a, 4);

  array_reverse(a, 4);

  print_array(a, 4);

  free(a);

  return EXIT_SUCCESS;
}


  static
int test15 (int argc, char *argv[])
{

  Array a = new_array_of_split("1 2 3 4 5 -7");
  print_array(a, 6);
  free(a);

  Array b = new_array(4);
  set_array_w_split_string(b, "22 23 24 25");
  print_array(b, 4);
  free(b);

  return EXIT_SUCCESS;
}

  static
int test16 (int argc, char *argv[])
{

  /* MatrixPtr A = createMatrix(3, 2); */
  Matrix data  = new_matrix(3, 2);
  matrix_one(data, 3, 2);

  free(data);
  /* A->data = data; */
  /* destroyMatrix(A); */

  return EXIT_SUCCESS;
}


  static
int testN (int argc, char *argv[])
{

  MatrixPtr A = createMatrix(3, 2);
  MatrixPtr B = createMatrix(2, 1);

  destroyMatrix(A);
  destroyMatrix(B);

  return EXIT_SUCCESS;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int main(int argc, char *argv[])
{
  printf("argc = <%d>\n", argc);
  if (argc != 2)
    exit(EXIT_FAILURE);

  printf("argv[1] = <%d>\n", atoi(argv[1]));

  switch(atoi(argv[1])) {

    case 1:
      if (test1(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 2:
      if (test2(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 3:
      if (test3(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 4:
      if (test4(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 5:
      if (test5(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 6:
      if (test6(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 7:
      if (test7(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 8:
      if (test8(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 9:
      if (test9(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 10:
      if (test10(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 11:
      if (test11(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 12:
      if (test12(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 13:
      if (test13(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 14:
      if (test14(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 15:
      if (test15(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 16:
      if (test16(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);
      break;

    case 200:
      if (testN(argc, argv) == EXIT_FAILURE)
        exit(1);
      break;

    default : /* Optional */
      printf("No input ...\n");
  }

  return EXIT_SUCCESS;

}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
