#include <stdio.h>
#include <stdlib.h>
#include "list.h"	

/* rev_list() reverses a linked list's node order */
void rev_list(List **list) {
  List *prev, *current, *next;
  prev = NULL;
  current = *list;

  while (current != NULL) {
    next = current->next;  
    current->next = prev;   
    prev = current;
    current = next;
  }

  *list = prev;
}
