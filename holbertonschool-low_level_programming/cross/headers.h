#include <unistd.h>

/* cross.c */
void print_top(int);
void print_middle(int);
void print_bottom(int);
void print_line(char, char, int, int);

/* print_char.c */
int print_char(char);

/* helper_func.c */
int string_to_integer(char*);
void cut_string(char*, int, char*);
int make_number(char*, int, int);
int expon(int);
