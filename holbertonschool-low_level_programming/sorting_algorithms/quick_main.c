void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {-1, 0, 402, 94111, 98, 12, 1024, 1, 3090972, -5812362};

  print_array(array, 10);
  quick_sort(array, 10);
  print_array(array, 10);
  return (0);
}
