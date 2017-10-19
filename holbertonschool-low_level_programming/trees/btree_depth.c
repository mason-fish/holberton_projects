#include <stdio.h>
#include "tree.h"

int btree_depth(BTree *tree)
{
  int r;
  int l;

  r = 0;
  l = 0; 
  if (tree == NULL) {
    return (-1);
  }
  if (tree->right != NULL) {
    r = 1 + btree_depth(tree->right);
  }
  if (tree->left != NULL) {
    l = 1 + btree_depth(tree->left);
  }
  if (r > l) {
    return (r);
  }
  else {
    return (l);
  }
}
