#ifndef MATRIX_H
#define MATRIX_H

#include "kmatrix.h"
#include "array.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

typedef struct Matrix_t* Matrix;

#define MatMul(A, B)                     mulMatrix((A), (B))
#define destroyCloned(matrix)            destroyClonedMatrix((matrix))
#define cloneArray(array, rows, columns) createMatrixWithArray((array), (rows), (columns))

Matrix createMatrix(Row rows, Column columns);
Matrix createMatrixWithDataNull(Row rows, Column columns);
Matrix mulMatrix(Matrix A, Matrix B);
void printMatrix(Matrix matrix);
void destroyMatrix(Matrix matrix);
void zeroMatrix(Matrix matrix);
void oneMatrix(Matrix matrix);
void twoMatrix(Matrix matrix);
void threeMatrix(Matrix matrix);
void randMatrix(Matrix matrix);
Array toArray(Matrix matrix);
matrix_t getDataMatrix(Matrix matrix);
Size getRows(Matrix matrix);
Size getColumns(Matrix matrix);
void timesTwoMatrix(Matrix matrix);
void powerNMatrix(unsigned int n, Matrix matrix);
Scalar dotMatrix(Matrix A, Matrix B);
Matrix addMatrix(Matrix A, Matrix B);
Matrix subMatrix(Matrix A, Matrix B);
void copyMatrix(Matrix orig, Matrix dest);
Matrix cloneMatrix(Matrix orig);
void destroyClonedMatrix(Matrix matrix);
Matrix createMatrixWithArray(Array array, Row rows, Column columns);
void transposeMatrix(Matrix matrix);
void mapMatrix(Matrix matrix, Scalar (*f)(Scalar));
void prodMatrix(Scalar scalar, Matrix matrix);
Scalar Det(Matrix A);
Matrix Inv(Matrix A);
Array Cross(Array a, Array b);

#endif 		/* MATRIX_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
/* matrix.c */
