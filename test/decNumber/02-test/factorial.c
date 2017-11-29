#define  DECNUMDIGITS 34           /* work with up to 34 digits */
#include "decNumber.h"             /* base number library */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

decNumber* fact (decNumber *ans, const decNumber *n, decContext *set);
decNumber* fact (decNumber *ans, const decNumber *n, decContext *set)
{

  decNumber *res = ans;

  /* n < 0 */
  if (decNumberIsNegative(n))
  {
    decNumberFromString(res, "0", set);
    return res;
  }

  /* n == 0 */
  if (decNumberIsZero(n))
  {
    decNumberFromString(res, "1", set);
    return res;
  }

  /* n == 1 */

  decNumber tmp;
  decNumberFromString(&tmp, "1", set);
  decNumberCompare(&tmp, &tmp, n, set);
  if (decNumberIsZero(&tmp))
  {
    decNumberFromString(res, "1", set);
    return res;
  }

  decNumber one;
  decNumber ans1;

  decNumberFromString(&one, "1", set);
  decNumberSubtract(&ans1, n, &one, set);
  fact(&ans1, &ans1, set);
  decNumberMultiply(res, n, &ans1, set);

  return res;
}

int main(int argc, char *argv[]) {
  decNumber *res;
  decNumber a;
  decNumber b;
  decContext set;
  char string[DECNUMDIGITS+14];

  decContextTestEndian(0);

  decContextDefault(&set, DEC_INIT_BASE);
  set.traps=0;
  set.digits=DECNUMDIGITS;

  decNumberFromString(&b, "230", &set);

  /* res = &a; */
  /* res = decNumberAdd(&a, &a, &b, &set); */

  /* res = decNumberCompare(&a, &a, &b, &set); */
  /* 200 < 230 => -1 */
  /* 230 > 200 =>  1 */
  /* 200 = 200 =>  0 */

  res = &b;
/*
  decNumberFromString(&a, "-1", &set);
  fact(res, &a, &set);
  decNumberToString(res, string);
  printf("%s => %s\n", "fact(-1)", string);

  decNumberFromString(&a, "0", &set);
  fact(res, &a, &set);
  decNumberToString(res, string);
  printf("%s => %s\n", "fact(0)", string);

  decNumberFromString(&a, "1", &set);
  fact(res, &a, &set);
  decNumberToString(res, string);
  printf("%s => %s\n", "fact(1)", string);
*/
  decNumberFromString(&a, "8", &set);
  fact(res, &a, &set);
  decNumberToString(res, string);
  printf("%s => %s\n", "fact(8)", string);

  return 0;
}
