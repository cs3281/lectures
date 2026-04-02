#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int fd = open("test.txt", O_CREAT|O_RDWR);
  printf("fd for text.txt: %d\n", fd);
  dup2(fd, 1);
  printf("fd for text.txt: %d\n", fd);
  printf("Hello\n");
  close(fd); 
}	
