/* imitates string.h lbrary's strcpy */
char *string_copy(char *dest, const char *src) {
  int i;

  for (i = 0; *(src + i); i++) {
    *(dest + i) = *(src + i); 
  }
  
  return dest;
}
