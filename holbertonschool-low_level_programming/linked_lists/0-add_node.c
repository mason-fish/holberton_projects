#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char *str_dup(char *);

/* add_node() receives a string and a pointer to a list and will
   create a new node for that list, create a copy of the passed string
   and pass a reference to the new node, then finally the new node 
   will be added to the beginning of the list */
int add_node(List **list, char *content) {
  List *new;
  
  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }
  
  new->str = str_dup(content);
  new->next = *list;
  *list = new;

  return (0);
}

/* str_dup() makes a copy of a string that is input and returns
   a pointer to that string */
char *str_dup(char *c) {
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
