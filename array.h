#ifndef ARRAY_H
#define ARRAY_H

#include "karray.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

typedef struct Array_t* Array;

Array createArray              (Size size);
Array createArrayWithDataNull  (Size size);

void destroyArray    (Array array);

void zeroArray       (Array array);
void printArray      (Array array);
void oneArray        (Array array);
void twoArray        (Array array);
void threeArray      (Array array);
void randArray       (Array array);
void reverseArray    (Array array);

Scalar sumArray      (Array array);

void mapArray           (Array array, Scalar (*f)(Scalar));
Scalar seq_sumArray     (Array array, Scalar (*f)(Scalar));
Scalar seq_productArray (Array array, Scalar (*f)(Scalar));

Scalar productArray  (Array array);
array_t getData      (Array array);
Size    getSize      (Array array);

Scalar   Dot  (Array a, Array b);
Array    Mul  (Array a, Array b);
Array    Add  (Array a, Array b);

void toarray  (Array array, array_t data);

#endif /* ARRAY_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
