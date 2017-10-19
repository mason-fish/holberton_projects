#include <stdio.h>
#define LIMIT 4000000

/* PRINTS THE SUM OF ALL OF THE EVEN TERMS WITHIN
 * THE FIBONACCI SEQUENCE UNTIL THE SET LIMIT.
 */
int main(void) {
  unsigned long x = 1;
  unsigned long y = 1;
  unsigned long z;
  unsigned long total;

  while (y <= LIMIT) {
    z = y;
    y += x;
    x = z;
    if (!(y % 2)) {
      total += y;
    }
  }

   printf("%lu\n", total);

  return 0;
}
