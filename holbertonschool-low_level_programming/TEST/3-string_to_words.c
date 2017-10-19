#include <stdio.h>
#include <stdlib.h>

int count_char(char *);
int count_words(char *);
int check_char(char);
void split_strings(char *, char **);
void add_string(char *, char *, int);

char **string_to_words(char *s) {
  char **ss;
  int i;

  i = 0;

  i = count_words(s);
  ss = malloc(sizeof(char *) * i + 1);
  ss[i] = NULL;
  split_strings(s, ss);
  
  return ss; 
}

int count_char(char *s1) {
  if (check_char(*s1)) {
    return (1 + count_char(s1++));    
  }
  return (0);
}

int count_words(char *s) {
  if (*s == '\0') {
    return (1);
  }
  if (check_char(*s)) {
    return (count_words(s++));
  }
  else {
    if (check_char(s[-1])) {
      return (1 + count_words(s++));
    }
    else {
      return (count_words(s++));
    }
  }
}

int check_char(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return (1);
  }
  else {
    return (0);
  }
}

void split_strings(char *s, char **ss) {
  int i;

  i = 0;
 
  if (ss == NULL) {
    return;
  }
  else if (check_char(*s)) {
    i = count_char(s);
    ss = malloc(sizeof(char) * i + 1);
    add_string(s, *ss, i);    
    split_strings(&(s[i]), ss++);
  }
  else {
    split_strings(s++, ss);
  }
}

void add_string(char *s, char *ss, int i) {
  if (i) {
    *ss = *s;
    add_string(s++, ss++, i--); 
  }
  else {
    *ss = '\0';
  }
}
