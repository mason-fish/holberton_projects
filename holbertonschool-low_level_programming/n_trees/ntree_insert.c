#include "my_headers.h"

int ntree_insert(NTree **tree, char **parents, char *data)
{
	NTree **insert;

	insert = find_insertion_point(tree, parents);
	if (add_node_to_list(insert, data) != 0) {
		return (1);
	}
	return (0);
}

NTree **find_insertion_point(NTree **root, char **str_list)
{
	NTree **searcher;
	if (*root == NULL) {
		return (root);
	}
	if (*str_list == NULL) {
		return (root);
	}
	if (strcmp(*str_list, (*root)->str) != 0) {
		return (NULL);
	}
	searcher = root;
	str_list++;
	while(*searcher != NULL && *str_list != NULL) {
		searcher = find_match_in_list((*searcher)->children, *str_list);
		if (*searcher == NULL) {
			return (NULL);
		}
		str_list++;
	}
	return (searcher);
}

int add_node_to_list(NTree **insert_node, char *data)
{
	List *new_list;
	NTree *new_node;

	new_node = malloc(sizeof(NTree));
	if (new_node == NULL) {
		return (1);
	}
	new_node->children = NULL;
	new_node->str = strdup(data);
	if (*insert_node == NULL) {
		*insert_node = new_node;
		return (0);
	}
	new_list = malloc(sizeof(List));
	if (new_list == NULL) {
		return (1);
	}
	new_list->node = new_node;
	if ((*insert_node)->children == NULL) {
		new_list->next = NULL;
		(*insert_node)->children = new_list;
		return (0);
	}
	new_list->next = (*insert_node)->children;
	(*insert_node)->children = new_list;
	return (0);
}

NTree **find_match_in_list(List *list, char *match)
{
	while(list != NULL && list->node != NULL) {
		if (strcmp(list->node->str, match) == 0) {
			return (&(list->node));
		}
		list = list->next;
	}
	return (NULL);
}
