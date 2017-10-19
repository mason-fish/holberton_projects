#include "headers.h"

void ht_free(HashTable *hashtable)
{
  unsigned int i;

  if (hashtable == NULL) {
    return;
  }

  for (i = 0; i < hashtable->size; i++) {
    ll_free(hashtable->array[i]);
    /*free(hashtable->array[i]);*/
  }

  free(hashtable->array);
  free(hashtable);
}

void ll_free(List *list)
{  
  List *temp;
  if (list == NULL) {
    return;
  }
  
  temp = list->next;
  free(list->key);
  free(list->value);
  free(list);
  ll_free(temp);
}
