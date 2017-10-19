#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char *str_dup_1(char *);
int list_size(List *);
int add_node_end(List **, char *);

/* insert_in_list creates a node, filled with given content, and inserts it
   into a given list at a given index number */
int insert_in_list(List **list, char *content, int index) {
  List *prev, *new, *next = *list;
  if (index >= list_size(*list)) {
    add_node_end(list, content);
    return (0);
  }
  if (index < 0) {
    return (1);
  }
  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }
  if (index == 0) {
    *list = new;
    new->next = next;
    new->str = str_dup_1(content);
    return (0);
  }
  while (index > 0 && next) {
    prev = next;
    next = next->next;
    index--;
  }
  new->next = next;
  new->str = str_dup_1(content);
  prev->next = new;
  return (0);
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


/* add_node_end() receives a string and a pointer to a list and will
   create a new node for that list, create a copy of the passed string
   and pass a reference to the new node, then finally the new node 
   will be added to the end of the list */
int add_node_end(List **list, char *content) {
  List *new, *last;
  
  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }
  
  new->str = str_dup_1(content);
  new->next = NULL;

  if (*list == NULL) {
    *list = new;
  }
  else {
    last = *list;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = new;
  }
  return (0);
}

/* str_dup_1() makes a copy of a string that is input and returns
   a pointer to that string */
char *str_dup_1(char *c) {
  char *c2;
  int i, i2;

  for(i = 0; c[i] != '\0'; i++) {}

  c2 = malloc(sizeof(char) * (i + 1));
  if (c2 == NULL) {
    return NULL;
  }

  i2 = 0;
  while(i2 < i) {
    c2[i2] = c[i2];
    i2++;
  }

  c2[i2] = '\0';

  return c2;
}
