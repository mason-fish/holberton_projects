#include "headers.h"

/* free_dl_list() recursively frees allocated memory
   of a linked list of 'Link' structs */
void free_dl_list(List *list)
{
  List *temp;

  if (list == NULL) {
    return;
  }
  temp = list->next;
  free(list->str);
  free(list);
  free_dl_list(temp);
}
