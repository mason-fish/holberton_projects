#include "headers.h"

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
  List *n;
  unsigned int ndx;
  
  if (key == NULL) {
    return (1);    
  }

  ndx = hash(key, hashtable->size);

  if ( (n = search_ll(hashtable->array[ndx], key)) != NULL ) {
    free(n->value);
    n->value = strdup(value);
    return (0);
  } 

  if ( (n = malloc(sizeof(List))) == NULL ) {
    return (1);
  }

  n->key = strdup(key);
  n->value = strdup(value);
  n->next = hashtable->array[ndx];
  hashtable->array[ndx] = n;
  
  return (0);
}

List *search_ll(List *list, const char *key)
{
  while(list != NULL) {
    if ( (bin_strcmp(list->key, key)) == 0) {
      return list;
    }
    list = list->next;
  }

  return NULL;
}

int bin_strcmp(const char *str1, const char *str2)
{
  int i;

  for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return (1);
    }
  }
  if (str1[i] == str2[i]) {
    return (0);
  }
  return (1);
}
