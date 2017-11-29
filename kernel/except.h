#ifndef EXCEPT_H
#define EXCEPT_H

#include "hp50g.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

#define is_null(a) ((a) == NULL)

#define fatal_error(message)                                           \
    fprintf(stderr, "%s:In function `%s':\n" "%s:%d: %s\n",            \
            __FILE__, __FUNCTION__, __FILE__,  __LINE__, message"\n"); \
        exit(EXIT_FAILURE)

#endif       /* EXCEPT_H */
