#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  pid_t pid;
  pid_t ppid;

  fork();
  fork();
     
  //pid = getpid();
  //ppid = getppid();
  printf("My pid:%d, ppid:%d\n", getpid(), getppid());
}	
