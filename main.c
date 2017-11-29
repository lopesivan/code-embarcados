#include <stdlib.h>
#include <stdio.h>

#include "ulist.h"

   static
int test (int argc, char *argv[])
{

   List               list;
   ListElmt           *element = NULL;

   linit(list);

   ladd(list, 42);
   ladd(list, 43);
   ladd(list, 44);
   ladd(list, 45);
   ladd(list, 46);

   lprint(list);

   element = list_head(&list);
   lrm(list, element);

   lprint(list);

   ldelete(list);

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
      exit(1);

   return EXIT_SUCCESS;

}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
