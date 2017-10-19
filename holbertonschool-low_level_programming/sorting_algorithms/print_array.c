int print_char(char);
void print_number(int);

void print_array(int *array, int size)
{
  int i;

  i = 0;
  while (i < size) {
    print_number(array[i]);
    if (i < (size - 1)) {
      print_char(',');
      print_char(' ');
    }
    i++;
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
