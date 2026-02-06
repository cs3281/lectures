#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void stack_example_function();

char global_init_str[9] = "AABBCCDD";
char global_unint_str[9];

char* heap_ptr_str = 0;

int main(int argc, char* argv[]) {  	 
  printf("Address of global_init_str:  %p\n", global_init_str);
  printf("Content of global_init_str:  %s\n", global_init_str); 

  printf("Address of global_unint_str:  %p\n", global_unint_str);
  printf("global_init_str does not have content yet; do not try to print it.\n");
  //printf("Content of global_unint_str:  %s\n", global_unint_str);
  
  strcpy(global_unint_str, "00112233"); 
  printf("After strcpy, global_unint_str contains: %s\n", global_unint_str);

  printf("Initially, heap_ptr_str is a null pointer: %p\n", heap_ptr_str);
  heap_ptr_str = malloc(32);
  printf("After malloc, heap_ptr_str holds an address in the heap:%p\n", heap_ptr_str);
  strcpy(heap_ptr_str, "XXYYZZ");
  printf("After strcpy, heap_ptr_str contains: %s\n", heap_ptr_str);

  stack_example_function();

  while(1);
}

void stack_example_function() {
  char stack_char[64];
  printf("Address of stack_char: %p\n", stack_char);
  strcpy(stack_char, "112233"); 
  printf("After strcpy, stack_char contains: %s\n", stack_char);

  stack_char[0] = '0';
  stack_char[1] = '0';
  stack_char[2] = '1';
  stack_char[3] = '1';

  printf("stack_char now contains: %s\n", stack_char);
}	
