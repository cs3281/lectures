#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int num_iterations;
volatile int sum = 0;
int lock = 0;

void get_lock() { 
  while(__atomic_exchange_n(&lock, 1, __ATOMIC_SEQ_CST));
  //while(lock);
  //lock = 1;
}

void unlock() {
  __atomic_store_n(&lock, 0, __ATOMIC_SEQ_CST); 	
  //lock = 0;	
}

void* thread_func(void* arg) {
     	
  for(int i = 0; i < num_iterations; ++i) {
    get_lock();
    ++sum;        
    unlock();
  }    
}	

int main(int argc, char* argv[]) {
  pthread_t t1, t2;
 
  num_iterations = atoi(argv[1]);
  
  pthread_create(&t1, NULL, thread_func, NULL);
  pthread_create(&t2, NULL, thread_func, NULL); 
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);  

  printf("Sum = %d\n", sum);

  return 0;
}	
