#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "list.h"
#include "karray.h"

/*****************************************************************************
*                                                                            *
*  Define a structure for polynomial.                                        *
*                                                                            *
*****************************************************************************/

typedef struct term_
{   Scalar         coeff;
    unsigned int   degree;
} Term;

typedef List Poly;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

void print_poly(List *poly);

Scalar horner_evaluate(Scalar x, List *poly);

Scalar polynomial_evaluate(Scalar x, List *poly);

Scalar obsolete_horner_evaluate(Scalar x,
                                unsigned int DegreeOfPolynomial,
                                array_t CoefficientsOfPolynomial);

Scalar obsolete_polynomial_evaluate(Scalar x,
                                    unsigned int DegreeOfPolynomial,
                                    array_t CoefficientsOfPolynomial);

bool new_term(Term **term);

array_t new_polynomial_coefficients(const char *list_of_numbers);

bool added_a_new_term_to_polynomial( Term *term,
                                     List *poly);

void set_polynomial_term(Term *term,
                         int degree,
                         const array_t coefficientsOfPolynomial);

List polynomial(Size degreeOfPolynomial,
                const array_t coefficientsOfPolynomial);

void print_term(const Term *term);

Scalar pval(Scalar x,
            unsigned int degree,
            const char *coefficients_of_polynomial);

#define poly_destroy list_destroy

#define poly_coeff(term) ((term)->coeff)

#define poly_degree(term) ((term)->degree)

#endif       /* POLYNOMIAL_H */

