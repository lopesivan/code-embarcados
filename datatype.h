#ifndef DATATYPE_H
#define DATATYPE_H

#ifdef DECNUMBER
    #define  DECNUMDIGITS 34           /* work with up to 34 digits */
#endif

#ifdef BOOLTYPE
    typedef enum {false=0, true=1} bool;
#endif

#ifdef ENABLE_INTEGER
    #include "integer.h"
#else
    #include "real.h"
#endif

#endif       /* DATATYPE_H */
