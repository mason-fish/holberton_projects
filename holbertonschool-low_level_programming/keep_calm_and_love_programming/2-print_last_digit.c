#include "my_functions.h"
#include <limits.h>

/* print_last_digit WILL TAKE AN INT OF ANY SIZE
 * WITHIN ITS LIMITS AND PRINT THE FINAL DIGIT.
 */
void print_last_digit(int n) {
  if (n < 0 && n > INT_MIN) {
    n *= -1;
  }
  if (n == INT_MIN) {
    n += 10;
    n *= -1;
  }
  print_char(((n % 10) + '0'));
}
