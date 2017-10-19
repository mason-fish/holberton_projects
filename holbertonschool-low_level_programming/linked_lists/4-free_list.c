#include <stdlib.h>
#include "list.h"

void free_list(List *list) {
  List *temp;

  while(list != NULL) {
    temp = list->next;

    free(list->str);
    free(list);
    list = temp;
  }
}
