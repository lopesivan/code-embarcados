#ifndef PARSER_H
#define PARSER_H

typedef struct ExpTree_ ExpTree;
/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

ExpTree *Expression(char *exp, int *position);
ExpTree *Addition(char *exp, int *position);
ExpTree *RestOfAddition(char *exp, int *position);
ExpTree *Element(char *exp, int *position);
ExpTree *Multiplication(char *exp, int *position);
ExpTree *RestOfMultiplication(char *exp, int *position);
char extract_variable(char *exp, int *position);
char* extract_int(char *exp, int first, int last);
void parser(char *exp);

void split(char *tmp, const char *d);
void print_trace (void);
void dummy_function (void);
char *new_string(char *list_of_numbers);

#endif /* PARSER_H */
/* -*- vim: set ts=4 sw=4 tw=78 ft=header: -*- */
