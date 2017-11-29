#include "polynomial.h"

/*****************************************************************************
*                                                                            *
*  ------------------------------ print_poly ------------------------------  *
*                                                                            *
*****************************************************************************/

/*
    Exemplo de Uso:
    ==============

    List poly;

    Size degreeOfPolynomial = 2;

    array_t coefficientsOfPolynomial = new_array(degreeOfPolynomial + 1);

    *  -> x^2 + 3*x + 15 *
    coefficientsOfPolynomial[0] = 15;
    coefficientsOfPolynomial[1] = 3;
    coefficientsOfPolynomial[2] = 1;

    poly = polynomial(degreeOfPolynomial, coefficientsOfPolynomial);

    print_poly(&poly);

    array_destroy(coefficientsOfPolynomial);
    list_destroy(&poly);
*/

void print_poly(List *poly)
{
    ListElmt   *element;

    Term       *term;

    for (element  = list_head(poly);
         element != NULL;
         element  = list_next(element))
    {
        term = list_data(element);
        print_term(term);
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- horner_evaluate ---------------------------- *
 *                                                                           *
 *****************************************************************************/

/*
    Exemplo de uso:
    ===============

    List           poly;

    unsigned int   degree = 5;
    array_t          coefficientsOfPolynomial = new_array(degree+1);

    coefficientsOfPolynomial[0] = 1;
    coefficientsOfPolynomial[1] = 1;
    coefficientsOfPolynomial[2] = 0;
    coefficientsOfPolynomial[3] = 0;
    coefficientsOfPolynomial[4] = 0;
    coefficientsOfPolynomial[5] = 1;

    poly = polynomial(degree, coefficientsOfPolynomial);

    printf("P("data_no_fmt") = "data_fmt"\n",
           2.0,
           obsolete_polynomial_evaluate(2.0, degree, coefficientsOfPolynomial) );

    array_reverse(coefficientsOfPolynomial, degree+1);

    printf("P("data_no_fmt") = "data_fmt"\n",
           2.0,
           obsolete_horner_evaluate(2.0, degree, coefficientsOfPolynomial) );

    printf("P("data_no_fmt") = "data_fmt"\n",
           2.0,
           horner_evaluate(2.0, &poly) );

    array_destroy(coefficientsOfPolynomial);

    list_destroy(&poly);
 */

Scalar horner_evaluate(Scalar x, List *poly)
{
    /*
        We want to evaluate the polynomial in x, of coefficients
        CoefficientsOfPolynomial, using Horner's method.
        The result is stored in result.
    */

    ListElmt   *element;
    Term       *term;

    Scalar result = 0;

    for (element  = list_head(poly);
         element != NULL;
         element  = list_next(element))
    {
        term = list_data(element);

        result = result * x + term->coeff;

    }

    return result;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------ polynomial_evaluate ---------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar polynomial_evaluate(Scalar x, List *poly)
{

    ListElmt   *element;
    Term       *term;

    Scalar result = 0;

    for (element  = list_head(poly);
         element != NULL;
         element  = list_next(element))
    {
        term   = list_data(element);

        result = result +
                term->coeff*pow(x, term->degree);
    }

    return result;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------- obsolete_polynomial_evaluate --------------------- *
 *                                                                           *
 *****************************************************************************/

/*
    Exemplo de Uso:
    ==============

    P(x) = 5*x^2 + 3*x + 12
    P(7) = 278
    =============================

    unsigned int   degree = 2;
    array_t          coefficientsOfPolynomial = new_array(degree+1);
    Scalar         p_x;
    const Scalar   x = 7.0;

    coefficientsOfPolynomial[0] = 5;
    coefficientsOfPolynomial[1] = 3;
    coefficientsOfPolynomial[2] = 12;

    p_x = PolynomialEvaluate(x, degree, coefficientsOfPolynomial);

    destroy_array(coefficientsOfPolynomial);

    printf("P("data_no_fmt") = "data_fmt"\n", x, p_x );
    printf("P("data_no_fmt") = "data_fmt"\n", x, 5*x*x + 3*x + 12);

    .. OR ..

    unsigned int   degree = 2;
    Scalar         coefficientsOfPolynomial[3] = {5, 3, 12};
    Scalar         p_x;
    const Scalar   x = 7.0;

    p_x = PolynomialEvaluate(x, degree, coefficientsOfPolynomial);

    printf("P("data_no_fmt") = "data_fmt"\n", x, p_x );
    printf("P("data_no_fmt") = "data_fmt"\n", x, 5*x*x + 3*x + 12);

    .. OR ..

    unsigned int   degree = 8;
    Scalar         coefficientsOfPolynomial[9] = {1, 2, 3, 4, 5, 3, 12, 1, 8};
    Scalar         p_x;
    const Scalar   x = 7.0;

    p_x = PolynomialEvaluate(x, degree, coefficientsOfPolynomial);

    printf("P("data_no_fmt") = "data_fmt"\n", x, p_x );
    printf("P("data_no_fmt") = "data_fmt"\n", x,
           1*x*x*x*x*x*x*x*x +
           2*x*x*x*x*x*x*x +
           3*x*x*x*x*x*x +
           4*x*x*x*x*x +
           5*x*x*x*x +
           3*x*x*x +
           12*x*x +
           1*x+
           + 8
    );

    .. OR ..

    P(x) = 1*x^6 + 4*x^5 - 72*x^4 -214*x^3 + 1127x*^2 +1602*x + 5040

    MAPLE
    =====

    > p :=  x -> (x-3)*(x+3)*(x+4)*(x+8)*(x-2)*(x-7);
    p := x -> (x - 3) (x + 3) (x + 4) (x + 8) (x - 2) (x - 7)

    > p(-3);
    0

    > p(x);
    (x - 3) (x + 3) (x + 4) (x + 8) (x - 2) (x - 7)

    > expand(p(x));
    6      5       4        3         2
    x  + 3 x  - 71 x  - 147 x  + 1006 x  + 1080 x - 4032

    > f :=  x -> x^6 + 4*x^5 - 72*x^4 - 214*x^3 + 1127*x^2 +1602*x + 5040;
    6      5       4        3         2
    f := x -> x  + 4 x  - 72 x  - 214 x  + 1127 x  + 1602 x + 5040

    > f(3);
    10080

    > f(-3);
    10080

    > f(0);
    5040

    unsigned int   degree = 6;
    array_t          coefficientsOfPolynomial = new_array(degree+1);

    coefficientsOfPolynomial[0] = 1;
    coefficientsOfPolynomial[1] = 4;
    coefficientsOfPolynomial[2] = -72;
    coefficientsOfPolynomial[3] = -214;
    coefficientsOfPolynomial[4] = 1127;
    coefficientsOfPolynomial[5] = 1602;
    coefficientsOfPolynomial[6] = 5040;

    printf("P("data_no_fmt") = "data_fmt"\n",
    3.0,
    PolynomialEvaluate(3.0, degree, coefficientsOfPolynomial) );

    printf("P("data_no_fmt") = "data_fmt"\n",
    -3.0,
    PolynomialEvaluate(-3.0, degree, coefficientsOfPolynomial) );

    printf("P("data_no_fmt") = "data_fmt"\n",
    0.0,
    obsolete_polynomial_evaluate(0.0, degree, coefficientsOfPolynomial) );

    array_destroy(coefficientsOfPolynomial);
*/

Scalar obsolete_polynomial_evaluate(Scalar x,
                                    unsigned int DegreeOfPolynomial,
                                    array_t CoefficientsOfPolynomial)
{

    Scalar       result = CoefficientsOfPolynomial[DegreeOfPolynomial];
    unsigned int i;

    for(i = 0 ; i < DegreeOfPolynomial; i++)
    {
        result = result +
                CoefficientsOfPolynomial[i]*pow(x, DegreeOfPolynomial-i);
    }
    return result;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------ obsolete_horner_evaluate ----------------------- *
 *                                                                           *
 *****************************************************************************/

/*
    Exemplo  de  Uso
    ================

    unsigned int   degree = 5;
    array_t          coefficientsOfPolynomial = new_array(degree+1);

    convertendo da base 2 para a base 10
    ====================================

    (110001)  -> (10)
            2       10
    =====================================

    coefficientsOfPolynomial[0] = 1;
    coefficientsOfPolynomial[1] = 1;
    coefficientsOfPolynomial[2] = 0;
    coefficientsOfPolynomial[3] = 0;
    coefficientsOfPolynomial[4] = 0;
    coefficientsOfPolynomial[5] = 1;

    printf("P("data_no_fmt") = "data_fmt"\n",
    2.0,
    obsolete_polynomial_evaluate(2.0, degree, coefficientsOfPolynomial) );

    * invertendo o vetor *
    * ------------------
    array_reverse(coefficientsOfPolynomial, degree+1);

    printf("P("data_no_fmt") = "data_fmt"\n",
    2.0,
    obsolete_horner_evaluate(2.0, degree, coefficientsOfPolynomial) );

    array_destroy(coefficientsOfPolynomial);

*/

Scalar obsolete_horner_evaluate(Scalar x,
                                unsigned int DegreeOfPolynomial,
                                array_t CoefficientsOfPolynomial)
{
    /*
        We want to evaluate the polynomial in x, of coefficients
        CoefficientsOfPolynomial, using Horner's method.
        The result is stored in result.
    */

    Scalar result = 0;
    int    i;

    for(i = DegreeOfPolynomial; i >= 0; i--)
    {
        result = result * x + CoefficientsOfPolynomial[i];
    }

    return result;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------- new_term ----------------------------------- *
 *                                                                           *
 *****************************************************************************/

bool new_term(Term **term)
{
    return ((*term) = (Term *) malloc(sizeof(Term))) == NULL;
}

/*****************************************************************************
 *                                                                           *
 * --------------------- added_a_new_term_to_polynomial -------------------- *
 *                                                                           *
 *****************************************************************************/

bool added_a_new_term_to_polynomial(Term *term, List *poly)
{
    return list_ins_next(poly, NULL, term) != 0;
}

/*****************************************************************************
 *                                                                           *
 * -------------------------------- set_polynomial_term -------------------------------- *
 *                                                                           *
 *****************************************************************************/

void set_polynomial_term(Term *term,
                         int degree,
                         const array_t coefficientsOfPolynomial)
{
    term->coeff  = coefficientsOfPolynomial[degree];
    term->degree = degree;

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- polynomial ------------------------------ *
 *                                                                           *
 *****************************************************************************/

List polynomial(Size degreeOfPolynomial,
                const array_t coefficientsOfPolynomial)
{

    List          poly;
    Term          *term;
    int           i;

    /*****************************************************************************
    *                                                                            *
    *  Initialize the linked list.                                               *
    *                                                                            *
    *****************************************************************************/

    list_init(&poly, free);

    for(i = degreeOfPolynomial; i >= 0; i--)
    /*for(i = 0; i <= degreeOfPolynomial; i++)*/
    {

        if (new_term(&term))
        {
            fatal_error("Couldn't allocate memory");
        }

        set_polynomial_term(term, i, coefficientsOfPolynomial);

        if (added_a_new_term_to_polynomial(term, &poly))
        {
            fatal_error("Couldn't associate the term with polynomial");
        }

    }

    return poly;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------- new_polynomial_coefficients ---------------------- *
 *                                                                           *
 *****************************************************************************/
    /*
     Exemplo de uso:
     ===============

    Poly         poly;

    unsigned int degree = 2;

    array_t coefficientsOfPolynomial =
            new_polynomial_coefficients("1 -6 9");

    poly = polynomial(degree, coefficientsOfPolynomial);

    print_poly(&poly);

    printf("P("data_no_fmt") = "data_fmt"\n",
           5.0,
           polynomial_evaluate(5.0, &poly));

    printf("->P("data_no_fmt") = "data_fmt"\n",
           5.0,
           (5.0 * 5.0 - 6 * 5.0 + 9));

    array_destroy(coefficientsOfPolynomial);

    poly_destroy(&poly);
    */

array_t new_polynomial_coefficients(const char *list_of_numbers)
{

    char          *string = new_string(list_of_numbers);

    char          **res   = NULL;
    char          *p      = strtok(string, " ");

    int           number_of_spaces = 0,
                  i;

    /*
     * split string and append tokens to 'res'
     */
    while (p)
    {
        res = realloc(res, sizeof(char *) * ++number_of_spaces);

        if (res == NULL)
        {
            fatal_error("memory allocation failed");
        }

        res[number_of_spaces - 1] = p;

        p = strtok(NULL, " ");
    }

    /*
     * realloc one extra element for the last NULL
     */
    res = realloc(res, sizeof(char *) * (number_of_spaces + 1));
    res[number_of_spaces] = 0;

    array_t array = new_array(number_of_spaces);

    for (i = 0; i < number_of_spaces; ++i)
    {
        array[i] = atos(res[i]);
    }

    array_reverse(array, number_of_spaces);

    /*
     * free the memory allocated
     */
    free(res);
    free(string);

    return array;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- print_term ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void print_term(const Term *term)
{
    printf("degree: %u\tcoeff: "data_no_fmt"\n",
           term->degree,
           term->coeff);
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- pval --------------------------------- *
 *                                                                           *
 *****************************************************************************/

    /*
     Exemplo de uso:
     ==============

    Scalar       x =  5.0;
    unsigned int i;

    printf("P("data_no_fmt") = "data_fmt"\n",
           x,
           pval(x, 2, "1 -6 9"));


    for (i = 0; i < 20; ++i)
    {
        x = (Scalar)i;
        printf("P("data_no_fmt") = "data_fmt"\n",
               x,
               pval(x, 2, "1 -6 9"));
    }

    array_t array = new_array(25);
    for (i = 0; i < 25; ++i)
    {
        x = (Scalar)i;
        array[i] = pval(x, 2, "1 -6 9");
    }

    print_array(array, 25);
    printf("soma dos termos: "data_fmt"\n", sum(array, 25));
    printf("produto dos termos: "data_fmt"\n", product(array, 25));

    matrix_t M = new_matrix_array2matrix(array, 25, 5, 5);
    print_matrix(M, 5, 5);
    matrix_destroy(M);

    array_destroy(array);
    */

Scalar pval(Scalar x,
            unsigned int degree,
            const char *coefficients_of_polynomial)
{
    Poly         poly;

    array_t coefficientsOfPolynomial =
            new_polynomial_coefficients(coefficients_of_polynomial);

    poly = polynomial(degree, coefficientsOfPolynomial);

    Scalar value = polynomial_evaluate(x, &poly);

    array_destroy(coefficientsOfPolynomial);

    poly_destroy(&poly);

    return value;

}