int shell_comp(char *s1, char *s2) {  
  if (*s1 == *s2 && *s1 != 0) {
    return shell_comp(s1 + 1, s2 + 1);
  }

  if (*s2 == '*') {
    if (s2[1] == 0) {
      return (1);
    }
    if (*s1 == *s2) {
      return shell_comp(s1 + 1, s2 + 2);
    }
    if (shell_comp(s1 + 1, s2)) {
      return (1);
    }
    else {
      return shell_comp(s1, s2 + 1);
    }
  }
  
  if (*s1 == 0 && *s2 == 0) {
    return (1);
  }
  return (0);
}
