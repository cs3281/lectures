#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    /* show a segmentation fault occuring by not allocating memory to a pointer */

    /* declare a pointer to char */
    char *str = malloc(sizeof(char)* 7);

    /* define some garbage literal string */
    char *literal = "adioof"; 

    printf ("string contents of the literal string = %s\n", literal);

    /* now try copying the contents of the literal into the pointer without
       allocating any memory thereby causing segmentation fault */
    strcpy (str, literal);

    printf ("string contents pointed to by the pointer = %s\n", str);
}
