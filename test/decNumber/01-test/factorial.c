#define  DECNUMDIGITS 34           /* work with up to 34 digits */
#include "decNumber.h"             /* base number library */
#include <stdio.h>                 /* for printf */

/*
decCompare(&a, &b, 0)
  a<b -1
  a=b 0
  a>b 1
*/
/*
decNumber* fact (const decNumber *a, decContext *set);

decNumber* fact (const decNumber *a, decContext *set)
{
  decCompare(&a, &b, 0)

}
*/

int main(int argc, char *argv[]) {
  decNumber *res;
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

  /* a=a+b */
  /* decNumberAdd(&a, &a, &b, &set); */
  /* a=a*b */
  /* decNumberMultiply(&a, &a, &b, &set); */
  /* a=a-b  */
  res = decNumberSubtract(&a, &a, &b, &set);
  decNumberToString(&a, string);

  printf("%s + %s => %s\n", argv[1], argv[2], string);

  decNumberToString(res, string);
  printf("%s + %s => %s\n", argv[1], argv[2], string);

  return 0;
}
