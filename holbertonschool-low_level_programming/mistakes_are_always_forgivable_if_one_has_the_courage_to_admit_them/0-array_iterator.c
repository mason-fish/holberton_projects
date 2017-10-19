void array_iterator(int *arr, int n, void (*func)(int)) {
  if (n) {
    func(*arr);
    array_iterator(++arr, --n, func);
  }
}
