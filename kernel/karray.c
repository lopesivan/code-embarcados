#include "karray.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- zero --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void zero(array_t array, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 0;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- one ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

void one(array_t array,
         Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 1;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- two ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

void two(array_t array,
         Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 2;

    return;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- three --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void three(array_t array,
           Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 3;

    return;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- array_grand --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void grand(array_t array,
                 Size size)
{

    unsigned int i;

    /* initialize array_grand generator */

    srand ((unsigned int)time(NULL));

    for (i = 0; i < size; i++)

/* generate array_grand numbers
 * -----------------------
 *
 * RAND_MAX = RAND_MAX
 *
 * A number between 0 and RAND_MAX : rand()
 * A number between 0 and 99: rand() % 100
 * A number between 0 and 9: rand() % 10
 *
 */

    array[i] = (Scalar)(rand() % 100);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- sum ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar sum(array_t array,
           Size size)
{

    unsigned int i;

    Scalar       sum=0;

    for (i = 0; i < size; i++)

        sum += array[i];

    return sum;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ seq_sum ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar seq_sum(array_t array,
               unsigned int begin,
               unsigned int end,
               Scalar (*f)(Scalar))
{

    unsigned int i;

    Scalar       sum = 0;

    for (i = begin; i < end; i++)

        sum += f(array[i]);

    return sum;

}

/*****************************************************************************
 *                                                                           *
 * -------------------------- seq_product ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar seq_product(array_t array,
                   unsigned int begin,
                   unsigned int end,
                   Scalar (*f)(Scalar))
{

    unsigned int i;

    Scalar       product=1;

    for (i = begin; i < end; i++)

        product *= f(array[i]);

    return product;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- dot ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar dot(array_t A,
           array_t B,
           Size size)
{

    Scalar        value;

    array_t         C = new_array(size);

    array_dot(A, B, C, size);

    value = sum(C, size);

    free(C);

    return value;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- product --------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar product(array_t array,
               Size size)
{

    unsigned int i;

    Scalar       product=1;

    for (i = 0; i < size; i++)

        product *= array[i];

    return product;

}


/*****************************************************************************
 *                                                                           *
 * ------------------------------ print_array ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void print_array(array_t array, Size size) {

    unsigned int i;

    for (i = 0; i < size; i++)
    {
        printf("array[%u] = " data_fmt "\n", i, array[i]);
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- array_add ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_add(array_t A,
               array_t B,
               array_t C, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        C[i] = A[i] + B[i];

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- array_dot ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_dot(array_t A,
               array_t B,
               array_t C, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        C[i] = A[i] * B[i];

    return;
}


/*****************************************************************************
 *                                                                           *
 * --------------------------- array_reverse ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_reverse(array_t array, Size size) {

    unsigned int i,
                 end = size - 1;

    Scalar       temp;

    for (i = 0; i < size/2; i++) {
        temp       = array[i];
        array[i]   = array[end];
        array[end] = temp;

        end--;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- new_array ------------------------------- *
 *                                                                           *
 *****************************************************************************/

array_t new_array(Size size)
{

    array_t array;

    array = (array_t) malloc((size_t)(size) * sizeof(Scalar));

    if is_null(array)
        return NULL;

    /* initialize with zero */
    zero(array, size);

    return array;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------- new_array_of_split -------------------------- *
 *                                                                           *
 *****************************************************************************/

array_t new_array_of_split(const char *list_of_numbers)
{

    char          *string = new_string(list_of_numbers);

    char          **res   = NULL;
    char          *p      = strtok(string, " ");

    int           number_of_spaces = 0,
                  i;

    /*
     * split string and append tokens to 'res'
     */

    while (p) {
        res = realloc(res, sizeof(char *) * ++number_of_spaces);

        if is_null(res) {
            printf("%s:In function `%s':\n" "%s:%d: %s\n", \
               __FILE__, __FUNCTION__, __FILE__, __LINE__, \
               "memory allocation failed"
            );

            exit(EXIT_FAILURE);
        }

        res[number_of_spaces - 1] = p;

        p = strtok(NULL, " ");
    }

    /*
     * realloc one extra element for the last NULL
     */

    res = realloc(res, sizeof(char *) * (number_of_spaces + 1));
    res[number_of_spaces] = 0;

    /*
     * print the result
     */

    /*
    for (i = 0; i < number_of_spaces; ++i)
        printf("res[%d] = %s\n", i, res[i]);
    */

    array_t array = new_array(number_of_spaces);

    for (i = 0; i < number_of_spaces; ++i) {
        array[i] = atos(res[i]);
    }

    /*
     * free the memory allocated
     */
    free(res);
    free(string);

    return array;
}

/*****************************************************************************
 *                                                                           *
 * ----------------------------- array_destroy ----------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_destroy(array_t array)
{

    if(array != NULL) {
        free(array);
    } else {
        fatal_error("Couldn't frees the memory space pointed.");
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------ set_array_w_split_string ----------------------- *
 *                                                                           *
 *****************************************************************************/

void set_array_w_split_string(array_t dest, const char *list_of_numbers)
{
    char *string = new_string(list_of_numbers);

    copy_string_to_array(dest, string);

    /*
     * free the memory allocated
     */
    free(string);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- new_string ------------------------------ *
 *                                                                           *
 *****************************************************************************/

char *new_string(const char *list_of_numbers)
{

    char          *string;

    size_t        size = strlen(list_of_numbers);

    string = (char*) malloc(size + 1);

    strcpy(string, list_of_numbers);

    return string;

}

/*****************************************************************************
 *                                                                           *
 * -------------------------- copy_string_to_array ------------------------- *
 *                                                                           *
 *****************************************************************************/

void copy_string_to_array(array_t dest, char *string)
{
    char          **res = NULL;
    char          *p    = strtok(string, " ");

    int           number_of_spaces = 0,
                  i;

    /*
    * split string and append tokens to 'res'
    */

    while (p) {
        res = realloc(res, sizeof(char *) * ++number_of_spaces);

        if is_null(res) {
            printf("%s:In function `%s':\n" "%s:%d: %s\n", \
               __FILE__, __FUNCTION__, __FILE__, __LINE__, \
               "memory allocation failed"
            );

            exit(EXIT_FAILURE);
        }

        res[number_of_spaces - 1] = p;

        p = strtok(NULL, " ");
    }

    /*
     * realloc one extra element for the last NULL
     */
    res = realloc(res, sizeof(char *) * (number_of_spaces + 1));
    res[number_of_spaces] = 0;

    for (i = 0; i < number_of_spaces; ++i) {
        dest[i] = atos(res[i]);
    }

    /*
     * free the memory allocated
     */
    free(res);

}
