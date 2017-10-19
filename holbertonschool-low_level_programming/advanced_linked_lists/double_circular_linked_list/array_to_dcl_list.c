#include "headers.h"
#include "list.h"

/* array_to_dcl_list() accepts an array of strings and stores
   each string into a node in a linked list */
List *array_to_dcl_list(char **array)
{
  List *list;

  list = NULL;
  while (*array != NULL) {
    if(add_end_dcl_list(&list, *array)) {
      return NULL;
    }
    array++;
  }

  return list;
}
