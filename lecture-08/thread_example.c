#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct thread_args {
  int x;
  int y;  
};

void* func(void* arg) {  
  struct thread_args* args = (struct thread_args*)arg;
  printf("Values passed in are x = %d, y = %d\n", args->x, args->y);
      
  struct thread_args new_struct = *args;
  new_struct.x = 20;
  return &new_struct;   
}

int main(int argc, char* argv[]) {
  pthread_t t1;
  struct thread_args arg = {.x=17, .y=31};
  
  pthread_create(&t1, NULL, func, &arg);  
  void* retVal;
    
  pthread_join(t1, &retVal);
 
  if(retVal != NULL) {  
   printf("Value returned: %d\n", ((struct thread_args*)retVal)->x); 
  }     
}	
