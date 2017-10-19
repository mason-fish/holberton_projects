#include <limits.h>

int printf(const char *format, ...);

int main(void)
{
  int len;
  unsigned int ui;
  void *addr;

  len = printf("INTEGER{%d}, STRING{%s}\n", 98, "I am a string");
  ui = (unsigned int)INT_MAX + 1;
  addr = &len;
  printf("previous length{%d}\n", len);
  printf("UNSIGNED INTEGER{%u}\n", ui);
  printf("UNSIGNED INTEGER{%u}\n", INT_MIN);
  len = printf("Octal{%o}\n", 100);
  printf("\n11?\t%d\n", len);
  len = printf("ADDRESS{%p}\n", addr);
  printf("\n10 + p?\t%d\n", len);
  printf("HEXADECIMAL{%X}\n", 94111);
  len = printf("HEXADECIMAL{%x}\n", 94111);
  printf("\n14 + x?\t%d\n", len);
  printf("UNKNOWN SPECIFIER{%Q}\n", len);
  return (0);
}
