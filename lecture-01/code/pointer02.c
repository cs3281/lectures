#include <stdio.h>
#include <string.h>

void f1(int x) {
  x++;
}

void f2(int* x) {
  (*x)++;
}

void f3(char* s) {
  while(*s != '\0') {
    *s++;  
  }	  
}

void f4(char* s) {
  while(*s != '\0') {
    (*s)++;  
  }	  
}
void f5(char* s) {
  while(*s != '\0') {
    (*s)++;
    s++;  
  }	  
}


int main() {
  int x = 1;
  f1(x);
  printf("after f1, x=%d\n", x);  

  f2(&x);
  printf("after f2, x=%d\n", x);

  char hello[] = "HELLO";
  char str[80];
  strcpy(str, hello);
  f3(str);
  printf("after f3, str=%s\n", str);
  strcpy(str, hello);
  f4(str);
  printf("after f4, str=%s\n", str);
  strcpy(str, hello);
  f5(str);
  printf("after f5, str=%s\n", str);
}	
