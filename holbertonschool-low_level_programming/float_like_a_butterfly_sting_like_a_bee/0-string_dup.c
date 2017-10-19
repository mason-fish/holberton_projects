#include <stdlib.h>

char *string_dup(char *str) {
  int i;
  char *cPtr;

  for (i = 0; str[i] != '\0'; i++) {}
  
  cPtr = malloc(sizeof(char) * i);
  if (cPtr == NULL) {
    return NULL;
  }
 
  while (i--) {
    cPtr[i] = str[i]; 
  } 

  return cPtr;
}
