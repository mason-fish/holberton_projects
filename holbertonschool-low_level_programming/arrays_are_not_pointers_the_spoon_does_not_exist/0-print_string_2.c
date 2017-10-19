int print_char(char c);

/* this function will print every other char in a string */
void print_string_2(char *str) {
  while (*str) {
    print_char(*str++);
    if (*str) {
      str++;
    }
  }
}
