#include <stdio.h>

void print_array_str(char **arr)
{
  while(*arr != NULL) {
    printf("%s", *arr);
    if (*(arr + 1) != NULL) {
      printf(", ");
    }
    arr++;
  }
  printf("\n");
}
