int print_char(char c); 
void print_number(int n);

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

void print_number(int n) {
  int i = 1;
  int temp;
  int mod = 1;
  if (n < 0) {
    print_char('-');
    mod = -1;
  }
  for(temp = n; temp > 9 || temp < -9; temp = temp / 10) {
    i++;
  }
  while(i) {
    int i2 = i--;
    temp = n;
    while(i2-- > 1) {
      temp /= 10;
    }
    print_char(((temp % 10) * mod + '0'));
  }
}
