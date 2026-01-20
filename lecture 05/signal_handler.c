#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int sig) {
  printf("So you think you can stop the bomb with ctrl-c, do you?\n");	
  sleep(2);
  printf("Well..");
  fflush(stdout);
  sleep(1);
  printf("OK. :)\n");
  exit(0); 
  }

int main() {
  if(signal(SIGINT, sigint_handler) == SIG_ERR) {
   printf("signal error"); 	  
  } 

  pause();
  printf("SIGINT signal is handled\n");  

  return 0;   
}	
