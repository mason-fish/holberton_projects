/* swap the two target's values between two pointers */
void swap_int(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
