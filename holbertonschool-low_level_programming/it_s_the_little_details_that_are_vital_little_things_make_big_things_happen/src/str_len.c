/* return length of string */
int str_len(char *s) {
  int len;
  
  len = 0;

  while (*s++) {
    len++;
  }

  return len;
}
