/* power() recursively multiplies x by itself y times */
int power(int x, int y) {
  if (y == 1) {
    return (x);
  } 
  if (y == 0) {
    return (1);
  }
  if (y < 0) {
    return (-1);
  }
  else {
    return (x * (power(x, y - 1)));
  }
}
