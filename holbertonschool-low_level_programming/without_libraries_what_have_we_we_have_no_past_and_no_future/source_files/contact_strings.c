#include <stdio.h>

/* concatenate two strings */
char *concat_strings(char *dest, const char *src) {
  int i;

  for (i = 0; *(dest + i); i++) {
    ;
  }
  while (*src) {
    *(dest + i) = *src++;
    i++;
  }

  *(dest + i) = '\0';
  
  return dest;
}
