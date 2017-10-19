int advanced_search(int *arr, int size, int (*func)(int)) {
  int i;
  
  for(i = 0; i < size; i++) {
    if (func(arr[i])) {
      return (i);
    }
  }

  return (-1);
}
