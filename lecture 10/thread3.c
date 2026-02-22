#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int shared = 1;
pthread_mutex_t mutex;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

void* fun1() {
  pthread_mutex_lock(&mutex);
  while(shared != 1) {
    sleep(1);
    pthread_cond_wait(&cv, &mutex);    
  }
  shared++;
  pthread_cond_signal(&cv);
  pthread_mutex_unlock(&mutex); 
}

void* fun2() {
  pthread_mutex_lock(&mutex);
  while(shared != 2) {
    sleep(1);
    pthread_cond_wait(&cv, &mutex);    
  }
  shared--;
  pthread_cond_signal(&cv);
  pthread_mutex_unlock(&mutex); 
}

int main(int argc, char* argv[]) {
  pthread_t t1, t2;
  
  pthread_create(&t1, NULL, fun1, NULL);
  pthread_create(&t2, NULL, fun2, NULL);
  
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}	
