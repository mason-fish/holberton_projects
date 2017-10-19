#include "my_headers.h"

void ntree_free(NTree *tree)
{
	if (tree == NULL)
		return;
	if (tree->children == NULL) {
		free(tree->str);
		free(tree);
		return;
	}
	ntree_list_free(tree->children);
	free(tree->str);
	free(tree);
}

void ntree_list_free(List *list)
{
	List *next_list;

	next_list = list;
	while (next_list != NULL) {
		list = next_list;
		if (list->node != NULL) {
			ntree_list_free(list->node->children);
			free(list->node->str);
			free(list->node);
		}
		next_list = list->next;
		free(list);
	}
}
