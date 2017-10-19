#include "my_functions.h"

/* [print_combination_2] LOOPS ONE INT (Y) UNTIL IT REACHES 10, THEN RESETS
 * TO AN INCREMENTING INDEX (NEXT) AND ALSO INCREMENTS ANOTHER INT (X). ON 
 * EACH ITERATION BOTH X AND Y ARE PRINTED, AS WELL AS A SPACE (' ') AND COMMA (',').
 */

void print_combination_2(void) {
  int x = 0, y = 1, next = 2;
  print_number(x);
  print_number(y++);
  while (x < 9) {
    print_char(',');
    print_char(' ');
    print_number(x);
    print_number(y++);
    if (y > 9) {
      x++;
      y = next++;
    }
  } 
}
