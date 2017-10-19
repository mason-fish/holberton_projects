#include "headers.h"

int print_char(char c)
{
  return (write(1, &c, 1));
}

/*
 * print_number() TAKES AN INT, DIVIDES IT BY 10 AS MANY TIMES AS IT CAN TO
 * DETERMINE HOW MANY DIGITS IT CONTAINS,
 * AND THEN CONVERTS EACH DIGIT TO A SINGLE
 * CHAR BY USING THE MODULUS OPERATOR
 * AND ADDING THIS VALUE TO THE CHAR '0'. FINALLY
 * THIS CHAR IS PASSED TO THE [print_char] FUNCTION.
 */
int print_number(long int n)
{
        int total = 0;
        long int i = 1;
        long int i2;
        long int temp;
        long int mod = 1;
        if (n < 0) {
                total += print_char('-');
                mod = -1;
        }
        for(temp = n; temp > 9 || temp < -9; temp = temp / 10) {
                i++;
        }
        while(i) {
                i2 = i--;
                temp = n;
                while(i2-- > 1) {
                        temp /= 10;
                }
                total += print_char(((temp % 10) * mod + '0'));
        }
        return total;
}
