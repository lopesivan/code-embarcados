#ifndef COMPLEX_H
#define COMPLEX_H

#include "kernel/pythagoras.h"

#include "array.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

typedef Array Complex;

#define imagpart(cval)  (getRealComplex((cval))
#define realpart(cval)  (getImgComplex((cval)))
#define cisp(angle)     (cisComplex((angle)))
#define cisn(angle)     (cisComplex(-(angle)))

Complex createComplex(Scalar r, Scalar i);
Complex createComplex__mag_angle(Scalar m, Scalar angle);
Complex cisComplex(Scalar angle);

Complex mulComplex(Complex A,
                   Complex B);


void destroyComplex(Complex complex);
void printComplex(Complex complex);

Scalar getRealComplex(Complex complex);
Scalar getImgComplex(Complex complex);
Scalar argComplex(Complex complex);
Scalar magComplex(Complex complex);

#endif 		/* COMPLEX_H */
