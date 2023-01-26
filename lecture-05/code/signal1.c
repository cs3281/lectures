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
  pid_t pidChild = fork(); 
  assert(pidChild >= 0);

  if(pidChild == 0) {   	  
   signal(SIGUSR1, sig_handler);       
   while(1) {
     printf("Child\n");     
     sleep(1);
   }	   
  } else {
      sleep(1);	  
      kill(pidChild, SIGINT);
      int status;
      waitpid(pidChild, &status, 0);
      printf("Child has terminated.\n");     
  }     	  
}
