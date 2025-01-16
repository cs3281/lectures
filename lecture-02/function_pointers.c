#include <stdio.h>

void a() {
  printf("Hello from function a()\n");	
}

void b(int x) {
  printf("Hello from b called with arg %d\n", x);	
}

int c(int x) {
  printf("Hello from c called with arg %d\n", x);
  return x + 1;  
}

int main() {
  printf("Address of function a(): %p\n", a);
  printf("Address of function b(): %p\n", b);
  printf("Address of function c(): %p\n", c);

  void (*p1)() = &a;
  void (*p2)(int) = &b;
  int (*p3)(int) = &c;

  (*p1)();
  (*p2)(17);
  int ret = (*p3)(31);
  printf("Return value from c: %d\n", ret); 
}	


