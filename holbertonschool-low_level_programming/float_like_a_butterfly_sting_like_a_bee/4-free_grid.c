#include <stdlib.h>

void free_grid(int **iPPtr, int y) {
  int iy;

  for (iy = 0; iy < y; iy++) {
    free(iPPtr[iy]);
  }
  
  free(iPPtr);
}
