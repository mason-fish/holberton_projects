#include "my_functions.h"

/* print_alphabet increments through the ASCII characters, starting 
 * at the char 'a', until it exceeds the char 'z' and uses 
 * print_char to print each iteration.
 */
void print_alphabet(void) {
  char letter = 'a';
  while(letter <= 'z') {
    print_char(letter++);
  } 
}
