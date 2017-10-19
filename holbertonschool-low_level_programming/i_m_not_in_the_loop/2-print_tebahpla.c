#include "my_functions.h"

/* print_tebahpla decrements through the ASCII chars 'z' 
 * through 'a' and passes each char to print_char for each iteration.
 */
void print_tebahpla(void) {
  char letter = 'z';
  while(letter >= 'a') {
    print_char(letter--);
  }
}
