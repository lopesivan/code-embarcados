#ifndef KMATRIX_H
#define KMATRIX_H

#include "karray.h"

typedef Scalar**      matrix_t;

void matrix_zero      (matrix_t matrix, Row rows, Column columns);

void matrix_one       (matrix_t matrix, Row rows, Column columns);

void matrix_two       (matrix_t matrix, Row rows, Column columns);

void matrix_three     (matrix_t matrix, Row rows, Column columns);

void matrix_grand     (matrix_t matrix, Row rows, Column columns);

array_t matrix_to_array (matrix_t matrix);

void matrix_test      (matrix_t matrix, Row rows, Column columns);

void matrix_times_two (matrix_t A, Row rows, Column columns);

void matrix_inner_power_n(unsigned int n,
                          matrix_t A,
                          Row rows, Column columns);

void matrix_add(matrix_t A,
                matrix_t B,
                matrix_t C,
                Row rows,
                Column columns);

void matrix_sub(matrix_t A,
                matrix_t B,
                matrix_t C,
                Row rows,
                Column columns);

void matrix_mul(matrix_t A, Row rows_A, Column columns_A,
                matrix_t B, Row rows_B, Column columns_B,
                matrix_t C, Row rows_C, Column columns_C);

Scalar matrix_sum(matrix_t matrix,
                  Row rows,
                  Column columns);

void scalar_mul (Scalar scalar, matrix_t matrix,
                                Row rows,
                                Column columns);

void scalar_div (Scalar scalar, matrix_t matrix,
                 Row rows,
                 Column columns);

void scalar_min (Scalar scalar, matrix_t matrix,
                 Row rows,
                 Column columns);

void scalar_add (Scalar scalar, matrix_t matrix,
                 Row rows,
                 Column columns);

void trans (matrix_t matrix, Row rows, Column columns);

void copy_matrix(matrix_t dest, matrix_t orig, Size size);

void print_matrix(matrix_t matrix,
                  Row rows,
                  Column columns);

matrix_t new_matrix(Row rows, Column columns);

void matrix_destroy(matrix_t matrix);

void matrix2array(array_t array,
                  matrix_t matrix,
                  Row rows,
                  Column columns);

void array2matrix(matrix_t matrix, Column columns, array_t array, Size size);

void initialize_w_static_matrix(matrix_t dest, Scalar *orig, Size size);

matrix_t kernel__clone_matrix(matrix_t matrix, Row rows, Column columns);

matrix_t new_matrix_array2matrix(array_t array,
                                 Size size,
                                 Row rows,
                                 Column columns);

array_t new_array_matrix2array(matrix_t matrix,
                               Row rows,
                               Column columns);

Scalar Determinant  (matrix_t matrix, unsigned int n);
void   CoFactor     (matrix_t a, unsigned int n, matrix_t b);
void   Transpose    (matrix_t matrix, unsigned int n);

#endif       /* KMATRIX_H */
