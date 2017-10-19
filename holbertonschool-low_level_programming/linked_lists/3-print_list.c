#include <stdlib.h>
#include "list.h"

int print_char(char);
void print_list_struct_string(List *);

void print_list(List *list) {
  List *temp;

  if (list != NULL) {
    temp = list;
    print_list_struct_string(temp);
    temp = temp->next;

    while (temp != NULL) {
      print_char(',');
      print_char(' ');
      print_list_struct_string(temp);
      temp = temp->next;
    }
  }

  print_char('\n');
}

void print_list_struct_string(List *strP) {
  int i;

  i = 0;
  while (strP->str[i] != '\0') {
    print_char(strP->str[i]);
    i++;
  }
}
