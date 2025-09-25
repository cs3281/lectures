#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 1

int num_avail = 0;
int buffer[BUFFER_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;
int p_index = 0;
int c_index = 0;
int loops;
sem_t sem;

// function for producer threads
void *producer_function(void *arg)
{
    int args = (int)arg;
    int i;
    for(i = 0; i < loops; i++) {

      pthread_mutex_lock(&mutex);
      while (num_avail >= BUFFER_SIZE) {
        pthread_cond_wait(&cond_empty, &mutex);
      }       
    
      buffer[p_index] = args;
      printf("producer_%d: buffer[%d] = %d \n", args, p_index, buffer[p_index]);
      p_index++;
      p_index = p_index % BUFFER_SIZE;    
      num_avail++;
      pthread_cond_signal(&cond_full);
      pthread_mutex_unlock(&mutex);    
    }
    return NULL;
}

// function for producer threads
void *consumer_function(void *arg)
{    
    char* args = (char*)arg;
    int i;
    for(i = 0; i < loops; i++) {
      pthread_mutex_lock(&mutex);
      while (num_avail <= 0) {
	    pthread_cond_wait(&cond_full, &mutex);	    
      }    
    
      printf("%s took %d\n", args, buffer[c_index]);
      c_index++;
      c_index = c_index % BUFFER_SIZE; 
      num_avail--;
      pthread_cond_signal(&cond_empty);
      pthread_mutex_unlock(&mutex);
    }        
    return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    loops = atoi(argv[1]);
    pthread_t producer_1, producer_2;
    pthread_t consumer_1, consumer_2;

    // create four threads: two producers, two consumers
    pthread_create(&producer_1, NULL, producer_function, (void*)1); 
    pthread_create(&producer_2, NULL, producer_function, (void*)2);
    pthread_create(&consumer_1, NULL, consumer_function, "consumer_1");   
    pthread_create(&consumer_2, NULL, consumer_function, "consumer_2");

    // wait for everyone to finish
    pthread_join(producer_1, NULL);
    pthread_join(producer_2, NULL);
    pthread_join(consumer_1, NULL);
    pthread_join(consumer_2, NULL);
 
    return 0;
}

