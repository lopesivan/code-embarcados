#ifndef COMPLEX_H
#define COMPLEX_H

#include "matrix.h"
#include "pythagoras.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

typedef Matrix Complex;

#define imagpart(cval)  (getRealComplex((cval))
#define realpart(cval)  (getImagComplex((cval)))
#define cisp(angle)     (cisComplex((angle)))
#define cisn(angle)     (cisComplex(-(angle)))

Scalar getRealComplex(Complex complex);
Scalar getImagComplex(Complex complex);
Scalar magComplex(Complex complex);
Scalar argComplex(Complex complex);

void __one__(Complex complex);
void __i__(Complex complex);
void __i2__(Complex complex);
void prodComplex(Scalar scalar, Complex complex);
void destroyComplex(Complex complex);
void printComplex(Complex complex);

Complex mulComplex(Complex A, Complex B);
Complex addComplex(Complex A, Complex B);
Complex subComplex(Complex A, Complex B);
Complex divComplex(Complex A, Complex B);
Complex negComplex(Complex complex);
Complex conjComplex(Complex complex);
Complex createComplex(Scalar r, Scalar i);
Complex createComplex__mag_angle(Scalar m, Scalar angle);
Complex cisComplex(Scalar angle);

#endif 		/* COMPLEX_H */
