#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1000000

char* p = NULL;

void allocate_space() {
  p = malloc(sizeof(char) * SIZE);	
}

void use_space() {
  for(int i = 0; i < SIZE; ++i) {
    *(p + i) = 'A';	  
  }	  
}

int main() {
  sleep(20);
  printf("About to allocate space\n");
  allocate_space();
  sleep(20);
  printf("About to use space\n"); 
  use_space();
  sleep(20);
}	

