#include <stdio.h>
#include <stdlib.h>

int check_char(char);
char **string_to_words(char *);
int count_words(char *);
int count_chars(char *);

/* string_to_words() takes a string and places all the
   words into an array of strings. */
char **string_to_words(char *s) {
  int i, i2;
  char **ss;
  char *t;

  i = count_words(s);
  ss = malloc(sizeof(char *) * (i + 1));
  if (ss == NULL) {
    return NULL;
  }

  ss[i] = NULL;
  
  i2 = 0;
  while(i2 < i) {
    if (check_char(*s)) {
      ss[i2] = malloc(sizeof(char) * (count_chars(s) + 1)); 
      if (ss == NULL) {
	return NULL;
      }
            
      t = ss[i2];
      while(check_char(*s)) {
	*t++ = *s++;
      }
      *t = '\0';
      
      while(check_char(*s) == 0) {
	s++;
      }
    i2++;
    }
    else {
      s++;
    }
  }

  return ss;
}

/* count_chars() counts how many chars are in a string */
int count_chars(char *s1) {
  int i;

  i = 0;
  while(check_char(*s1++)) {
    i++;
  }

  return i;
}

/* check_char() checks if its input, a char, is alphanumerical or not */
int check_char(char c) {
  if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return (1);
  }
  else {
    return (0);
  }
}

/* count_words() counts how many words are in a string. A word must contain
   alphanumerical symbols only. */
int count_words(char *s) {
  int i;

  i = 0;
  while(*s != '\0') {
    if (check_char(*s)) {
      i++;
    }
    while(check_char(*s)) {
      s++;
    }
    while(check_char(*s) == 0 && *s != '\0') {
      s++;
    }
  }
  return i;
}
