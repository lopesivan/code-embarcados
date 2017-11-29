#include <hpgcc49.h>
#include <hpstack.h>
#include <hpgraphics.h>

#include "help.h"

void draw_help (char *error)
{

    //draws this help and exit

    hpg_set_font (hpg_stdscreen, hpg_get_bigfont ());
    hpg_set_color (hpg_stdscreen, HPG_COLOR_BLACK);

    hpg_clear ();
    /* hpg_draw_text ("Pythagoras", 25, 0); */
    hpg_draw_text ("Two", 25, 0);
    hpg_draw_text (error, 0, 15);
    hpg_set_font (hpg_stdscreen, hpg_get_minifont ());

    hpg_draw_text (
    //             "xxxx xx xx xxxxxxx xxxxxxxxxxx\n" <- size of line
                   "Entrada:\n"
                   "numeros (a) e (b) reais.", 0, 28);
                   /* "catetos (a) e (b) ou hipotenusa.", 0, 28); */

    hpg_draw_text (
    //             "xxxx xx xx xxxxxxx xxxxxxxxxxx\n" <- size of line
                   "Saida:\n"
                   "soma de (a) com (b).\n", 0, 50);
                   /* "(hipotenusa) ou um dos catetos.\n", 0, 50); */

    hpg_flip ();

    //wait a bit
    sys_waitRTCTicks (2);
    while (1)
        if (keyb_isAnyKeyPressed ())
            break;

    return;

}
