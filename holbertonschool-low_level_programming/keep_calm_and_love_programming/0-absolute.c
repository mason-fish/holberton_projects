#include <limits.h>

/* absolute CONVERTS A NUMBER TO AN ABSOLUTE NUMBER
 * IF IT ISN'T ALREADY.
 */
int absolute(int n) {
  if (n > INT_MIN && n < 0) {
    n *= -1;
  }
  return n;
}
