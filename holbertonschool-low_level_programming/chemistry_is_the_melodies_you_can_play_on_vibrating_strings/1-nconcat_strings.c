/* concatenate two strings by n bytes */
char *nconcat_strings(char *dest, const char *src, int n) {
  int i;

  for (i = 0; *(dest + i); i++) {
    ;
  }
  while (*src && n--) {
    *(dest + i) = *src++;
    i++;
  }

  *(dest + i) = '\0';
  
  return dest;
}
