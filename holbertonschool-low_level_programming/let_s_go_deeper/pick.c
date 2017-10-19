/* compare strings with wildcards. returns 1 if matches, 0 if no match*/
int shell_comp(char *s1, char *s2) {
  if (*s2 == '*' && *(s2 + 1) == '*') return shell_comp(s1, s2+1);

  if (*s2 == '*' && *s1 == 0) {
    if (*(s2 + 1) == 0 ) return 1;
    return 0;
  }

  if (*s2 == '*') {
    return (shell_comp(s1, s2+1) || shell_comp(s1 + 1, s2));
  }

  if (*s1 == 0 && *s2 == 0) return 1;
  if ((*s1 == 0 && *s2 != 0) || (*s1 != 0 && *s2 == 0)) return 0;
  if (*s1 != *s2) return 0;
  if (*s1 == *s2) return shell_comp(s1+1, s2+1);
  return 0;
}
