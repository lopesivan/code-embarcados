#include "kmatrix.h"

/*****************************************************************************
 *                                                                           *
 * ------------------------------- matrix_sum ------------------------------ *
 *                                                                           *
 *****************************************************************************/

Scalar matrix_sum(matrix_t matrix,
        Row rows,
        Column columns)
{

    return sum(*matrix, rows * columns);
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix_grand ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void matrix_grand(matrix_t matrix,
        Row rows,
        Column columns)
{

    grand(*matrix, rows * columns);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix_zero ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void matrix_zero(matrix_t matrix,
        Row rows,
        Column columns)
{

    zero(*matrix, rows*columns);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- matrix_one ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void matrix_one(matrix_t matrix,
        Row rows,
        Column columns)
{

    one(*matrix, rows*columns);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- matrix_two ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void matrix_two(matrix_t matrix,
        Row rows,
        Column columns)
{

    two(*matrix, rows*columns);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix_three ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix_three(matrix_t matrix,
        Row rows,
        Column columns)
{

    three(*matrix, rows*columns);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix_test ------------------------------ *
 *                                                                           *
 *****************************************************************************/

/*
 * m
 *  NxM
 *
 * **m -> *m[0] -> m[0][0]--m[0][1]--   ..  --m[0][M]--,
 *           |     .__________________________________/
 *           |     |
 *           |     v
 *        *m[1] -> m[1][0]--m[1][1]--   ..  --m[1][M]--,
 *           |     .__________________________________/
 *           |     |
 *           |     v
 *        *m[2] -> m[2][0]--m[2][1]--   ..  --m[2][M]--,
 *           |     .__________________________________/
 *           |     |
 *           |     v
 *        *m[3] -> m[3][0]--m[3][1]--   ..  --m[3][M]--,
 *           |     .__________________________________/
 *           |     |
 *           |     v
 *          ...   ...             ...
 *           |     .__________________________________/
 *           |     |
 *           |     v
 *        *m[N] -> m[N][0]--m[N][1]--   ..  --m[N][M]
 *
 *
 */

void matrix_test(matrix_t matrix,
        Row rows,
        Column columns)
{

    printf("  (&matrix[0][0]) = [%p]\n",  (&matrix[0][0]));
    printf(" *(&matrix[0])    = [%p]\n", *(&matrix[0]));
    printf(" *(matrix[0])     = ["data_fmt"]\n", *(matrix[0]));
    printf("  &matrix[0]      = [%p]\n",  &matrix[0]);
    /*
    // printf(" *(&matrix[0][0]) = [%08.4f]\n", *(&matrix[0][0]));
    // printf("[%08.4f]\n", *(&matrix[0][0]));
    // printf("[%08.4f]\n", *(&matrix[0][0]));
    // printf("[%08.4f]\n", *(&matrix[0][0]));
    */
    return;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------- matrix_times_two ---------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix_times_two (matrix_t A,
        Row rows,
        Column columns)
{

    /*
     *  A      = A     +   A
     *   MxN      MxN       MxN
     */
    array_add(*A, *A, *A, rows*columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- matrix_times_n ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix_inner_power_n (
        unsigned int n,
        matrix_t A,
        Row rows,
        Column columns)
{

    unsigned int i;

    /*
     *  A      = A     +   A
     *   MxN      MxN       MxN
     *
     *  repeat n times
     */
    for (i = 0; i < (n-1); i++)
        array_add(*A, *A, *A, rows*columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix_add ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix_add (matrix_t A,/*Row rows, Column columns,*/
                 matrix_t B,/*Row rows, Column columns,*/
                 matrix_t C, Row rows, Column columns)

{

    /*
     * A     +  B     =  C
     *  MxN      MxN      MxN
     */
    array_add(*A, *B, *C, rows*columns);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- matrix_to_array ---------------------------- *
 *                                                                           *
 *****************************************************************************/

array_t matrix_to_array(matrix_t matrix)
{
    /* exemplo de uso:
     *
     *   A = matrix_to_array(B);
     *   printf(data_fmt "\n", A[0]);
     *   printf(data_fmt "\n", A[1]);
     */

    return matrix[0];

}
/*****************************************************************************
 *                                                                           *
 * ------------------------------- scalar_mul ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void scalar_mul (Scalar scalar,
                 matrix_t matrix, Row rows, Column columns)
{

    unsigned int i;
    Size         size = rows*columns;
    array_t        array = matrix[0];

    for (i = 0; i < size; ++i)
    {
        array[i] *=scalar;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- scalar_add ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void scalar_add (Scalar scalar,
                 matrix_t matrix, Row rows, Column columns)
{

    unsigned int i;
    Size         size = rows*columns;
    array_t        array = matrix[0];

    for (i = 0; i < size; ++i)
    {
        array[i] +=scalar;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- scalar_min ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void scalar_min (Scalar scalar,
                 matrix_t matrix, Row rows, Column columns)
{

    unsigned int i;
    Size         size = rows*columns;
    array_t        array = matrix[0];

    for (i = 0; i < size; ++i)
    {
        array[i] -=scalar;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- scalar_div ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void scalar_div (Scalar scalar,
                 matrix_t matrix, Row rows, Column columns)
{

    unsigned int i;
    Size         size = rows*columns;
    array_t        array = matrix[0];

    for (i = 0; i < size; ++i)
    {
        array[i] /=scalar;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- trans ----------------------------------- *
 *                                                                           *
 *****************************************************************************/

void trans (matrix_t matrix, Row rows, Column columns)
{

    unsigned int i,
                 j;

    Size         size = rows*columns;
    matrix_t       aux = new_matrix(rows,columns);

    for (i = 0; i < rows; ++i)
        for (j = 0; j < columns; ++j)
        {
            aux[j][i] = matrix[i][j];
        }
    ;

    copy_matrix(matrix, aux, size);

    matrix_destroy(aux);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ copy_matrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void copy_matrix(matrix_t dest, matrix_t orig, Size size) {

    unsigned int i;
    array_t        ptr_1 = orig[0],
    ptr_2 = dest[0];

    for (i = 0; i < size; ++i)
        ptr_2[i] = ptr_1[i];

    ptr_1 = NULL;
    ptr_2 = NULL;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- matrix_mul ------------------------------ *
 *                                                                           *
 *****************************************************************************/

/*
   matrix_t A = new_matrix(2,3);

   matrix_t B = new_matrix(3,2);

   matrix_t C = new_matrix(2,2);

   Scalar a_val[2][3] = {
   {1,2,3},
   {4,5,6}
   };

   Scalar b_val[3][2] = {
   {7 ,  8},
   {9 , 10},
   {11, 12}
   };

   initialize_w_static_matrix(A, a_val[0], 2*3);

   print_matrix(A, 2, 3);

   printf("\n");

   initialize_w_static_matrix(B, b_val[0], 3*2);

   print_matrix(B, 3, 2);

   printf("\n");

   matrix_mul(A, 2, 3,
   B, 3, 2,
   C, 2, 2);

   print_matrix(C, 2, 2);

   matrix_destroy(A);
   matrix_destroy(B);
   matrix_destroy(C);

   .. OR ..

   Size   A_l = 2000,
   A_c = 300,
   B_l = 300,
   B_c = 2000;

   matrix_t A = new_matrix(A_l, A_c);
   matrix_t B = new_matrix(B_l, B_c);
   matrix_t C = new_matrix(A_l, B_c);

   matrix_grand(A, A_l, A_c);
   matrix_grand(B, B_l, B_c);

   matrix_mul(A, A_l, A_c,
   B, B_l, B_c,
   C, A_l, B_c);

   matrix_destroy(A);
   matrix_destroy(B);
   matrix_destroy(C);
   */

void matrix_mul (matrix_t A, Row rows_A, Column columns_A,
                 matrix_t B, Row rows_B, Column columns_B,
                 matrix_t C, Row rows_C, Column columns_C)
{

    unsigned long int i,
                  j,
                  k;

    if (columns_A != rows_B)
    {
        fatal_error("Multiply a row with a column of the same length!");
    }

    /*
     *   C   =  A    *   B
     *    MxP   MxN      NxP
     */

    for ( i = 0; i < rows_A; i++ )
    {
        for ( j = 0; j < columns_B; j++ )
        {

            C[i][j] = 0;

            for ( k = 0; k < columns_A; k++ )

                /* Canonical matrix_t Multiplication */
                C[i][j] += A[i][k]*B[k][j];

            /*printf("C[%lu][%lu] = "data_fmt"\n", i, j, C[i][j]);*/
        }
    }

    return;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- printf_matrix ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void print_matrix(matrix_t matrix,
                  Row rows,
                  Column columns)
{

    unsigned int i,
                 factor = 0;

    for (i = 0; i < ( rows * columns); i++) {

        printf("["data_fmt"]", *(&matrix[0][0] + i));

        if (i == (columns - 1) + factor) {

            factor += columns;

            printf("\n");
        }
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- matrix_destroy ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix_destroy(matrix_t matrix)
{

    free(*matrix);
    free(matrix);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ new_matrix ------------------------------- *
 *                                                                           *
 *****************************************************************************/

matrix_t new_matrix(Row rows, Column columns) {

    unsigned int i;

    matrix_t       matrix;

    /* ///////////////////////////////////////////////////////////////////////// */
    /* ---------------------- allocate pointers to rows -----------------------  */
    /* ///////////////////////////////////////////////////////////////////////// */

    matrix = (matrix_t) malloc((size_t)((rows)*sizeof(array_t)));

    if (!matrix)
    {
        fatal_error("Couldn't allocate memory");
    }

    matrix[0] = new_array(rows*columns);

    for(i = 1; i < rows; i++)
        matrix[i] = matrix[i-1] + columns;

    zero(*matrix, rows*columns);

    return matrix;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------- kernel__clone_matrix ------------------------------ *
 *                                                                           *
 *****************************************************************************/

/*  Exemplo de uso:
    ==============

    matrix_t A,
    B;

    A = new_matrix(3, 4);
    matrix_grand(A, 3, 4);

    print_matrix(A, 3, 4);

    B = kernel__clone_matrix(A, 3, 4);
    print_matrix(B, 3, 4);

    matrix_destroy(A);
    matrix_destroy(B);
    */

matrix_t kernel__clone_matrix(matrix_t A, Row rows, Column columns)
{

    matrix_t       matrix = new_matrix(rows, columns);

    Size         size = rows*columns;

    copy_matrix(matrix,  A, size);

    return matrix;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------- initialize_w_static_matrix ---------------------- *
 *                                                                           *
 *****************************************************************************/

/*
   exemplo de uso:
   ==============

   Size   n = 3;
   matrix_t M = new_matrix(n, n);

   Scalar v[3][3] = {
   {2, -4, 8},
   {5,  4, 6},
   {-3, 0, 2}
   };

   initialize_w_static_matrix(M, v[0], n*n);

   print_matrix(M, n, n);

   printf("DET: "data_fmt"\n", gaussian_elimination(M, n));

   matrix_destroy(M);
   */

void initialize_w_static_matrix(matrix_t dest, Scalar *orig, Size size) {

    unsigned int i;
    array_t        ptr_1 = orig,
                 ptr_2 = dest[0];

    for (i = 0; i < size; ++i)
        ptr_2[i] = ptr_1[i];

    ptr_1 = NULL;
    ptr_2 = NULL;

    return;

}

/*****************************************************************************
 *                                                                           *
 * K E R N E L                                                               *
 * ===========                                                               *
 *                                                                           *
 *****************************************************************************/

/*****************************************************************************
 *                                                                           *
 * ------------------------------ matrix2array ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void matrix2array(array_t array,
        matrix_t matrix, Row rows, Column columns)
{
    unsigned int i,
                 j;

    for (i = 0; i < rows; ++i)
        for (j = 0; j < columns; ++j)
        {
            array[columns*(i) + j] = matrix[i][j];
        }
    ;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ array2matrix ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void array2matrix(matrix_t matrix, Column columns, array_t array, Size size)
{
    unsigned int i,
                 j,
                 k;

    for (k = 0; k < size; ++k)
    {
        i = k/columns;
        j = k%columns;

        /* printf("<%u,%u>\n", i, j); */

        matrix[i][j] = array[k];
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------- new_array_matrix2array ------------------------ *
 *                                                                           *
 *****************************************************************************/

array_t new_array_matrix2array(matrix_t matrix, Row rows, Column columns)
{

    array_t        array = new_array(rows*columns);

    matrix2array(array, matrix, rows, columns);

    /* array_destroy(array); */

    return array;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------ new_matrix_array2matrix ------------------------ *
 *                                                                           *
 *****************************************************************************/

/*  exemplo de uso:
    ==============

    array_t a = new_array(10);
    matrix_t m;

    grand(a, 10);
    print_array(a, 10);

    m = new_matrix_array2matrix(a, 10, 2, 5);

    print_matrix(m, 2, 5);

    array_destroy(a);
    matrix_destroy(m);
    */

matrix_t new_matrix_array2matrix(array_t array,
                                 Size size,
                                 Row rows, Column columns)
{

    matrix_t       matrix = new_matrix(rows, columns);

    if (size != columns*rows)
    {
        fatal_error("The product of the number of rows and columns should be equal to the vector size.");
    }

    array2matrix(matrix, columns, array, size);

    return matrix;

}



/*****************************************************************************
 *                                                                           *
 * ------------------------------ Determinant ------------------------------ *
 *                                                                           *
 *****************************************************************************/
/*
   Recursive definition of determinate using expansion by minors.
   */

Scalar Determinant(matrix_t matrix, unsigned int n)
{
    unsigned int  i,
                  j,
                  j1,
                  j2;

    Scalar        det = 0;
    matrix_t        m   = NULL;

    if (n < 1)
    { /* Error */

    }

    else if (n == 1)
    { /* Shouldn't get used */
        det = matrix[0][0];
    }

    else if (n == 2)
    {
        det = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }

    else
    {
        det = 0;
        for (j1 = 0; j1 < n; j1++)
        {
            m = (matrix_t)malloc( (n-1)*sizeof(array_t) );
            for (i = 0; i < n-1; i++)
                m[i] = (array_t)malloc( (n-1)*sizeof(Scalar) );
            for (i = 1; i < n; i++)
            {
                j2 = 0;
                for (j = 0; j < n; j++)
                {
                    if (j == j1)
                        continue;
                    m[i-1][j2] = matrix[i][j];
                    j2++;
                }
            }

            det += pow(-1.0, 1.0+j1+1.0) * matrix[0][j1] * Determinant(m, n-1);

            for (i = 0; i < n-1; i++)
                free(m[i]);

            free(m);
        }
    }
    return(det);
}

/*****************************************************************************
 *                                                                           *
 * -------------------------------- CoFactor ------------------------------- *
 *                                                                           *
 *****************************************************************************/
/*
   Find the cofactor matrix of a square matrix
 */
void CoFactor(matrix_t a, unsigned int n, matrix_t b)
{
    unsigned int i,
                 j,
                 ii,
                 jj,
                 i1,
                 j1;

    Scalar       det;
    matrix_t       c;

    c = (matrix_t)malloc((n-1)*sizeof(array_t));

    for (i=0;i<n-1;i++)
        c[i] = (array_t)malloc((n-1)*sizeof(Scalar));

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {

            /* Form the adjoint a_ij */
            i1 = 0;
            for (ii = 0; ii < n; ii++)
            {
                if (ii == i)
                    continue;

                j1 = 0;
                for (jj = 0; jj < n; jj++)
                {
                    if (jj == j)
                        continue;

                    c[i1][j1] = a[ii][jj];
                    j1++;
                }
                i1++;
            }

            /* Calculate the determinate */
            det = Determinant(c, n-1);

            /* Fill in the elements of the cofactor */
            b[i][j] = pow(-1.0, i + j + 2.0) * det;
        }
    }

    for (i = 0; i < n-1; i++)
        free(c[i]);

    free(c);
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- Transpose ------------------------------- *
 *                                                                           *
 *****************************************************************************/
/*
   Transpose of a square matrix, do it in place
 */
void Transpose(matrix_t matrix, unsigned int n)
{
    unsigned int i,
                 j;

    Scalar       tmp;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            tmp          = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}
