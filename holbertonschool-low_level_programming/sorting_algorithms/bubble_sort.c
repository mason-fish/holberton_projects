/* bubble_sort() implements a bubble sort algrithm to sort an array of ints */
void bubble_sort(int *array, int size)
{
  int i, tmp, flag;

  i = flag = 0;
  while(i < (size - 1)) {
    if (array[i] > array[i + 1]) {
      tmp = array[i];
      array[i] = array[i + 1];
      array[i + 1] = tmp;
      flag = 1;
    }
    i++;
    if (i == (size - 1) && flag == 1) {
      i = 0;
      flag = 0;
    }
  }
}





