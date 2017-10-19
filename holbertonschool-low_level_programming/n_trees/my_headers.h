#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* task 0 */
int ntree_insert(NTree **tree, char **parents, char *data);
NTree **find_insertion_point(NTree **root, char **str_list);
int add_node_to_list(NTree **insert_node, char *data);
NTree **find_match_in_list(List *list, char *match);

/* task 1 */
int path_exists(NTree *tree, char **path);
NTree *find_match(List *list, char *match);

/* task 2 */
void ntree_free(NTree *tree);
void ntree_list_free(List *list);

/* helper functions */
char **string_split(const char *string, char separator);
void free_str_array(char **array);
void ntree_print(NTree *tree);
void ntree_free(NTree *tree);
