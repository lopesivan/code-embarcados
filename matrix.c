#include "matrix.h"

struct Matrix_t {
    unsigned long rows;
    unsigned long columns;
    matrix_t      data;
};

/*****************************************************************************
 *                                                                           *
 * ------------------------------ createMatrix ----------------------------- *
 *                                                                           *
 *****************************************************************************/

Matrix createMatrix(Row rows, Column columns)
{
    Matrix matrix = malloc(sizeof *matrix);

    if is_null(matrix) {
        printf("%s:In function `%s':\n" "%s:%d: %s\n", \
           __FILE__, __FUNCTION__, __FILE__, __LINE__, \
           "could not allocate the Matrix pointer"
        );

        exit(EXIT_FAILURE);
    }

    matrix->rows    = rows;
    matrix->columns = columns;
    matrix->data    = new_array_2d(rows, columns);

    if is_null(matrix->data)
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "could not allocate Matrix data"
        );

        exit(EXIT_FAILURE);
    }

    return matrix;

}

Matrix createMatrixWithDataNull(Row rows, Column columns)
{
    Matrix matrix = malloc(sizeof *matrix);

    if is_null(matrix) {
        printf("%s:In function `%s':\n" "%s:%d: %s\n", \
           __FILE__, __FUNCTION__, __FILE__, __LINE__, \
           "could not allocate the Matrix pointer"
        );

        exit(EXIT_FAILURE);
    }

    matrix->rows    = rows;
    matrix->columns = columns;
    matrix->data    = NULL;

    return matrix;

}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- mulMatrix ---------------------------- *
 *                                                                           *
 *****************************************************************************/

Matrix mulMatrix(Matrix A,
                 Matrix B)
{

    Matrix C = createMatrix(A->rows, B->columns);

    matrix_mul ( A->data, A->rows, A->columns,
                 B->data, B->rows, B->columns,
                 C->data, C->rows, C->columns);

    return C;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ printMatrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void printMatrix(Matrix matrix) {

    print_matrix(matrix->data,
                 matrix->rows,
                 matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- destroyMatrix ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void destroyMatrix (Matrix matrix)
{
    free(matrix->data);
    free(matrix);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- zeroMatrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void zeroMatrix ( Matrix matrix )
{
    matrix_zero (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- oneMatrix ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void oneMatrix ( Matrix matrix )
{
    matrix_one (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- twoMatrix ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void twoMatrix ( Matrix matrix )
{
    matrix_two (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- threeMatri ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void threeMatrix ( Matrix matrix )
{
    matrix_three (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- randMatrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void randMatrix ( Matrix matrix )
{
    matrix_grand (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * -------------------------------- toArray -------------------------------- *
 *                                                                           *
 *****************************************************************************/

Array toArray ( Matrix matrix )
{
    Array array = createArrayWithDataNull(matrix->rows*matrix->columns);

    toarray(array, matrix->data[0]);

    return array;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- getDataMatrix ----------------------------- *
 *                                                                           *
 *****************************************************************************/

matrix_t getDataMatrix  ( Matrix matrix )

{
    return matrix->data;
}

/*****************************************************************************
 *                                                                           *
 * -------------------------------- getRows -------------------------------- *
 *                                                                           *
 *****************************************************************************/

Size   getRows     ( Matrix matrix )

{
    return matrix->rows;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- getColumns ------------------------------ *
 *                                                                           *
 *****************************************************************************/

Size   getColumns  ( Matrix matrix )

{
    return matrix->columns;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- timesTwoMatri ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void timesTwoMatrix ( Matrix matrix )
{
    matrix_times_two (matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ powerNMatri ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void powerNMatrix ( unsigned int n, Matrix matrix )
{
    matrix_inner_power_n (n, matrix->data, matrix->rows, matrix->columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- MatDot -------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar  dotMatrix  ( Matrix A, Matrix B )
{
    if ( (A->rows != B->rows) || (A->columns != B->columns) )
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "nonconformant arguments"
        );

        exit(EXIT_FAILURE);
    }

    Array a = NULL;
    Array b = NULL;

    a = toArray(A);
    b = toArray(B);

    Scalar ans = Dot(a, b);

    free(a);
    free(b);

    return ans;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- MatAdd -------------------------------- *
 *                                                                           *
 *****************************************************************************/

Matrix addMatrix ( Matrix A, Matrix B )
{
    if ( (A->rows != B->rows) || (A->columns != B->columns) )
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "nonconformant arguments"
        );

        exit(EXIT_FAILURE);
    }

    Matrix C = createMatrix(A->rows, A->columns);

    matrix_add ( A->data,/*Row rows, Column columns,*/
                 B->data,/*Row rows, Column columns,*/
                 C->data, A->rows, A->columns);

    return C;
}

Matrix subMatrix ( Matrix A, Matrix B )
{
    if ( (A->rows != B->rows) || (A->columns != B->columns) )
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "nonconformant arguments"
        );

        exit(EXIT_FAILURE);
    }

    Matrix C = createMatrix(A->rows, A->columns);

    matrix_sub ( A->data,/*Row rows, Column columns,*/
                 B->data,/*Row rows, Column columns,*/
                 C->data, A->rows, A->columns);

    return C;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- copyMatrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void copyMatrix  ( Matrix orig, Matrix dest )
{
    copy_matrix(dest->data, orig->data, (orig->rows * orig->columns));

    return;
}

Matrix cloneMatrix  ( Matrix orig )
{
    Matrix matrix = createMatrixWithDataNull(orig->rows, orig->columns);

    matrix->data = kernel__clone_matrix(orig->data, orig->rows, orig->columns);

    return matrix;
}

void destroyClonedMatrix  ( Matrix matrix )
{
  free(getDataMatrix(matrix)[0]);
  destroyMatrix(matrix);

  return;
}

Matrix createMatrixWithArray(Array array, Row rows, Column columns)
{
    Matrix matrix = createMatrixWithDataNull(rows, columns);
    matrix->data = new_matrix_array2matrix(getData(array), rows*columns, rows, columns);

    return matrix;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- transposeMatrix---------------------------- *
 *                                                                           *
 *****************************************************************************/

void transposeMatrix ( Matrix matrix )
{

    trans (matrix->data, matrix->rows, matrix->columns);

    return;
}
/*****************************************************************************
 *                                                                           *
 * ------------------------------- mapMatrix ------------------------------- *
 *                                                                           *
 *****************************************************************************/
void mapMatrix (Matrix matrix, Scalar (*f)(Scalar))
{
    unsigned int i;

    for (i = 0; i < (matrix->rows * matrix->columns); i++)
    {
        *(&matrix->data[0][0] + i) = f( *(&matrix->data[0][0] + i) );
    }

    return;
}

void prodMatrix (Scalar scalar, Matrix matrix)
{
    unsigned int i;

    for (i = 0; i < (matrix->rows * matrix->columns); i++)
    {
        *(&matrix->data[0][0] + i) = scalar * (*(&matrix->data[0][0] + i));
    }

    return;
}
/*
******************************************************************************

  exemplo de uso:
  ==============

 ## LINEARIZE UMA MATRIZ

Seja f uma funcão:

for (i = 0; i < (A->rows * A->columns); i++)
{
    f( *(&A->data[0][0] + i) );
}

******************************************************************************
*/

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- Det ---------------------------------- *
 *                                                                           *
 *****************************************************************************/
Scalar Det ( Matrix A )
{
    if (A->rows != A->columns)
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "nonconformant arguments"
        );

        exit(EXIT_FAILURE);
    }

    return Determinant(A->data, A->rows);
}

Matrix Inv ( Matrix A )
{
    int    i;

    Scalar det = Det(A);

    Matrix B = createMatrix(A->rows, A->columns);

    CoFactor  (A->data, A->rows, B->data);
    Transpose (B->data, B->rows);

    for (i = 0; i < (B->rows * B->columns); i++)
    {
        *(&A->data[0][0] + i) = ( *(&A->data[0][0] + i) )/det;
    }

    return B;
}

Array Cross(Array a,
            Array b)
{
  array_t array_data_a = getData(a);
  array_t array_data_b = getData(b);

  Matrix A = createMatrix(3,3);
  Matrix B = createMatrix(3,1);

  matrix_t data_A = getDataMatrix (A);

  data_A[0][1] =  - array_data_a[2];
  data_A[0][2] =    array_data_a[1];
  data_A[1][0] =    array_data_a[2];

  data_A[1][2] =  - array_data_a[0];
  data_A[2][0] =  - array_data_a[1];
  data_A[2][1] =    array_data_a[0];

  matrix_t data_B = getDataMatrix (B);

  data_B[0][0] =  array_data_b[0];
  data_B[1][0] =  array_data_b[1];
  data_B[2][0] =  array_data_b[2];

  printMatrix (A);
  printMatrix (B);

  Matrix C = mulMatrix(A, B);
  Array  c = createArray(C->rows * C->columns);
  array_t array_data_c = getData(c);

  unsigned int i;
  for (i = 0; i < (C->rows * C->columns); i++)
  {
      array_data_c[i] =  *(&C->data[0][0] + i);
  }

  destroyMatrix(A);
  destroyMatrix(B);
  destroyMatrix(C);

  return c;
}


