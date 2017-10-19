/* convert chars in a string to all uppercase */
char *uppercase_string(char *c) {
  int i;

  for (i = 0; c[i]; i++) {
    if (c[i] > 96 && c[i] < 123) {
      c[i] -= 32;
    }
  }

  return c; 
}
