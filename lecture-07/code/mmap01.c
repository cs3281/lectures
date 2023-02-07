#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <assert.h>
#include <stdlib.h>

int main() {
  int psz = getpagesize();
  printf("Page size: %d\n", psz); 
  
  char arr[8];
  void* stack_pointer = arr;
  printf("stack pointer: %p\n", stack_pointer);
  
  void *top_of_heap1 = sbrk(0);
  printf("Program break: %p\n", top_of_heap1);
   

  void *p = mmap (NULL, 2*psz, PROT_READ |PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0); 

  printf ("Memory (2 pages) has been allocated at address = %p\n", p);  
  
  return 0;
}
