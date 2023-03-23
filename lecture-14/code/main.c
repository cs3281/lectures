#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>

int main() {
  int fd[2];
  if(pipe(fd)) {
   perror("Error:");
   exit(1);   
  }

  int pid = fork();
  if(pid == 0) {
   close(fd[0]);       	   
   char msg[] = "Hello, world!";           
   write(fd[1], msg, strlen(msg));    
   close(fd[1]);
  } else {
      close(fd[1]);
      char msg[14];      
      int len;                        
      len = read(fd[0], msg, sizeof(msg)-1);
      msg[len] = '\0';      
      printf("[parent] received %s\n", msg);      
      close(fd[0]);            
  }	  
}	
