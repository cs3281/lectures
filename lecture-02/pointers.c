#include <stdio.h>

/* This program demonstrates how to use a pointer to change the 
   value of a variable. */

// C uses call by value. For an explanation of what call by value
// means, see page 27 of the K & R book.

// Remember that a pointer is just a variable that holds an address.

// The function f1 below has one parameter (named x) of type int pointer.
// That means it holds the address of an int.
void
f1 (int *x)
{
  printf ("Value of x at beginning of function is: %d, the pointer is %p\n",
          *x, x);
  // This is how you "de-reference" a pointer and assign a value
  // to be stored at the address the pointer holds.
  *x = 37;
  printf ("Value of x at end of function is: %d, the pointer is %p\n", *x, x);
}

int
main (int argc, char *argv[])
{
  // x is an automatic variable
  int x = 3;

  // the address of x is passed to f1
  f1 (&x);

  // after calling f1, the value of x is 37
  printf ("Value of x after calling function is: %d\n", x);

  // you can print the value of a pointer like this
  printf ("Address of x: %p\n", &x);
  return 0;
}
