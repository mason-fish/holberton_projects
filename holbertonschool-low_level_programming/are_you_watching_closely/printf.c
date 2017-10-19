#include "headers.h"

int printf(const char *format, ...)
{
        int i, i2, check, mod;
        va_list vargs;
        
        va_start(vargs, format);
        for(i = 0, i2 = 0, mod = 0; format[i] != '\0'; i++) {
                if(format[i] == '%') {
                        if(!(check = func_butt(format[++i], vargs))) {
                                printf("error: incomplete format specifier\n");
                                return (i + i2 - mod);
                        }
                        i2 += check;
                        mod += 2;
                }
                else {
                        print_char(format[i]);
                }
        }
        va_end(vargs);
        return (i + i2 - mod);
}

int func_butt(char c, va_list vargs)
{
        int i, i2;
        spec_stru spec_stru_arr[] = {
                                   {'d', &spec_func_di},
                                   {'i', &spec_func_di},
                                   {'c', &spec_func_c},
                                   {'o', &spec_func_o},
                                   {'u', &spec_func_u},
                                   {'x', &spec_func_x},
                                   {'X', &spec_func_X},
                                   {'s', &spec_func_s},
                                   {'p', &spec_func_p},
                                   {'%', &spec_func_perc},
                                   {'\0', NULL}
        };

        for(i2 = 0, i = 0; spec_stru_arr[i2].spec != '\0'; i2++) {
                if (spec_stru_arr[i2].spec == c) {
                        i = spec_stru_arr[i2].spec_func(vargs);
                        return i;
                }
        }

        return i;
}


/* SCRAPS */

/* rep = (char) va_arg(vargs, int); */
/* print_char(rep); */
/* i2++; */
