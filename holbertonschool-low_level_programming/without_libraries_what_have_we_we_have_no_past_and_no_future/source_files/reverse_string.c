#include <stdio.h>

/* using a pointer and a few temp variables, reverses a string */
void reverse_string(char *s) {
  int size, ndx;
  char temp;

  size = 0;

  while (*(s + size)) {
    size++;
  }
  
  size-=1;

  for (ndx = 0; ndx <= (size / 2); ndx++) {
    temp = *(s + ndx);
    *(s + ndx) = *(s + (size - ndx));
    *(s + (size - ndx)) = temp;
  }
}
