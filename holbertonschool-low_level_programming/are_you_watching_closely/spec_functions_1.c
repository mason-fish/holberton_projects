#include "headers.h"

int spec_func_di(va_list args)
{
        int i, next_arg;
        next_arg = va_arg(args, int);
        i = print_number(next_arg);
        return i;
}

int spec_func_o(va_list args)
{
        long int x, q;
        int o[100], i, j, total;
        i = 1;

        x = va_arg(args, long int);
        q = x;

        while(q){
                o[i++] = q % 8;
                q /= 8;
        }

        for(j = (i - 1), total = 0; j; j--, total++)
                printf("%d",o[j]);

        return total;
}

int spec_func_u(va_list args)
{
        unsigned int x;
        int i;
        x = va_arg(args, unsigned int);
        i = print_number(x);
        return i;
}

int spec_func_x(va_list args)
{
        long int d, q;
        int i, j, tmp, total;
        char hex[100];
        i = 1;

        d = va_arg(args, long int);
        q = d;

        while(q){
                tmp = q % 16;
                if(tmp < 10) {
                        tmp += 48;
                }
                else {
                        tmp += 87;
                }
                hex[i++] = tmp;
                q /= 16;
        }

        for(j = (i - 1), total = 0; j; j--, total++)
                print_char(hex[j]);

        return total;
}

int spec_func_X(va_list args)
{
        long int d, q;
        int i, j, tmp, total;
        char hex[100];
        i = 1;
        
        d = va_arg(args, long int);
        q = d;
        
        while(q){
                tmp = q % 16;
                if(tmp < 10) {
                        tmp += 48;
                }
                else {
                        tmp += 55;
                }

                hex[i++] = tmp;
                q /= 16;
        }
        
        for(j = (i - 1), total = 0; j; j--, total++)
                print_char(hex[j]);
        
        return total;       
}
