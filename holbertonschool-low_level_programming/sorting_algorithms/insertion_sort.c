void insertion_sort(int *array, int size)
{
  int i, j, tmp;

  i = j = 0;
  while(i < (size - 1)) {
    j = i;
    while(array[j] > array[j + 1] && j >= 0) {
      tmp = array[j + 1];
      array[j + 1] = array[j];
      array[j] = tmp;
      j--;
    }
    i++;
  }
}
