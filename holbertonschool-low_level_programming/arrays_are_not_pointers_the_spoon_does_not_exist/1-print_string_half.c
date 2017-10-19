int print_char(char c);

/* this function will print the second half of a string */
void print_string_half(char *str) {
  int i;
  
  for (i = 0; *str++; i++) {}
  for (i /= -2, str--; i; i++) {
    print_char(str[i]);
  }   
}
