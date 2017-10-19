/* square_root() passes an int to count_square()
so that it may find its square root with an additional
parameter */
int count_square(int, int);

int square_root(int n) {
  return count_square(n, 1);
}

int count_square(int x, int y) {
  if (x < 0) {
    return (-1);
  }
  if (y * y == x) {
    return (y);
  }
  if (y * y > x) {
    return (-1);
  }
  return count_square(x, y + 1);
}
