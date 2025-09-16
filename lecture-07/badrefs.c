#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int input_arg;

void handler(int sig) {
  printf("%d: received signal %d\n", input_arg, sig);
  exit(0);  
}

int main(int argc, char* argv[]) {
  int *p, val;
  
  signal(SIGSEGV, handler);

  input_arg = atoi(argv[1]);
  switch(input_arg) {
  
  //Accessing a page that is not allocated	  
  case 0:
       p = 0;
       val = *p;
       break;

  //Writing in a page of code section     
  case 1:
       p = (int*)main;
       *p = 0;
       break;

  //Reading from a page of code section      
  case 2:
       p = (int*)main;
       val = *p;
       printf("%d\n", val);
       break;       

  default:
        printf("usage %s <k>\n", argv[0]);
	exit(1);
  }
}	
