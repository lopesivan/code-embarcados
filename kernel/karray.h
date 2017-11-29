#ifndef KARRAY_H
#define KARRAY_H

#include "narray.h"

typedef Scalar*              array_t;

typedef const unsigned long  Row;
typedef const unsigned long  Column;
typedef const unsigned long  Size;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

   void zero(array_t array, Size size);
    void one(array_t array, Size size);
    void two(array_t array, Size size);
  void three(array_t array, Size size);
void reverse(array_t array, Size size);
  void grand(array_t array, Size size);

Scalar sum(array_t array, Size size);
Scalar seq_sum(array_t array, unsigned int begin, unsigned int end, Scalar (*f)(Scalar));
Scalar seq_product(array_t array, unsigned int begin, unsigned int end, Scalar (*f)(Scalar));
Scalar dot(array_t A, array_t B, Size size);
Scalar product(array_t array, Size size);

char *new_string(const char *list_of_numbers);
array_t new_array_of_split(const char *list_of_numbers);

void set_array_w_split_string(array_t dest, const char *list_of_numbers);
void copy_string_to_array(array_t dest, char *string);

void print_array(array_t array, Size size);

void array_add(array_t A, array_t B, array_t C, Size size);
void array_dot(array_t A, array_t B, array_t C, Size size);
void array_reverse(array_t array, Size size);

array_t new_array(Size size);
void array_destroy(array_t array);

#endif 		/* KARRAY_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
