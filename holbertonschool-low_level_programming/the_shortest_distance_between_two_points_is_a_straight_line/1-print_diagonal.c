int print_char(char);

/* prints a diagonal line the length of n */
void print_diagonal(int n) {
  int i, i2;

  if (n <= 0) {
    print_char('\n');
  }

  for (i = 0, i2 = 0; i < n; i++) {
    i2 = i;
    while(i2-- > 0) {
      print_char(' ');
    }
    print_char('\\');
    print_char('\n');
  }
}
