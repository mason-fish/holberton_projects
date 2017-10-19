#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int btree_insert(BTree **, char *);

BTree *array_to_btree(char **array)
{
  BTree *root;
  int i;
  int check;

  if (array == NULL) {
    return NULL;
  }
  root = NULL;
  for (i = 0; array[i] != NULL; i++) {
    check = btree_insert(&root, array[i]);
    if (check == 1) {
      return NULL;
    }
  }
  return root;
}
