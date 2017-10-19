#include "headers.h"

int main(void)
{
  HashTable *ht;
  ht = ht_create(5);

  ht_put(ht, "Mason", "Fish");
  ht_put(ht, "Emma", "King");
  ht_put(ht, "Joe", "Green");
  ht_put(ht, "Kris", "Bredemeier");
  ht_put(ht, "John", "Spence");
  ht_put(ht, "Jon", "Serrano");
  ht_put(ht, "Dora", "Korpar");
  ht_put(ht, "Mason1", "Fish");
  ht_put(ht, "Emm1a", "King");
  ht_put(ht, "Jo2e", "Green");
  ht_put(ht, "Kris", "Bredemeier");
  ht_put(ht, "Joh3", "Spence");
  ht_put(ht, "Jon4", "Serrano");
  ht_put(ht, "Dora", "Korpar2");

  ht_free(ht);
  return (0);
}
