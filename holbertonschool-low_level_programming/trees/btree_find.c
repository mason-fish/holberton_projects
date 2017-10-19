#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

BTree *btree_find(BTree *tree, char *str)
{
  int diff;

  if (tree == NULL) {
    return NULL;
  }
  diff = strcmp(tree->str, str);
  if (diff == 0) {
    return tree;
  }
  if (diff > 0) {
    return btree_find(tree->right, str);
  }
  if (diff < 0) {
    return btree_find(tree->left, str);
  }
  return NULL;
}
