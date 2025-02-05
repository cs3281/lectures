#include <stdio.h>
#include <string.h>

char uninit_arr[5];

int x = 1;

void a() {
  printf("inside function a\n");
}

int main(int argc, char* argv[]) {
  int local_var = 1;

  printf("Address of function a in the text section: %p\n", a);
  printf("Address of initialized variable x in the init data section: %p\n", &x); 
  printf("Address of uninitialized array in the bss: %p\n", uninit_arr);
  printf("Address of local variable on the stack: %p\n", &local_var);

  while(1);
}	
