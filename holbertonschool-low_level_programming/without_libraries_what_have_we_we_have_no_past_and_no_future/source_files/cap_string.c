/* capitalize first letter of each word that
comes after a space, newline, tab, or is simply
the first word of a string*/

char *cap_string(char *c) {
  int i;

  for (i = 0; c[i]; i++) {
    if (i == 0 && c[i] > 96 && c[i] < 123) {
      c[i++] -= 32;
    }
    
    if (c[i] == ' ' || c[i] == '\n' || c[i] == '\t') {
      if (c[i+1] > 96 && c[i+1] < 123) {
	c[++i] -= 32;
      }    
    }
  }
  
  return c;
}
