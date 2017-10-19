#include <stdio.h>
#define NUMBER 1024

/* PRINTS ALL OF THE NUMBERS BETWEEN 0 AND 1024 
 * THAT ARE MULTIPLES OF 3 AND 5.
 */
int main(void) {
  int x = NUMBER;
  int total = 0;
  
  while(x--) {
    if (!(x % 3) || !(x % 5)) {
      total += x;
    }
  }
  
  printf("%d\n", total);

  return 0;
}
