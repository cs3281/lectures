#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * GitHUb
 * threads
 * race_condition.c
 * __sys_lock_test_and_set
 * __sys_fetch_and_add
 */

int num_threads;
volatile int sum = 0;






void* thread_func(void* arg) {
  
  for(int i = 0; i < num_threads; ++i) {    
    ++sum;           
  }  
}	

int main(int argc, char* argv[]) {
  pthread_t t1, t2;
 
  num_threads = atoi(argv[1]);
  
  pthread_create(&t1, NULL, thread_func, NULL);
  pthread_create(&t2, NULL, thread_func, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Sum = %d\n", sum);

  return 0;
}	
