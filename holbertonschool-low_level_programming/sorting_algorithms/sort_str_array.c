#include <string.h>
#include <stdio.h>

int partition(char **, int);
void quick_sort_str(char **, int);

void sort_str_array(char **array)
{
  int size;

  for(size = 0; array[size] != NULL; size++) {}

  quick_sort_str(array, size);
}

void quick_sort_str(char **array, int size)
{
  int piv;

  if (size > 1) {
    piv = partition(array, size);
    quick_sort_str(array, piv);
    quick_sort_str(&(array[piv + 1]), (size - piv - 1));
  }
}

int partition(char **array, int size)
{
  int i, piv;
  char *tmp;

  i = piv = (size - 1);
  while(i--) {
    if (strcmp(array[i], array[piv]) > 0) {
      if (strcmp(array[piv - 1], array[piv]) != 0) {
        tmp = array[piv - 1];
        array[piv - 1] = array[i];
        array[i] = tmp;
      }
      tmp = array[piv - 1];
      array[piv - 1] = array[piv];
      array[piv] = tmp;
      piv = i;
    }
  }

  return (piv);
}
