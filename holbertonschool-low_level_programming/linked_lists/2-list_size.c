#include "list.h"
#include <stdlib.h>

/* list_size() takes a list and returns the amount of nodes
   contained within. */
int list_size(List *list) {
  int i;

  i = 0;
  if (list == NULL) {
    return i;
  }

  i++;
  while(list->next != NULL) {
    list = list->next;
    i++;
  }

  return i;
}
