#include "headers.h"
#include "list.h"

int add_end_cl_list(List **list, char *str)
{
  List *new, *tail;

  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }

  new->str = strdup(str);

  if (*list == NULL) {
    *list = new;
    new->next = new;
  }
  else {
    tail = find_tail(*list);
    tail->next = new;
    new->next = *list;
  }
  return (0);
}

int add_begin_cl_list(List **list, char *str)
{
  List *new, *tail;

  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }

  new->str = strdup(str);

  if (*list == NULL) {
    *list = new;
    new->next = new;
  }
  else {
    tail = find_tail(*list);
    tail->next = new;
    new->next = *list;
    *list = new;
  }

  return (0);
}

List *find_tail(List *list)
{
  List *cursor;
  
  cursor = list;

  while (cursor->next != list) {
    cursor = cursor->next;
  }

  return cursor;
}
