#include "complex.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- createComplex ------------------------------ *
 *                                                                           *
 *****************************************************************************/

Complex createComplex(Scalar r, Scalar i)
{
    Complex complex = createArray(2);
    array_t data = getData (complex);
    data[0] = r;
    data[1] = i;

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
    array_t data = getData (complex);
    return data[0];
}

Scalar getImgComplex(Complex complex)
{
    array_t data = getData (complex);
    return data[1];
}

Complex mulComplex(Complex A,
        Complex B)
{
    array_t data_A = getData (A);
    array_t data_B = getData (B);

    Scalar r = data_A[0] * data_B[0] - data_A[1] * data_B[1];

    Scalar i = data_A[0] * data_B[1] + data_A[1] * data_B[0];

    return createComplex(r, i);
}
/*****************************************************************************
 *                                                                           *
 * ---------------------------- destroyComplex ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void destroyComplex(Complex complex)
{
    destroyArray(complex);

    return;
}

Scalar magComplex(Complex complex)
{
    array_t data = getData (complex);

    Scalar r = data[0];
    Scalar i = data[1];

    return pythagoras(r, i);
}


Scalar argComplex(Complex complex)
{
    array_t data = getData (complex);

    Scalar r = data[0];
    Scalar i = data[1];

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
            return 180.0 + arg;
        }
    }
}

void printComplex(Complex complex)
{
    printf("<"data_fmt", "data_fmt " >\n",
            magComplex(complex),
            argComplex(complex)
          );

    return;
}
