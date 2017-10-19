/* replace specific letters in a string to numbers */
char *leet(char *c) {
  int i;

  for (i = 0; c[i]; i++) {
    
    switch(c[i]) {  
      case 'a':
      case 'A':
        c[i] = '4';
        break;
      case 'e':
      case 'E':
        c[i] = '3';
        break;
      case 'o':
      case 'O':
        c[i] = '0';
        break;
      case 't':
      case 'T':
        c[i] = '7';
        break;
      case 'l':
      case 'L':
        c[i] = '1';
        break;
    }
  }

  return c;
}
