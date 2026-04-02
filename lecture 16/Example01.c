#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 	30
#define READ_END	0
#define WRITE_END	1

int main() {
    // Pipe file descriptors
    int fd[2];

    char buf[BUFF_SIZE];
    char *msg = "CS3281";
    //create pipe: return 0 if success, else -1
    if (pipe(fd) == -1) {
     perror("pipe");
     exit(EXIT_FAILURE);
    }
     
    //write to pipe 
    if(write(fd[WRITE_END], msg, 1+strlen(msg)) == -1) {
     perror("write failed");    	    
    }	    
    
    //read from pipe
    if(read(fd[READ_END], buf, BUFF_SIZE) == -1) {
     perror("read failed"); 	    
    }
    printf("read %s\n", buf);
    return 0;
}

