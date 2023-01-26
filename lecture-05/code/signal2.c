#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <assert.h>

void sig_handler(int num) {
  printf("Received a signal %d\n", num);	
}

int main() {
  signal(SIGUSR1, sig_handler);
  pid_t pidChild = fork();
  assert(pidChild >= 0);
 
  if(pidChild == 0) {
   pid_t ppid = getppid();   
   kill(ppid, SIGUSR1); 
   while(1);
  } else {
      kill(pidChild, SIGUSR1);
      int status;
      waitpid(pidChild, &status, 0);
      printf("Child has terminated.\n");     
  }     	  
}
