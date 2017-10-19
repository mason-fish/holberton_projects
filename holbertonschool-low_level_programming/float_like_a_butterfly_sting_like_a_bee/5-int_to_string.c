#include <stdlib.h>

int find_size(int);

char *int_to_string(int x) {
  int size, sign;
  char *cPtr;

  size = find_size(x);

  if (x < 0) {
    sign = -1;
    size++;
  }
  else {
    sign = 1;
  }

  cPtr = malloc(sizeof(char) * size + 1);
  if (cPtr == NULL) {
    return NULL;
  }

  cPtr[size--] = '\0';

  while (size >= 0) {
    if (size == 0 && sign == -1) {
      cPtr[size] = '-';
      size--;
    }
    else {
      cPtr[size] = '0' + ((x % 10) * sign);
      size--;
      x /= 10;
    }
  }

  return cPtr;
}

int find_size(int x) {
  int i;

  i = 1;
  while (x / 10) {
    i++;
    x /= 10;
  }

  return i;
}
