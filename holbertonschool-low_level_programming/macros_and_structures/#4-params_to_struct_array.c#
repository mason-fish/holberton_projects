#include <stdio.h>
#include <stdlib.h>
#include "param_struct.h"
#include <string.h>

int get_length(char *c);
char *make_copy(char *c);
char **string_to_words(char *);
int count_words(char *);
int count_chars(char *);

struct Param *params_to_struct_array(int ac, char **av) {
  /* for each parameter (ac gives the amount) create a new
   struct that stores a pointer to the parameter (str), length 
   of the parameter, a copy of the string (copy), and a word table
  of the string (tab) */
  int i;
  struct Param *stru_arr;

  stru_arr = malloc(sizeof(struct Param) * (ac + 1));
  if (stru_arr == NULL) {
    return NULL;
  }

  for(i = 0; i < ac; i++) {
    stru_arr[i].str = av[i];
    stru_arr[i].length = get_length(av[i]);
    stru_arr[i].copy = make_copy(av[i]);
    stru_arr[i].tab = string_to_words(av[i]);
  }

  stru_arr[i].str = NULL;

  return stru_arr;
}

/* get_length() returns the length of a given string */
int get_length(char *c) {
  int i;
  
  for(i = 0; c[i] != '\0'; i++) {}
  
  return i;
}

/* make_copy() makes a copy of a string that is input and returns
   a pointer to that string */
char *make_copy(char *c) {
  char *c2;
  int i, i2;

  i = get_length(c);
  c2 = malloc(sizeof(char) * (i + 1));
  if (c2 == NULL) {
    return NULL;
  }

  i2 = 0;
  while(i2 < i) {
    c2[i2] = c[i2];
    i2++;
  }
  
  c2[i2] = '\0';
  
  return c2;
}



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
    if (*s != ' ' && *s != '\0') {
      ss[i2] = malloc(sizeof(char) * (count_chars(s) + 1));
      if (ss == NULL) {
        return NULL;
      }

      t = ss[i2];
      while(*s != ' ' && *s != '\0') {
	*t++ = *s++;
      }
      *t = '\0';
      
      while(*s == ' ' || *s == '\0') {
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
  while(*s1 != ' ' && *s1 != '\0') {
    s1++;
    i++;
  }

  return i;
}

/* count_words() counts how many words are in a string. A word must contain
   alphanumerical symbols only. */
int count_words(char *s) {
  int i;

  i = 0;
  while(*s != '\0') {
    if (*s != ' ') {
      i++;
    }
    while(*s != ' ' && *s != '\0') {
      s++;
    }
    while(*s == ' ' && *s != '\0') {
      s++;
    }
  }
  return i;
}
