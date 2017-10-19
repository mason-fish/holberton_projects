#include <stdio.h>
#include "string.c"

int main(void) {
  char str[] = "I am fi94ve words lon1g          s9IXNOW!";

  printf("%d\n", count_words(str));

  return (0);
}
