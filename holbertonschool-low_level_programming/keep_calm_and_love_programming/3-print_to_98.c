#include <stdio.h>

/* print_to_98 WILL TAKE ANY INT AND INCREMENT
 * OR DECREMENT IT TO THE INT 98.
 */
void print_to_98(int n) {
  printf("%d", n);
  while (n < 98) {
    printf(", %d", ++n);
  }
  while (n > 98) {
    printf(", %d", --n);
  }
  printf("\n");
}
