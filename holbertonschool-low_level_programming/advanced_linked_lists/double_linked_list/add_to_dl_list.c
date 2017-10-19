#include "headers.h"
#include "list.h"

/* add a List node to the end of a double linked list */
int add_end_dl_list(List **list, char *str)
{
  List *new, *tail;

  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }

  new->str = strdup(str);
  new->next = NULL;

  if ((tail = get_tail(list)) == NULL) {
    *list = new;
    new->prev = NULL;
  }
  else {
    tail->next = new;
    new->prev = tail;
  }

  return (0);
}

/* add a List node to the beginning of a double linked list */
int add_begin_dl_list(List **list, char *str)
{
  List *new;

  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }

  new->str = strdup(str);
  new->prev = NULL;

  if (*list == NULL) {
    *list = new; 
    new->next = NULL;
  }
  else {
    new->next = *list;
    (*list)->prev = new;
    *list = new;
  }

  return(0);
}

/* get_tail() receives a null terminated linked list and returns the final node */
List *get_tail(List **list)
{
  List *cursor;

  cursor = *list;

  while (cursor != NULL && cursor->next != NULL) {
    cursor = cursor->next;
  }

  return cursor;
}
