#include <stdlib.h>
#include "param_struct.h"
#include <stdio.h>

void free_params_structs_array(struct Param *array) {
  char **strP;
  int i;
  
  i = 0;
  while(array[i].str != NULL) {
    strP = array[i].tab;
    while(*strP != NULL) {
      free(*strP);
      strP++;
    }
    
    free(array[i].tab);
    free(array[i].copy);
    i++;
  }
  free(array);
}
