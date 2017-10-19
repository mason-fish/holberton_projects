#include <stdio.h>
void reverse_string(char *s);

int main(void)
{
  char s[11] = "0123456789";

  printf("%s\n", s);
  reverse_string(s);
  printf("%s\n", s);
  return (0);
}
