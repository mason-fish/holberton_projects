#include <unistd.h>
#include <stdlib.h>

int print_char(char);
int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char c))(int, int);
void print_number(int);

int main(int argc, char *argv[]) {
  int x, y, z;
  char c;
 
  while (argc == 4 && argv[2][1] == '\0') {
    c = argv[2][0];
    while (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
      x = atoi(argv[1]);
      y = atoi(argv[3]);
      c = argv[2][0];
      
      z = get_op_func(c)(x,y);
      
      print_number(z);
      print_char('\n');
      return (0);
    }
    return (1);
  }
  return (1);
}
    
int print_char(char c) {
  return (write(1, &c, 1));
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
