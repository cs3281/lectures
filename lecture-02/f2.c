#include<stdio.h>

int foo() {
  extern int x; 
  printf("x=%d\n", x);  
}
