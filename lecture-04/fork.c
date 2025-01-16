#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
	
int main() 
{
    pid_t pid;
    pthread_t tid;
    int x = 1;

    pid = fork(); 
    if (pid == 0) {  /* Child */
	printf("child: x=%d\n", ++x);	
	exit(0); //comment this line	
    }

    /* Parent */            
    printf("parent: x=%d\n", --x); 
    exit(0);
}

