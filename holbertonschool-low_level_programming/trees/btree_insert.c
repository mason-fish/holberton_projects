#include "tree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int btree_insert(BTree **tree, char *data) 
{
  BTree *new;

  if (*tree == NULL) {
    new = malloc(sizeof(BTree));
    if (new == NULL) {
      return (1);
    }
    new->str = strdup(data);
    new->left = NULL;
    new->right = NULL;
    *tree = new;
    return (0);
  }
  else {
    if (strcmp((*tree)->str, data) >= 0) {
      return (btree_insert(&((*tree)->right), data));
    }
    else {
      return (btree_insert(&((*tree)->left), data));
    }
  }
}
