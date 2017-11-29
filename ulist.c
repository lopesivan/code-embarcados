#include <stdlib.h>
#include <stdio.h>

#include "ulist.h"

void print_list(const List *list)
{

   ListElmt           *element;

   list_t             *data;
   int                i;

   /**************************************************************************
    *  Display the linked list.                                              *
    **************************************************************************/

   fprintf(stdout, "List size is %d\n", list_size(list));

   i = 0;
   element = list_head(list);

   while (1) {

      data = list_data(element);
      fprintf(stdout, "list[%03d]="list_data_fmt"\n", i, *data);

      i++;

      if (list_is_tail(element))
         break;
      else
         element = list_next(element);

   }

   return;

}

void print_list_element(const ListElmt *element)
{

   list_t             *data;

   data = list_data(element);
   fprintf(stdout, "=>"list_data_fmt"\n", *data);

   return;

}

int add(List *list, list_t value)
{
   list_t *data;

   data = (list_t *)malloc(sizeof(list_t));

   if is_null(data)
   {
      printf("%s:In function `%s':\n" "%s:%d: %s\n",    \
            __FILE__, __FUNCTION__, __FILE__, __LINE__, \
            "could not allocate the data pointer"
            );

      return EXIT_FAILURE;
   }

   *data = value;

   if (list_ins_next(list, NULL, data) != 0)
      return EXIT_FAILURE;

   return EXIT_SUCCESS;
}

void delete(List *list)
{
   fprintf(stdout, "Destroying the list\n");
   list_destroy(list);

   return;
}

int rm(List     *list,
      ListElmt  *element)
{
   list_t    *data;

   data =  list_data(element);

   if (list_rem_next(list, element, (void **)&data) != 0)
      return EXIT_FAILURE;

   free(data);

   return EXIT_SUCCESS;
}

void init(List *list)
{
   list_init(list, free);
   return;
}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
