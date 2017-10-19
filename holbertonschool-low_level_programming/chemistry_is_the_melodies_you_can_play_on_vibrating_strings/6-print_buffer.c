void ripple(char*);
void increment_memory(char*);
void print_buffer(char*, int);
void convert_to_hex(char*, int);
void print_mod_string(char*, int);
int print_char(char c);

/* this function takes a string of chars and
displays a buffer listing the relative memory
location (in hex), the hex ascii code for each
char, and then displays the actual printable
chars in sets of 10 per line. */
void convert_to_hex(char *b, int size) {
  char *c; 
  char res[] = "00";
  int s,d;

  c = b;
  s = 0;
  d = 0;
  if (size < 10) {
    s = 10 - size;
  }

  while (size-- > 0) {
    res[0] = *c / 16 + '0';
    res[1] = *c % 16 + '0';
    if (res[0] > '9') {
      res[0] += 39;
    } 
    if (res[1] > '9') {
      res[1] += 39;
    }
    print_char(res[0]);
    print_char(res[1]);
    d++;
    if (d % 2 == 0) {
      print_char(' ');
      d = 0;
    }
    c++;
  }
  while (s-- > 0) {
    print_char(' ');
    print_char(' ');
    d++;
    if (d % 2 == 0) {
      print_char(' ');
      d = 0;
    }
  }  
}

void print_buffer(char *b, int size) {
  char memory[] = "00000000: ";
  int s, i;
  
  while (size > 0) {
    if ((size - 10) >= 0) {
      s = 10;
    } 
    else {
      s = size;
    }
    for (i = 0; memory[i]; i++) {
      print_char(memory[i]);  
    }
    convert_to_hex(b, s);
    print_mod_string(b, s);
    increment_memory(memory);
    size -= 10;
    b += 10;
  }
}


void print_mod_string(char *c,int size) {
   while (size--) {
    if (*c > 31 && *c < 127) {
      print_char(*c);
    }
    else {
      print_char('.');
    }
    c++;
  }
  print_char('\n');
}

void increment_memory(char *c) {
  int i;

  for (i = 7; i >= 0; i--) {
    if (c[i] >= 'a' && c[i] <= 'f') {
      c[i] -= 39;
    }
  }

  if ((*(c + 7) + 10) > '?') {
    *(c + 7) -= 6;
    ripple((c + 6));
  }
  else {
    *(c + 7) += 10;
  }
  for (i = 0; i < 8; i++) {
    if (*c > '9') {
      *c += 39;
    }
    c++;
  }
}

void ripple(char *c) {
  if ((*c + 1) > '?') {
    *c = '0';
    ripple(&(c[-1]));
  }
  else {
    (*c)++;
  }
}

