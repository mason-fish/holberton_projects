/* imitates strncpy function */
char *string_ncopy(char *dest, const char *src, int n) {
  int i;

  for (i = 0; *(src + i) && i < n; i++) {
    *(dest + i) = *(src + i);
  }

  while (i < n) {
    *(dest + i) = '\0';
    i++;
  }
  
  return dest;
}
