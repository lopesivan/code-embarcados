#include "complex.h"

    static
int test (int argc, char *argv[])
{

    if (argc != 3)
        return EXIT_FAILURE;

    Complex  V[3];
    Complex  ans[6];
    Complex  cis = NULL;

    int i;

    V[0] = createComplex__mag_angle(atos(argv[1]), atos(argv[2]));

    cis = cisn(120);
    V[1] = mulComplex(V[0], cis);
    destroyComplex(cis);

    cis = cisp(120);
    V[2] = mulComplex(V[0], cis);
    destroyComplex(cis);

    /* horário */
    ans[0] = subComplex(V[1], V[0]);
    ans[1] = subComplex(V[2], V[1]);
    ans[2] = subComplex(V[0], V[2]);

    /* trigonometrico */
    ans[3] = subComplex(V[2], V[0]);
    ans[4] = subComplex(V[1], V[2]);
    ans[5] = subComplex(V[0], V[1]);

    for (i = 0; i < 3; ++i)
    {
        printComplex  (V[i]);
    }

    puts("forward");

    for (i = 0; i < 6; ++i)
    {
        printComplex  (ans[i]);
        if (i==2)
            puts("backward");
    }

    for (i = 0; i < 6; ++i)
    {
        destroyComplex (ans[i]);
    }

    for (i = 0; i < 3; ++i)
    {
        destroyComplex (V[i]);
    }

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
