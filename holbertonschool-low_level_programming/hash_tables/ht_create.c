#include "headers.h"

HashTable *ht_create(unsigned int size)
{
  HashTable *ht;
  unsigned int i;
  
  if (size < 1 || (ht = malloc(sizeof(HashTable))) == NULL) {
    return NULL;
  }
 
  if ( (ht->array = malloc(sizeof(List *) * size)) == NULL) {
    return NULL;
  }

  for(i = 0; i < size; i++) {
    ht->array[i] = NULL;
  }

  ht->size = size;

  return ht;
}

