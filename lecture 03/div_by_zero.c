#include <stdio.h>

int main (int argc, char *argv[])
{
    /* do something silly and end up with div by zero */
    int divisor = 100;
    int dividend = 50;
    while (1) {
        /* let us keep dividing and reducing the dividend by 1. At some point
           the dividend will become zero and the division will throw an
           exception 
        */
        printf ("%d divided by %d = %d\n", divisor, dividend, divisor/dividend);
        dividend--;
    }
}
