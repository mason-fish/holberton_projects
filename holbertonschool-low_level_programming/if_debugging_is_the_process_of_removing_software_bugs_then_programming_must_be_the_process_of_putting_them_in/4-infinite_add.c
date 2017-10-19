/* This function adds two strings of numbers together
 * regardless of their size and returns the result. It 
 * will not work if the provided buffer size is too small,
 * however. 
*/
int find_size(char *);
char *infinite_add(char *, char *, char *, int);
int eval_to_single_digits(char *, int);
void reverse_string(char *, int);

#define CONVERT 48

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
  int ndx, i1, i2;  

  i1 = find_size(n1);
  i2 = find_size(n2);

  i1--;
  i2--;
  size_r--;

  for (ndx = 0; i1 >= 0 || i2 >= 0; ndx++, i1--, i2--) {
    if (ndx >= size_r) {
      return 0;
    } 
    if (i1 < 0) {
      r[ndx] = n2[i2];
    }
    if (i2 < 0) {
       r[ndx] = n1[i1];
    }
    if (i2 >= 0 && i1 >= 0) {
      r[ndx] = n1[i1] + n2[i2] - CONVERT;
    }
  } 
  
  if (ndx <= size_r) {
    r[ndx] = '\0';
  } 
  else {
    return 0;
  }

  if (eval_to_single_digits(r, size_r)) {
    return 0;
  }

  reverse_string(r, (find_size(r)));

  return r;
}

int find_size(char *cPtr) {
  int i;
  
  for (i = 0; *cPtr++; i++){}
  
  return i;
}

int eval_to_single_digits(char *r, int size_r) {
  int i;

  for (i = 0; r[i] != '\0' && i < size_r; i++) {
    if (r[i] > '9') {
      if ((i + 2) > size_r) {
	return 1;
      }
      else {
	r[i] -= 10;
	if (r[i+1] == '\0') {
          r[i+1] = '1';
          r[i+2] = '\0';
        }
        else {
          r[i+1]++;
        }
      } 
    } 
  }
  return 0;
}

void reverse_string(char *a, int n) {
  int ndx; 
  char temp;

  n--;

  for (ndx = 0; ndx <= (n / 2); ndx++) {
    temp = *(a + ndx);
    *(a + ndx) = *(a + (n - ndx));
    *(a + (n - ndx)) = temp;
  }

}
