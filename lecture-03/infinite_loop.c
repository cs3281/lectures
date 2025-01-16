#include <stdio.h>

int main (int argc, char *argv[])
{
    /* run an infinite loop and show that the process can be killed */
    int counter = 0;
    while (1) {
        printf ("Current counter value = %d\n", counter);
        counter++;
    }
}
