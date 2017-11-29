#include "complex.h"

    static
Complex getLineBC (Complex AB)
{
    Complex cis = cisn(60);

    /*
     *   V     =  V       *   cis(-60)
     *    CB       AB
     */
    Complex CB = mulComplex(AB, cis);
    Complex BC = negComplex(CB);

    destroyComplex(cis);
    destroyComplex(CB);

    return BC;
}

    static
Complex getLineAC (Complex AB)
{
    /*
     *   V     =  V    *   cis(-60)
     *    CB       AB
     *
     *   V     =  - V
     *    BC         CB
     *
     *   V     =  V    *   cis(-60)
     *    AC       BC
     *
     *   V     =  - V
     *    CA         AC
     */
    Complex cis = cisn(60);
    Complex CB  = mulComplex(AB, cis);
    Complex BC  = negComplex(CB);
    Complex AC  = mulComplex(BC, cis);
    Complex CA  = negComplex(AC);

    destroyComplex(cis);
    destroyComplex(CB);
    destroyComplex(BC);
    destroyComplex(AC);

    return CA;
}

    static
Complex getA (Complex AB)
{
    /*
     *               /                         \
     *              |    - V                   |
     *              |       AB                 |
     *   V     = - <   ----------   *  cis(30)  >
     *    A         |   2*cos(30)              |
     *              |                          |
     *              \                          /
     */

    Complex nAB  = negComplex(AB);

    prodComplex(1/(2*cos((TORAD(30)))), nAB);

    Complex cis = cisp(30);

    Complex nA = mulComplex(nAB, cis);
    Complex A  = negComplex(nA);

    destroyComplex(nAB);
    destroyComplex(nA);
    destroyComplex(cis);

    return A;
}

    static
Complex getForward(Complex A)
{
    Complex cis     = cisn(120);
    Complex forward = mulComplex(A, cis);
    destroyComplex(cis);

    return forward;
}

    static
Complex getBackward(Complex A)
{
    Complex cis      = cisp(120);
    Complex backward = mulComplex(A, cis);
    destroyComplex(cis);

    return backward;
}

    static
int test (int argc, char *argv[])
{

    if (argc != 5)
        return EXIT_FAILURE;

    Complex AB = createComplex__mag_angle(atos(argv[1]), atos(argv[2]));

    Complex BC = getLineBC(AB);
    Complex CA = getLineAC(AB);
    Complex A  = getA(AB);
    Complex B  = getForward(A);
    Complex C  = getBackward(A);

    printComplex(AB);
    printComplex(CA);
    printComplex(BC);

    puts("A-B-C:");
    printComplex(A);
    printComplex(B);
    printComplex(C);

    destroyComplex(AB);
    destroyComplex(BC);
    destroyComplex(CA);
    destroyComplex(A);
    destroyComplex(B);
    destroyComplex(C);

    return EXIT_SUCCESS;
}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int main(int argc, char *argv[])
{

    if (test(argc, argv) == EXIT_FAILURE)
        exit(EXIT_FAILURE);

    return EXIT_SUCCESS;

}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
