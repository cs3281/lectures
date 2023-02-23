#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int shared = 1;
sem_t s;

void* func1(void* arg) {
  sem_wait(&s);
  shared++;
  sem_post(&s);  
}

void* func2(void* arg) {
  sem_wait(&s);
  shared--;
  sem_post(&s);  
}

int main() {
  sem_init(&s, 0, 1);	
  pthread_t t1, t2;

  pthread_create(&t1, NULL, func1, NULL);
  pthread_create(&t2, NULL, func2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
   	  

  printf("shared=%d\n", shared);

  return 0;
}	
