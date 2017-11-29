#include <hpgcc49.h>
#include <hpstack.h>

#include "help.h"
#include "configure.h"

#include "two.h"

typedef Scalar (*function) (Scalar, Scalar);

int first (double *value);

static
int execute (function f)
{
    // Pops a double from the stack

    int    ret;

    double a;

    if ((ret = first (&a)) == HPS_OK)
    {
        double b;

        if ((ret = first (&b)) == HPS_OK)
        {
            double answer = f (a, b);

            // Pushes it to the stack
            if ((ret = hps_push_real (answer)) != HPS_OK)
            {
                draw_help (hps_error (ret));
            }
        }
        else
        {
            draw_help (hps_error (ret));
        }
    }
    else
    {
        draw_help (hps_error (ret));
    }

    return ret;
}

int first (double *value)
{
    int    ret;

    if ((ret = hps_pop_real (value)) != HPS_OK)
    {
        draw_help (hps_error (ret));
    }

    return ret;
}

int main (void)
{
    function f = NULL;

    f = two;

    if (execute (f) != HPS_OK)
        return EXIT_FAILURE;
    else
        return EXIT_SUCCESS;
}
