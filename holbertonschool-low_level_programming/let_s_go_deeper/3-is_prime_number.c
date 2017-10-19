int check_prime(int, int);

int is_prime_number(int n) {
  return check_prime(n, 2);
}

int check_prime(int x, int y) {
  if (x <= 1) {
    return (0);
  }
  if (x % y == 0) {
    return (0);
  }
  if (y >= x/2) {
    return (1);
  }
  return check_prime(x, y+1);
}
