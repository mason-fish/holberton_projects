#include "headers.h"

int main(int ac, char **argv)
{
        int size;

        if (ac != 2) {
	        return (0);
        }
        
        size = string_to_integer(argv[1]);
        
        if (size < 1) {
                return (0);
        } 
        
        print_top(size);
        print_middle(size);
        print_bottom(size);

        return (0);
}

void print_top(int size)
{
        int i, row;
        
        row = size / 2;
        for (i = 0; i < row; row--) {
                print_line('\\', '/', size, row); 
        }
}

void print_middle(int size) 
{
        int i;
        if (size % 2 == 1) {
                for (i = 0; i < (size / 2); i++) { 
                        print_char(' ');
                }
                write(1, "X", 1);
                for (i = 0; i < (size / 2); i++) { 
                        print_char(' ');
                }
                print_char('\n');
        }
}

void print_bottom(int size)
{
        int i, row;
        
        row = size / 2;
        for (i = 1; i <= row; i++) {
                print_line('/', '\\', size, i);
        } 
}

void print_line(char a, char b, int length, int row)
{
        int i, mod, pad, space;
        mod = length % 2;
        pad = (length / 2) - row;
        space = (row * 2) - 2 + mod;

        if (row < 1) {
                return;
        }
        
        for (i = 0; i < pad; i++) {
                print_char(' ');
        }
        print_char(a);
        for (i = 0; i < space; i++) {
                print_char(' ');
        }
        print_char(b);
        for (i = 0; i < pad; i++) {
                print_char(' ');
        }
        print_char('\n');
}
