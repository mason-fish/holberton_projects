#include <unistd.h>
#include <stdarg.h>

typedef struct spec_stru {
  char spec;
  int (*spec_func)(va_list args);
} spec_stru;

int printf(const char *format, ...);

int print_char(char);
int print_number(long int);

int func_butt(char, va_list);

int spec_func_di(va_list);
int spec_func_c(va_list);
int spec_func_o(va_list);
int spec_func_u(va_list);
int spec_func_x(va_list);
int spec_func_X(va_list);
int spec_func_s(va_list);
int spec_func_p(va_list);
int spec_func_perc(va_list);

