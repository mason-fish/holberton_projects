int print_char(char c); 
void print_number(int);

/* prints out an array of ints seperated by commas */
void print_array(int *a, int n) {
  int i;

  for (i = 0; i < n; i++) {
    print_number(a[i]);
    if (i == (n-1)) {
      break;
    }
    print_char(',');
    print_char(' ');
  }
  print_char('\n');
}
