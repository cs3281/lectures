#include <stdio.h>

int b() {
  printf("About to cause an intentional segfault...\n");
  int x = *(int *)0;  
}

int a() {
  b();	
}

int main(int argc, char* argv[]) {
  a();	
}	
