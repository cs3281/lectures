#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  int fds[2];
  if(pipe(fds)) {
   printf("Error creating pipe!");\
   exit(1);	   
  }

  printf("fds[0]: %d, fds[1]: %d\n", fds[0], fds[1]);

  pid_t pid = fork();
  if(pid == 0) {
   printf("Hello from child\n");
   char buf[64] = {0};
   char* str = "Hello, parent process! How are you?\n";
   close(fds[0]);
   int len;   
   write(fds[1], str, strlen(str)+1);   
   close(fds[1]);         
  } else {
      int status;	  
      printf("Hello from parent\n");   
      close(fds[1]);     
      char buf[64] = {0};
      read(fds[0], buf, sizeof(buf)-1);
      printf("Message received from child: %s", buf); 
      close(fds[0]);                                   
      wait(&status);              
  }	  
}	

