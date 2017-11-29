/*
 *                     __ __       ___
 *                    /\ \\ \    /'___`\
 *                    \ \ \\ \  /\_\ /\ \
 *                     \ \ \\ \_\/_/// /__
 *                      \ \__ ,__\ // /_\ \
 *                       \/_/\_\_//\______/
 *                          \/_/  \/_____/
 *                                        Algoritmos
 *
 *
 *      Author: Ivan Lopes
 *        Mail: ivan@42algoritmos.com.br
 *        Site: http://www.42algoritmos.com.br
 *     License: gpl
 *    Language: C ansi
 *        File: main.c
 *        Date: Sat 17 Jun 2017 01:50:07 AM BRT
 * Description:
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <execinfo.h>

#include "parser.h"

/*****************************************************************************
 *                                                                           *
 *  --------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int
main (int argc, char *argv[]) {
    /* char *e = "(1+(3*4+x)*y)+1"; */
    char *e = new_string("118+233+26");

    parser(e);

    return EXIT_SUCCESS;
}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
