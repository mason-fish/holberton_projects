#include <stdio.h>
#include <stdlib.h>
char **string_split(char *);
void print_tab(char **tab) {…}
void free_tab(char **tab) {…}

int main(void)
{
  char **tab;

  tab = string_split("Holberton School         #cisfun");
  print_tab(tab);
  free_tab(tab);
  return (0);
}
