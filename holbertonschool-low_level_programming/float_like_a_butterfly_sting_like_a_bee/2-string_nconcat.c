#include <stdlib.h>

int count_string(char *);

char *string_nconcat(char *s1, char *s2, int n) {
  int len;
  char *cPtr;

  if (n < 0) {
    n = 0;
  }

  len = count_string(s1) + n;

  cPtr = malloc(sizeof(char) * len + 1);

  if (cPtr == NULL) {
    return NULL;
  }

  while (*s1 != '\0') {
    *cPtr++ = *s1++;
  }

  while (*s2 != '\0' && n > 0) {
    *cPtr++ = *s2++;
    n--;
  }

  *cPtr = '\0';

  return &(cPtr[-len]);
}

int count_string(char *cPtr) {
  int i;
  
  for (i = 0; cPtr[i] != '\0'; i++) {}

  return i;
}
