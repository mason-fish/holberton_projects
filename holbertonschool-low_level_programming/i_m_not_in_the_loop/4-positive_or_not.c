#include "my_functions.h"

/* positive_or_not takes an int, 'n', and checks if it is
 * greater than 0, less than 0, or equal to 0, and prints
 * back a 'P', 'N', or 'Z' respectively.
 */
void positive_or_not(int n) {
  if (n > 0) {
    print_char('P');
  }
  if (n < 0) {
    print_char('N');
  }
  if (n == 0) {
    print_char('Z');
  }
}
