#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int status;
  int psz = getpagesize();
  printf("Page size: %d\n", psz); 
  
  int *p = mmap (NULL, 2*psz, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0); 

  printf ("Memory (2 pages) has been allocated at address = %p\n", p);

  *p = -123;
     
  pid_t pid = fork();

  if(pid == 0) {
   printf("[Child] Initial value of *p=%d\n", *p);
   *p = 2023;
   printf("[Child] Updated value of *p=%d\n", *p);
  } else {      	  
      printf("[Parent] *p before waitpid=%d\n", *p);
      waitpid(pid, &status, 0);       
      printf("[Parent] *p after waitpid=%d\n", *p);
  }	  
  return 0;
}


