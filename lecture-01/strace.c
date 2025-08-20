#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int argc, char* argv[]) { 
  pid_t processId = getpid();  
  printf("processId=%d\n", processId);  

  return 0;  
}	
