unsigned int factorial(unsigned int n)
{

    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);

}

#define  DECNUMDIGITS 34           /* work with up to 34 digits */
#include "decNumber.h"             /* base number library */
#include <stdio.h>                 /* for printf */

int main(int argc, char *argv[]) {
  decNumber a, b;                  /* working numbers */
  decContext set;                  /* working context */
  char string[DECNUMDIGITS+14];    /* conversion buffer */

  decContextTestEndian(0);         /* warn if DECLITEND is wrong */

  if (argc<3) {                    /* not enough words */
    printf("Please supply two numbers to add.\n");
    return 1;
    }
  decContextDefault(&set, DEC_INIT_BASE); /* initialize */
  set.traps=0;                     /* no traps, thank you */
  set.digits=DECNUMDIGITS;         /* set precision */

  decNumberFromString(&a, argv[1], &set);
  decNumberFromString(&b, argv[2], &set);

  decNumberAdd(&a, &a, &b, &set);            /* a=a+b */
  decNumberToString(&a, string);

  printf("%s + %s => %s\n", argv[1], argv[2], string);
  return 0;
  } /* main */
