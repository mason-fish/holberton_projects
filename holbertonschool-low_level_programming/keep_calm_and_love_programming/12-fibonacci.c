#include <stdio.h>
#define AMOUNT 97

/* PRINT THE FIRST 98 TERMS OF FIBONACCI SEQUENCE
 * BEGINING WITH 1, AND 2. BREAKS OVERFLOWN LONG INTS
 * INTO TWO PIECES WHEN NECESSARY.
 */
long expon(int i) {
  long n = 1;
  while (i-- > 1) {
    n = n * 10;
  }
  return n;
}

void print_term(long x2, long y1, long y2) {
  if (y2 || x2) {
    printf(", %ld%ld", y1, y2);
  } else {
    printf(", %ld", y1);
  }
}

int main(void) {
  signed long x1 = 1, y1 = 1, x2 = 0, y2 = 0, z1, z2;
  int i = 1, ndx = AMOUNT;
  printf("%ld", y1);
  while (ndx--) {
    /* check if overflow will occur on _1 */
    if ((x1 + y1) < 0) {
      x2 = x2 + (expon(i) * (x1 % 10));
      x1 /= 10;
      y2 = y2 + (expon(i) * (y1 % 10));
      y1 /= 10;
      i++;
    }
    /* stash full y value */
    z1 = y1;
    z2 = y2;
    /* add _1 sides together */
    y1 += x1;
    /* check if new digit to _2 */
    if ((x2 + y2) / expon(i)) {
      y1 += 1;
      y2 = x2 + y2 - expon(i);
    } else {
      y2 += x2;
    }
    /* update full x value */
    x1 = z1;
    x2 = z2;
    /* print depending on use of algorithm or not */
    print_term(x2, y1, y2);
  }
  printf("\n");
  return 0;
}
