#include "headers.h"
#include "list.h"

int add_end_dcl_list(List **list, char *str)
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
    new->prev = new;
  }
  else {
    tail = (*list)->prev;
    (*list)->prev = new;
    tail->next = new;
    new->next = *list;
    new->prev = tail;
  }
  return (0);
}

int add_begin_dcl_list(List **list, char *str)
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
    new->prev = new;
  }
  else {
    tail = (*list)->prev;
    tail->next = new;
    new->next = *list;
    new->prev = tail;
    *list = new;
  }

  return (0);
}
