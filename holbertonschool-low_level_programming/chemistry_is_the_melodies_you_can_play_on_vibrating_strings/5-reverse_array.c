/* takes an array of ints and prints it in retrograde */
void reverse_array(int *a, int n) {
  int ndx, temp;
    
  n--;

  for (ndx = 0; ndx <= (n / 2); ndx++) {
    temp = *(a + ndx);
    *(a + ndx) = *(a + (n - ndx));
    *(a + (n - ndx)) = temp;
  }

}

