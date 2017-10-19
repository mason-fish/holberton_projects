void insertion_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {-0, -1};

  print_array(array, 2);
  insertion_sort(array, 2);
  print_array(array, 2);
  return (0);
}
