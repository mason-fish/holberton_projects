#include <stdlib.h>

int count_string(char *);

char *string_concat(char *s1, char *s2) {
  int len;
  char *cPtr;

  len = count_string(s1) + count_string(s2);

  cPtr = malloc(sizeof(char) * len + 1);

  if (cPtr == NULL) {
    return NULL;
  }

  while (*s1 != '\0') {
    *cPtr++ = *s1++;
  }

  while (*s2 != '\0') {
    *cPtr++ = *s2++;
  }

  *cPtr = '\0';

  return &(cPtr[-len]);
}

int count_string(char *cPtr) {
  int i;
  
  for (i = 0; cPtr[i] != '\0'; i++) {}

  return i;
}
