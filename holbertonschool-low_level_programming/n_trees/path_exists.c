#include "my_headers.h"

int path_exists(NTree *tree, char **path)
{
	if (path == NULL || *path == NULL) {
		return (1);
	}
	if (tree != NULL && strcmp(tree->str, *path) == 0) {
		path++;
	}
	while (tree != NULL && *path != NULL) {
		tree = find_match(tree->children, *path);
		if (tree == NULL) {
			return (0);
		}
		path++;
	}
	return (1);
}

NTree *find_match(List *list, char *match)
{
        while(list != NULL && list->node != NULL) {
                if (strcmp(list->node->str, match) == 0) {
                        return (list->node);
		}
                list = list->next;
        }
        return (NULL);
}
