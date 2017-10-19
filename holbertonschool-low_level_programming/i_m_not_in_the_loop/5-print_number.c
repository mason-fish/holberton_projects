#include "my_functions.h"

/*
 *[print_number] TAKES AN INT, DIVIDES IT BY 10 AS MANY TIMES AS IT CAN TO
 *DETERMINE HOW MANY DIGITS IT CONTAINS, AND THEN CONVERTS EACH DIGIT TO A SINGLE
 *CHAR BY USING THE MODULUS OPERATOR AND ADDING THIS VALUE TO THE CHAR '0'. FINALLY
 *THIS CHAR IS PASSED TO THE [print_char] FUNCTION.
 */

void print_number(int n) {
  int i = 1;
  int temp;
  int mod = 1;
  if (n < 0) {
    print_char('-');
    mod = -1;
  }
  for(temp = n; temp > 9 || temp < -9; temp = temp / 10) {
    i++;
  }
  while(i) {
    int i2 = i--;
    temp = n;
    while(i2-- > 1) {
      temp /= 10;
    }
    print_char(((temp % 10) * mod + '0'));
  }
}
