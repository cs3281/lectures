#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define N 3

void fork7();
void fork8();
void fork9();
void fork10();
void fork11();
void fork12();
void fork16();
void fork17();

int main(int argc, char* argv[]) {
  int option = atoi(argv[1]);
  switch(option) {
    case 7: fork7();
            break;
    case 8: fork8();
            break;
    case 9: fork9();
            break;
    case 10: fork10();
             break;       	     
    case 11: fork11();
             break;
    case 12: fork12();
             break;     
    case 16: fork16();
             break;	     
    case 17: fork17();
             break;     
  }	  
  
  return 0;  
}

void fork7() {
  if(fork() == 0) {
   printf("Terminated child, PID = %d\n", getpid());
   exit(0);   
  } else {
      printf("Running parent, PID = %d\n", getpid());
      while(1);      
  }	  
}	

void fork8() {
  if(fork() == 0) {
   printf("Running child, PID = %d\n", getpid());
   while(1);  
  } else {
      printf("Terminated parent, PID = %d\n", getpid());     	  
      exit(0);
  }	  
}

void fork9() {
  int child_status;
  
  if(fork() == 0) {
   printf("HC: hello form child\n");
   exit(0);   
  } else {      
      printf("HP: hello form parent\n");
      wait(&child_status);
      printf("CT: child has terminated with status: %d\n", child_status);           
  }

  printf("By\n");  
}

void fork10() { 
  int child_status;
  pid_t pid[N];

  for(int i = 0; i < N; ++i) {
    if((pid[i] = fork()) == 0) {
     //printf("Child %d started\n", getpid());          
     exit(100 + i);
    } 
  }     
    
  for(int i = 0; i < N; ++i) { 
    pid_t pid = wait(&child_status);	
    if(WIFEXITED(child_status)) {
     printf("Child %d exited with status %d\n", pid, WEXITSTATUS(child_status));		  
    }		 
  }	  
}

void fork11() {
  pid_t pid_array[N];     	
  int child_status; 

  for(int i = 0; i < N; ++i) {    	  
    if((pid_array[i] = fork()) == 0) {     	    
     exit(100 + i);
    }     
  }     
    
  for(int i = N - 1; i >= 0; --i) {      	  
    pid_t pid = waitpid(pid_array[i], &child_status, 0);	
    if(WIFEXITED(child_status)) {
     printf("Child %d exited with status %d\n", pid, WEXITSTATUS(child_status));		  
    } else {
	printf("Child terminated abnormally\n");   
    }	    
  }	  
}

void fork12() {
  pid_t pid_array[N];     	
  int child_status; 	

  for(int i = 0; i < N; ++i) {	  
    if((pid_array[i] = fork()) == 0) {
     printf("Child %d started\n", getpid());     
     while(1);
    }
  }
 
  for(int i = 0; i < N; ++i) {
    printf("Killing process %d\n", pid_array[i]);
    kill(pid_array[i], SIGINT);     
  }

  for(int i = 0; i < N; ++i) { 
    pid_t pid = waitpid(pid_array[i], &child_status, 0);	
    if(WIFEXITED(child_status)) {
     printf("Child %d exited with status %d\n", pid, WEXITSTATUS(child_status));		  
    } else if (WIFSIGNALED(child_status)){	  
	printf("Child %d received signal %d\n", pid_array[i], WTERMSIG(child_status)); // call strsignal() 
    }	    
  }
}	

void fork16() {
  // display process ID  
  if(fork() == 0) {
   printf("Child1: pid = %d, pgrp = %d\n", getpid(), getpgrp());
   
   if(fork() == 0)
    printf("Child2: pid = %d, pgrp = %d\n", getpid(), getpgrp());
   
   while(1);   	   
  }

  while(1); 
}

void fork17() {
  if(fork() == 0) {
   printf("Child: pid = %d, pgrp = %d\n", getpid(), getpgrp());
  } else { 
      printf("Parent: pid = %d, pgrp = %d\n", getpid(), getpgrp());
  } 
  
  while(1);	  
}
