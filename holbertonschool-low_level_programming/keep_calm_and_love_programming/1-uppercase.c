/* uppercase TAKES A CHAR AND CONVERTS IT
 * TO UPPERCASE, IF IT ISN'T ALREADY.
 */
char uppercase(char c) {
  if (c >= 97 && c <= 122) {
    c -= 32;
  }
  return c;
}
