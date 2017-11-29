#include <stdlib.h>
#include <stdio.h>

#include "ulist.h"

   static
int test (int argc, char *argv[])
{

   List               list;
   ListElmt           *element = NULL;

   linit(list);

   /* popula a lista */
   ladd(list, ":01: Todas as Opiniões que Há sobre a Natureza");
   ladd(list, ":02: Todas as opiniões que há sobre a Natureza");
   ladd(list, ":03: Nunca fizeram crescer uma erva ou nascer uma flor.");
   ladd(list, ":04: Toda a sabedoria a respeito das cousas");
   ladd(list, ":05: Nunca foi cousa em que pudesse pegar como nas cousas;");
   ladd(list, ":06: Se a ciência quer ser verdadeira,");
   ladd(list, ":07: Que ciência mais verdadeira que a das cousas sem ciência?");
   ladd(list, ":08: ");
   ladd(list, ":09: Fecho os olhos e a terra dura sobre que me deito");
   ladd(list, ":10: Tem uma realidade tão real que até as minhas costas a sentem.");
   ladd(list, ":11: Não preciso de raciocínio onde tenho espáduas.");
   ladd(list, ":12: ");
   ladd(list, ":13: Alberto Caeiro, in \"Poemas Inconjuntos\"");
   ladd(list, ":14: Heterónimo de Fernando Pessoa");

   lprint(list);
/*
   element = list_head(&list);
   lrm(list, element);
   lprint(list);

   element = list_next(element);
   lrm(list, element);
   lprint(list);

   element = list_next(element);
   element = list_next(element);
   element = list_next(element);
   lrm(list, element);
   lprint(list);
*/

   /* remove todos elementos da lista com exceção do head */
   element = list_head(&list);
   while(element)
   {

      print_list_element(element);
      lrm(list, element);

      if (list_is_tail(element))
         break;
   }

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
