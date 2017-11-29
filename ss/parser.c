#include "parser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <execinfo.h>


typedef enum {
    LAMBDA=0,
    ADDITION,
    MULTIPLICATION,
    INTEGER,
    VARIABLE

} TypeOfElemment;

struct ExpTree_{
    TypeOfElemment   type;
    char             *value;
    ExpTree          *left;
    ExpTree          *right;
};

void parser(char *exp)
{
    int i = 0;
    ExpTree *root = NULL;

    root = Element(exp, &i);
    printf("value:%s\n", root->value);
    root->left = Element(exp, &i);
    printf("value:%s\n", root->left->value);

    /* while (root) */
    /* { */
    /*     root = Element(exp, &i); */
    /*     break; */
    /* } */

    printf("e=%s\n", exp);
    printf("i=%d\n", i);

    free(root->value);
    free(root);

    return;
}

char extract_variable(char *exp, int *position)
{
    return exp[*position];
}

char* extract_int(char *exp, int first, int last)
{
    char          *dest;

    size_t        size = last - first + 1;

    dest = (char*) malloc(size + 1);

    printf("1=%s\n", dest);
    printf("1=%s\n", exp);
    printf("1=%c\n", exp[first]);
    printf("1=%c\n", exp[last]);
    printf("1=%d\n", size);
    memcpy(dest, exp+first, size);
    printf("2=%s\n", dest);
    printf("SIZE(exp)=%d\n", strlen(exp));

    char *e = (char*) malloc(strlen(exp) - last +1);
    memcpy(e, exp+last+1, strlen(exp) - last);
    memcpy(exp, e, strlen(exp) - last);
    printf("2=%s\n", e);
    printf("SIZE(e)=%d\n", strlen(e));
    free(e);
    /* realloc( exp, 6 * sizeof *ptr ); */

    return dest;
}

ExpTree *Expression(char *exp, int *position)
{
    if (exp[*position])
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = LAMBDA;
        node->value = 0;
        return node;
    }
    else
        return Addition(exp, position);
}

ExpTree *Addition(char *exp, int *position)
{
    ExpTree *node = malloc(sizeof(*node));
    node->type = ADDITION;
    node->left = Multiplication(exp, position);
    node->right = RestOfAddition(exp, position);
    return node;
}

ExpTree *Multiplication(char *exp, int *position)
{
    ExpTree *node = malloc(sizeof(*node));
    node->type = MULTIPLICATION;
    node->left = Element(exp, position);
    node->right = RestOfMultiplication(exp, position);
    return node;
}

ExpTree *RestOfAddition(char *exp, int *position)
{
    ExpTree *node;
    if (exp[*position] == '+')
    {
        ++*position;
        return Addition(exp, position);
    }
    else
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = LAMBDA;
        node->value = 0;
        return node;
    }
}

ExpTree *RestOfMultiplication(char *exp, int *position)
{
    ExpTree *node;
    if (exp[*position] == '*')
    {
        ++*position;
        return Element(exp, position);
    }
    else
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = LAMBDA;
        node->value = 0;
        return node;
    }
}

ExpTree *Element(char *exp, int *position)
{
    if (exp[*position] == '(')
    {
        ExpTree *node;
        ++*position;
        node = Expression(exp, position);
        if (!exp[*position] != ')')
            printf("Expected ) at position %d\n", *position);
        else
            ++*position;
        return node;
    }
    else if (exp[*position] == ')')
    {
        printf("Unexpected ) at position %d\n", *position);
        return NULL;
    }
    else if (exp[*position] >= '0' && exp[*position] <= '9')
    {
        int first = *position;
        while (exp[*position] >= '0' && exp[*position] <= '9')
        {
            ++*position;
        };

        ExpTree *node = malloc(sizeof(*node));
        node->type = INTEGER;
        int last = *position - 1;
        node->value = extract_int(exp, first, last);
        return node;
    }
    else if ((exp[*position] >= 'a' && exp[*position] <= 'z') ||
             (exp[*position] >= 'A' && exp[*position] <= 'Z') ||
             exp[*position] == '_')
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = VARIABLE;
        node->value = extract_variable(exp, position);
        return node;
    }
    else
    {
        printf("Warning: unexpected character %c in location %d\n", exp[*position], *position);
        return NULL;
    }
}

void split(char *tmp, const char *d)
{

    /* dummy_function(); */

    char *t = strtok(tmp, d);

    while (t)
    {
        printf("->@%s@\n", t);
        t = strtok(NULL, d);
        printf("->(%c)\n", *d);
    }
}

/* Obtain a backtrace and print it to stdout. */
void print_trace (void)
{
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    printf ("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        printf ("%s\n", strings[i]);

    free (strings);
}

/* A dummy function to make the backtrace more interesting. */
void dummy_function (void)
{
    print_trace ();
}

char *new_string(char *input_string)
{

    char          *string;

    size_t        size = strlen(input_string);

    string = (char*) malloc(size + 1);

    strcpy(string, input_string);

    return string;

}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
