#include <stdio.h>
#include "list.h"

void sort_list(List **list, int (*cmp_func)(List *, List *))
{
  List *cur, *next;
  char *tmp;
  int flag;

  if (*list == NULL || (*list)->next == NULL) {
    return;
  }
  
  cur = *list;
  next = (*list)->next;
  flag = 0;
  while(next != NULL) {
    if ((*cmp_func)(cur, next) > 0) {
      tmp = cur->str;
      cur->str = next->str;
      next->str = tmp;
      flag = 1;
    }
    cur = cur->next;
    next = next->next;
    if (next == NULL && flag == 1) {
      cur = *list;
      next = (*list)->next;
      flag = 0;
    }
  }
}
