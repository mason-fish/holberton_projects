#include <stdlib.h>

int **alloc_grid(int x, int y) {
  int *iPtr;
  int **iPPtr;
  int iy, ix;

  iPPtr = malloc(sizeof(iPtr) * y);
  if (iPPtr == NULL) {
    return NULL;
  }

  for (iy = 0; iy < y; iy++) {
    iPPtr[iy] = malloc(sizeof(int) * x);
    if (iPPtr[iy] == NULL) {
      return NULL;
    }
    for (ix = 0; ix < x; ix++) {
      iPPtr[iy][ix] = 0;
    }
  }

  return iPPtr;
}
