#include <stdio.h>
#include "param_struct.h"

int print_char(char);
void print_number(int);
void print_string_struct(struct Param *);
void print_string(char *);
void print_array_of_strings(char **);

/* print_params_structs_array() takes a struct pointer (params)
   and prints out its contents: char *str, int length, char **tab */
void print_params_structs_array(struct Param *params) {
  while(params->str != NULL) { 
    print_string_struct(params);
    print_array_of_strings(params->tab);
    params++;
  }
}


/* print_string_struct() receives a struct String pointer and
   prints out the string contained within. */
void print_string_struct(struct Param *str) {
  int i;

  i = 0;
  while(i < str->length) {
    print_char(str->str[i]);
    i++;
  }

  print_char('\n');
  print_number(str->length);
  print_char('\n');

}

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

/* print_array_of_string() takes a double char pointer
   and prints each string in the given array. */
void print_array_of_strings(char **a) {
  if (*a != NULL) {
    print_string(*a);
    a++;
  }

  while(*a != NULL) {
    print_char(',');
    print_char(' ');
    print_string(*a);
    a++;
  }

  print_char('\n');
}

/* print_string() takes a char pointer and prints the
   string contained within. */
void print_string(char *s) {
  if (*s == '\0') {
    return;
  }
  else {
    print_char(*s);
    s++;
    print_string(s);
  }
}
