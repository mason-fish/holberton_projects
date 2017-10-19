/* This function will rotate the chars of a string
   by 13 places in the alphabet */
char *rot13(char *c) {
  int i;

  for (i = 0; c[i]; i++) {
    if (c[i] >= 65 && c[i] <= 122) {
      if ((c[i] > 77 && c[i] < 97) || (c[i] > 109 && c[i] < 123)) {
	c[i] -= 13;
      }
      else {
	c[i] += 13;
      }
    }     
  }
  return c;
}



