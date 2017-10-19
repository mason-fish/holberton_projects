#include <stdio.h>

int check_pal(char *, int);
int get_size(char *);
int is_palindrome(char *s);

int main(void)
{
  int r;

  r = is_palindrome("level");
  printf("%d\n", r);
  r = is_palindrome("redder");
  printf("%d\n", r);
  r = is_palindrome("holberton");
  printf("%d\n", r);
  r = is_palindrome("step on no pets");
  printf("%d\n", r);
  return (0);
}

int is_palindrome(char *s) {
  int size;
  size = get_size(s) - 1;
  return check_pal(s, size);
}

int check_pal(char *s, int size) {
  if (size < 0) {
    return (1);
  }
  if (*s != s[size]) {
    return (0);
  }
  if (*s == s[size]) {
    return check_pal(s + 1, size - 2);
  }
  return (0);
}

int get_size(char *s) {
  if (*s == 0) {
    return (0);
  }
  return (1 + get_size(s + 1));
}
