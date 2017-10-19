int partition(int *, int);

void quick_sort(int *array, int size)
{
  int piv;

  if (size > 1) {
    piv = partition(array, size);
    quick_sort(array, piv);
    quick_sort(&(array[piv + 1]), (size - piv - 1));
  }
}

int partition(int *array, int size)
{
  int i, piv, tmp;

  i = piv = (size - 1);
  while(i--) {
    if (array[i] > array[piv]) {
      if (array[piv - 1] != array[piv]) {
	tmp = array[piv - 1];
	array[piv - 1] = array[i];
	array[i] = tmp;
      }
      tmp = array[piv - 1];
      array[piv - 1] = array[piv];
      array[piv] = tmp;
      piv = i;
    }
  }

  return (piv);
}
