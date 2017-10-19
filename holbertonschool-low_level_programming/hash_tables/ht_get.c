#include "headers.h"

char *ht_get(HashTable *hashtable, const char *key)
{
  List *list;
  unsigned int ndx;

  ndx = hash(key, hashtable->size);

  if ( (list = search_ll(hashtable->array[ndx], key)) == NULL ) {
    return NULL;
  }

  return list->value;
}
