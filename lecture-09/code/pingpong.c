#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* This program displays PING PONG alternately.
 * Use threads and a lock.
 */

#define THREAD_COUNT 2

void* play(void* args) {
  
  while(1) {
    sleep(1);
    /* print PING/PONG here */    
  }

  pthread_exit(NULL);
}	
int main() {
  pthread_t thread_id[THREAD_COUNT];
  int index[THREAD_COUNT];

  for(size_t i=0; i<THREAD_COUNT; ++i) {
    pthread_create(&thread_id[i], NULL, play, &index[i]);	  
  }

  for(int i=0; i<THREAD_COUNT; ++i) {
    pthread_join(thread_id[i], NULL);	  
  }

  return 0;
}	
