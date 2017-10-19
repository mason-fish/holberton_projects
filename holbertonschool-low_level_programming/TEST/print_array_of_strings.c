#include <stdio.h>
#include <unistd.h>

void print_string(char *);

void print_array_of_strings(char **a) {
  if (*a == NULL) {
    printf("\n");
  }
  else {
    print_string(*a);
    printf(" ");
    a++;
    print_array_of_strings(a);
  }
}

void print_string(char *s) {
  if (*s == '\0') {
    return;
  }
  else {
    printf("%c", *s);
    s++;
    print_string(s);
  }
}
