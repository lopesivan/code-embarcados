#include "complex.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- createComplex ------------------------------ *
 *                                                                           *
 *****************************************************************************/

Complex createComplex(Scalar r, Scalar i)
{
    Complex complex = createMatrix(2,2);

    matrix_t data   = getDataMatrix (complex);

    data[0][0] =  r; data[0][1] = i;
    data[1][0] = -i; data[1][1] = r;

    return complex;
}

Complex createComplex__mag_angle(Scalar m, Scalar angle)
{
    return createComplex(m * cos(TORAD(angle)),
                         m * sin(TORAD(angle)));
}

Complex cisComplex(Scalar angle)
{
    return createComplex__mag_angle(1.0, angle);
}

Scalar getRealComplex(Complex complex)
{
    matrix_t data = getDataMatrix  (complex);
    return data[0][0];
}

Scalar getImagComplex(Complex complex)
{
    matrix_t data = getDataMatrix  (complex);
    return data[0][1];
}

void __one__(Complex complex)
{
    Complex one  = createComplex(1, 0);
    copyMatrix(one, complex);
    destroyComplex(one);
    return;
}

void __i__(Complex complex)
{
    Complex i = createComplex(0, -1);
    copyMatrix(i, complex);
    destroyComplex(i);
    return;
}

void __i2__(Complex complex)
{
    Complex i  = createComplex(0, -1);
    Complex i2 =  mulMatrix(i,i);
    copyMatrix(i2, complex);

    destroyComplex(i);
    destroyComplex(i2);
    return;
}

/* operacoes */
Complex mulComplex(Complex A,
                   Complex B)
{
    return mulMatrix(A, B);
}

void prodComplex(Scalar scalar, Complex complex)
{
    prodMatrix(scalar, complex);

    return;
}

Complex addComplex(Complex A,
                   Complex B)
{
    return addMatrix(A, B);
}

Complex subComplex(Complex A,
                   Complex B)
{
    return subMatrix(A, B);
}

Complex negComplex(Complex complex)
{
    Complex neg = createComplex__mag_angle(1.0, 180);
    Complex nz = mulComplex(neg, complex);

    destroyMatrix (neg);

    return nz;
}

Complex divComplex(Complex A,
                   Complex B)
{
    Scalar det  = Det(B);

    Matrix invB = Inv(B);

    prodMatrix(1/det, invB);

    copyMatrix  (invB, B);

    destroyMatrix (invB);

    return mulMatrix(A, B);
}


Complex conjComplex(Complex complex)
{
    Complex conjugate = createMatrix(2,2);

    matrix_t data   = getDataMatrix (conjugate);

    Scalar r = getRealComplex (complex);
    Scalar i = getImagComplex (complex);

    data[0][0] = r; data[0][1] = -i;
    data[1][0] = i; data[1][1] =  r;

    return conjugate;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- destroyComplex ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void destroyComplex(Complex complex)
{
    destroyMatrix(complex);

    return;
}

Scalar magComplex(Complex complex)
{
    Scalar r = getRealComplex (complex);
    Scalar i = getImagComplex (complex);

    return pythagoras(r, i);
}


Scalar argComplex(Complex complex)
{
    Scalar r = getRealComplex (complex);
    Scalar i = getImagComplex (complex);

    Scalar arg = TODEG(
            atan2(ABS(i), ABS(r))
            );

    if (r >= 0)
    {
        if (r == 0)
        {
            return (i/ABS(i))*90.0;
        }

        if (i >= 0)
        { /* Q1 */
            if (i == 0)
            {
                return 0;
            }

            return arg;
        }
        else
        { /* Q4 */
            return -1.0*arg;
        }
    }
    else
    {
        if (i >= 0)
        { /* Q2 */
            if (i == 0)
            {
                return -180;
            }
            return 180.0 - arg;
        }
        else
        { /* Q3 */
            return arg - 180.0;
        }
    }
}

void printComplex(Complex complex)
{
    Scalar m = magComplex(complex);
    Scalar a = argComplex(complex);

    printf("< %c"data_fmt", %c"data_fmt " >\n",
        (m<0.0f)? '-':'+', fabs(m),
        (a<0.0f)? '-':'+', fabs(a)
          );

    return;
}
