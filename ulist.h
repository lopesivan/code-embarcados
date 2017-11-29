#ifndef ULIST_H
#define ULIST_H

#include "list.h"
#include "ltype.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

int  add   (List *list, list_t value);
int  rm    (List *list, ListElmt *element);
void init  (List *list);
void delete(List *list);
void print_list(const List *list);

#define lrm(list, element) \
   if (rm(&(list), (element)) == EXIT_FAILURE) \
      return EXIT_FAILURE

#define linit(list) \
   init(&(list))

#define ldelete(list) \
   delete(&(list))

#define lprint(list) \
   print_list(&(list))

#define ladd(list, value) \
   if (add(&(list), (value)) == EXIT_FAILURE) \
      return EXIT_FAILURE

#endif 		/* ULIST_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
