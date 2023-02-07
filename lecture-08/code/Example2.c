#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

void* func1(void* arg) { 

  for(int i = 0; i < 10; ++i) {
    sleep(1); 
    printf("func1\n");    
  }
 
  return NULL;    
}

void* func2(void* arg) {
  
  for(int i = 0; i < 10; ++i) {
    sleep(1);
    printf("func2\n");    
  }

  return NULL;  
}

int main() {
  pthread_t tid1, tid2;   
  int ret1 = pthread_create(&tid1, NULL, func1, NULL);
  assert(ret1 == 0); 
  
  int ret2 = pthread_create(&tid2, NULL, func2, NULL);
  assert(ret2 == 0); 

  return 0;
}	
