#include "headers.h"

int spec_func_c(va_list args)
{
        char c;
        int i;
        c = (char) va_arg(args, int);
        i = print_char(c);
        return i;
}

int spec_func_s(va_list args)
{
        int i;
        char *str;
        
        str = va_arg(args, char *);
        for(i = 0; str[i] != '\0'; i++) {
                print_char(str[i]); 
        }
        return i;
}

int spec_func_p(va_list args)
{
        unsigned long int point_addr, mod;
        int i, i2, total;
        char hex_arr[100];

        point_addr = va_arg(args, unsigned long int);

        for(i = 1; point_addr; i++) {
                mod = point_addr % 16;
                if (mod < 10) {
                        mod += 48;
                } else {
                        mod += 87;
                }
                hex_arr[i] = mod;
                point_addr /= 16;
        }
        printf("0x");
        i2 = i - 1;
        total = i2 + 2;

        while (i2) {
                print_char(hex_arr[i2--]);
        }
        return total;        
}

int spec_func_perc(__attribute__((unused)) va_list args)
{
        int i;
        i = print_char('%');
        return i;
}
