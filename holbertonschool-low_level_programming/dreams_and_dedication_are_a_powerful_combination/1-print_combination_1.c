#include "my_functions.h"

/*
 *[print_combination_1] PRINTS THE CHAR '0' AND THEN LOOPS
 *9 TIMES PRINTING ',' ' ' AND AN INCREMENTING NUMBER EACH
 *TIME UNTIL IT REACHES 10 (WHICH IT WILL NOT PRINT)
 */
void print_combination_1(void) {
  int ndx;
  print_char('0');
    for(ndx = 1; ndx <= 9; ndx++) {
      print_char(',');
      print_char(' ');
      print_char(ndx + '0');
    }
}
