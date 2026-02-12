#include "csapp.h"
#define N 5
void* thread(void* arg);

int main(int argc, char* argv[]) {  
  pthread_t tids[N];

  long i;
  for(i=0; i<N; i++) {    	  
    Pthread_create(&tids[i], NULL, thread, &i);        
  } 

  for(i=0; i<N; i++) {
    Pthread_join(tids[i], NULL);
  } 

  return 0;  
}

void* thread(void* arg) {
  
  int myid = *((long*) arg);
  printf("Hello from thread %d\n", myid);    
  return NULL;  
}	
