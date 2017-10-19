#include <stdlib.h>
#include "str_struct.h"

/* string_to_struct stores a string and that string's
size into a struct.
 */
struct String *string_to_struct(char *str) {
  int i;
  char *strcpy;

  struct String *xxx;

  xxx = malloc(sizeof(struct String));
  if (xxx == NULL) {
    return NULL;
  }

  i = 0;
  while(str[i] != '\0') {
    i++;
  }
  
  strcpy = malloc(sizeof(char) * (i + 1));
  if (strcpy == NULL) {
    return NULL;
  }

  i = 0;
  while(str[i] != '\0') {
    strcpy[i] = str[i];
    i++;
  }
  strcpy[i] = '\0';

  xxx->str = strcpy;  
  xxx->length = i;
  
  return xxx;
}
