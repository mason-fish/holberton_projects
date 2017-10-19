#include "headers.h"

/* free_cl_list() recursively frees allocated memory
   of a linked list of 'Link' structs */
void free_cl_list(List *list)
{
  List *flag, *temp;

  flag = list;
  list = list->next;
  while (list != flag) {
    temp = list->next;
    free(list->str);
    free(list);
    list = temp;
  }
  free(flag->str);
  free(flag);
}
