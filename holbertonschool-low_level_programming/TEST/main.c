#include <stdlib.h>
#include <stdio.h>

char **string_to_words(char *s);
void print_array_of_strings(char **a);

int main(void)
{
  char **w;

  char xxx[] = "./okay now what";

  w = string_to_words(xxx);

  if (w == NULL) {
    printf("ok now?");
  }
  
  

  
  print_array_of_strings(w);
  return (0);
}
