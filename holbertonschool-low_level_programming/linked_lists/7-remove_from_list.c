#include <stdlib.h>
#include "list.h"

int list_size(List *);

void remove_from_list(List **list, int index) {
  List *prev, *next, *current;
  
  if (index >= 0 && *list != NULL) {
    current = *list;
    next = current->next;
    
    if (index > list_size(*list)) {
      return;
    }
    
    if (index == 0) {
      free(next->str);
      free(next);
      *list = NULL;
      return;
    }
    
    while (index && next) {
      prev = current;
      current = current->next;
      next = current->next;
      index--;
    }
    
    prev->next = next;
    free(current->str);
    free(current);
  }
}
  
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
