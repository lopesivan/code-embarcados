#ifndef HP50G_H
#define HP50G_H

#ifdef ENABLE_HP50G
    #include <hpgcc49.h>
#else
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <time.h>
    #include <unistd.h>
    #include <math.h>
#endif

#endif       /* HP50G_H */
