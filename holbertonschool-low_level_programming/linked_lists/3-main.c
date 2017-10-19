#include <stdlib.h>
#include "list.h"

int add_node(List **list, char *str);
void print_list(List *list);

int main(void)
{
  List *list;

  list = NULL;
  if (add_node(&list, "I am number one") == 1)
    return (1);
  if (add_node(&list, "the number two") == 1)
    return (1);
  if (add_node(&list, "and three") == 1)
    return (1);
  if (add_node(&list, "this is four") == 1)
    return (1);
  print_list(list);
  return (0);
}
