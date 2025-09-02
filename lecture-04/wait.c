#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {
  int pid = fork();

  if(pid == 0) { 
   char* args[] = {"/bin/ls", "-l", (char*)0};
   execvp(args[0], args);
   printf("%s: Command not found.\n", args[0]);   
   exit(1);   
  } else if (pid > 0) {    	  
      int ret;
      wait(&ret);        
      if(WIFEXITED(ret)) {
       printf("Child exited with exit code: %d\n", WEXITSTATUS(ret));	      
      }	      
  }	  
}	
