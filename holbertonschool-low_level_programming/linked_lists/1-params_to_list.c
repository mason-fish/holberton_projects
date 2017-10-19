#include <stdlib.h>
#include "list.h"

char *str_dup(char *);
int add_node(List **, char *);

/* params_to_list() takes command line arguments as inputs and stores
   each string in a struct node within a linked list */
List *params_to_list(int ac, char **av) {
  List *head;
  int i;

  head = NULL;  
  
  for(i = 0; i < ac; i++) {
    if(add_node(&head, av[i]) == 1) {
      return NULL;
    }
  }

  return head;
}

/* add_node() receives a string and a pointer to a list and will
   create a new node for that list, create a copy of the passed string
   and pass a reference to the new node, then finally the new node 
   will be added to the end of the list */
int add_node(List **list, char *content) {
  List *new, *last;
  
  new = malloc(sizeof(List));
  if (new == NULL) {
    return (1);
  }
  
  new->str = str_dup(content);
  new->next = NULL;

  if (*list == NULL) {
    *list = new;
  }
  else {
    last = *list;
    while(last->next != NULL) {
      last = last->next;
    }

    last->next = new;
  }

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
