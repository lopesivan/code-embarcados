#ifndef MATRIX_H
#define MATRIX_H

#include "array.h"
#include "kernel/kmatrix.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

typedef struct Matrix_t* Matrix;

Matrix createMatrix(Row rows, Column columns);
Matrix createMatrixWithDataNull(Row rows, Column columns);

void destroyMatrix(Matrix matrix);

Matrix multiplyMatrix(Matrix A,
                      Matrix B);

void printMatrix(Matrix matrix);

void zeroMatrix  (Matrix matrix);
void oneMatrix   (Matrix matrix);
void twoMatrix   (Matrix matrix);
void threeMatrix (Matrix matrix);
void randMatrix  (Matrix matrix);

void timesTwoMatrix (Matrix matrix);

void powerNMatrix (unsigned int n, Matrix matrix);

Array toArray (Matrix matrix);

matrix_t getDataMatrix  (Matrix matrix);
Size     getRows        (Matrix matrix);
Size     getColumns     (Matrix matrix);

Scalar    MatDot  (Matrix a, Matrix b);
Matrix    MatAdd  (Matrix a, Matrix b);

void          copyMatrix  (Matrix orig, Matrix dest);
Matrix       cloneMatrix  (Matrix orig);
void      transposeMatrix (Matrix matrix);
void destroyClonedMatrix  (Matrix matrix);
Matrix createMatrixWithArray(Array array, Row rows, Column columns);

void mapMatrix (Matrix matrix, Scalar (*f)(Scalar));

Scalar Det (Matrix A);
Matrix Inv (Matrix A);

#define MatMul(A, B)                     multiplyMatrix((A), (B))
#define destroyCloned(matrix)            destroyClonedMatrix((matrix))
#define cloneArray(array, rows, columns) createMatrixWithArray((array), (rows), (columns))

#endif 		/* MATRIX_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
