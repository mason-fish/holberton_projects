#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

void btree_free(BTree *tree)
{
  if (tree == NULL) {
    return;
  }
  if (tree->right != NULL) {
    btree_free(tree->right);
  }
  if (tree->left != NULL) {
    btree_free(tree->left);
  }
  free(tree->str);
  free(tree);
}
