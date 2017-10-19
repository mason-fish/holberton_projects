int printf(const char *format, ...);

int main(void)
{
  int x;

  x = printf("12345 %d\n %s", 7890, "16?\n");
  printf("%d", x);
  return (x);
}

