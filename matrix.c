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
 * ----------------------------- multiplyMatrix ---------------------------- *
 *                                                                           *
 *****************************************************************************/

Matrix multiplyMatrix(Matrix A,
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

Scalar  MatDot  ( Matrix A, Matrix B )
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

Matrix MatAdd  ( Matrix A, Matrix B )
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

