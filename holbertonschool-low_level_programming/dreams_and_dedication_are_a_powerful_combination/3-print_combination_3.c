#include "my_functions.h"

/*
 * [print_combination_3] CYCLES THROUGH THREE PLACES OF DIGITS (xyz)
 * AND USES TWO DIFFERENT INCREMENTING INDEXES (next & nextX) TO RESET 
 * THE y AND x VALUES SO THAT THEY WILL NOT REPEAT A COMBINATION AND REMAIN
 * ORDERED CONSECUTIVELY.
 */

void print_combination_3(void) {
  int x = 0, y = 1, z = 2, next = 2, nextX = 2;
  print_number(x);
  print_number(y);
  print_number(z++);
  while (x < 8) {
    while (y < 9) {
      print_char(',');
      print_char(' ');
      print_number(x);
      print_number(y);
      print_number(z++);
      if (z > 9) {
	y = next++;
	z = next;
      }
    }
    next = nextX++;
    y = next++;
    z = next;
    x++;
  }
}
