#include <stdio.h>

void print_spaces(int);
void print_body(int);

void triangles_in_the_term(int len, int amt) {
  int i, i2;
  
  while(amt-- > 0) {
    i = len;
    i2 = 1;
    while(i-- > 0) {
      print_spaces(i);
      print_body(i2);
      printf("\n");
      i2+=2;
    }
  }
}

void print_spaces(int len) {
  while(len-- > 0) {
    printf(" ");
  }
}

void print_body(int len) {
  while(len-- > 0) {
    printf("*");
  }
}
