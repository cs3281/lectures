#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

void mmapcopy(int fd, int size) {	
  char* ptr;
  ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);   
  write(1, ptr, size);
  // write to ptr
  *ptr = 'H';
  write(1, ptr, size);
  
  
}	

int main(int argc, char* argv[]) {
  struct stat stat;
  int fd;
  fd = open(argv[1], O_RDWR, 0);
  fstat(fd, &stat);
  mmapcopy(fd, stat.st_size);  
}	
