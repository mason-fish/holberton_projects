#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_char(char);
HashTable *ht_create(unsigned int);
int ht_put(HashTable *, const char *, const char *);
char *ht_get(HashTable *, const char *);
void ht_free(HashTable *);
List *search_ll(List *, const char *);
int bin_strcmp(const char *, const char *);
void ll_free(List *);
