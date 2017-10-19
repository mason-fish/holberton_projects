#include "my_functions.h"

/* print_base16 increments through the chars 0-9 and then increments 
 * through the chars A-F, using print_char to print each iteration.
 */
void print_base16(void) {
  char i = '0';
  while(i <= 'F') {
    print_char(i++);
    if (i == ('9' + 1)) {
      i = 'A';
    }
  }
}
