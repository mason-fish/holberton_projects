#include <stdio.h>

#define AMOUNT 50

int main(void) {
  unsigned long x = 1;
  unsigned long y = 1;
  unsigned long z;
  int ndx = AMOUNT;

  printf("%lu", y);

  while (ndx--) {
    z = y;
    y += x;
    x = z;
    printf(", %lu", y);
  }

  printf("\n");

  return 0;
}
