#include <stdio.h>

int count_chars(char *);
int check_char(char);

int main(void) {
  char str[] = "eight!";

  printf("%d", count_chars(str));
  
  return (0);
}

int count_chars(char *s1) {
  int i;

  i = 0;
  while (check_char(*s1++)) {
    i++;
  }

  return i;
}

int check_char(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return (1);
  }
  else {
    return (0);
  }
}
