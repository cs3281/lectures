#include "csapp.h"

#define NITERS 50

volatile long cnt = 0; /* Counter */
sem_t mutex[2];

void* count(void* vargp) {
  long id = (long)vargp;

  for(int i = 0; i < NITERS; i++) {
    P(&mutex[1-id]); P(&mutex[id]);
    cnt++;
    V(&mutex[id]); V(&mutex[1 - id]);   
  }

  return NULL;  
}

int main() {
  pthread_t tid[2];

  Sem_init(&mutex[0], 0, 1);
  Sem_init(&mutex[1], 0, 1);

  Pthread_create(&tid[0], NULL, count, (void*) 0); 
  Pthread_create(&tid[1], NULL, count, (void*) 1);

  Pthread_join(tid[0], NULL);
  Pthread_join(tid[1], NULL);

  printf("cnt=%ld\n", cnt);

  return 0;
}	
