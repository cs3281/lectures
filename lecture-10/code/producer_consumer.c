#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 2

int num_avail = 0;
int buffer[BUFFER_SIZE];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

// function for producer threads
void *producer_function(void *arg)
{
    
    pthread_mutex_lock(&mutex);
    while (num_avail >= BUFFER_SIZE) {
      pthread_cond_wait(&cond_empty, &mutex);
    }      
            
    num_avail++;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond_full);

    return NULL;
}

// function for producer threads
void *consumer_function(void *arg)
{    
    pthread_mutex_lock(&mutex);
    while (num_avail <= 0) {
	    pthread_cond_wait(&cond_full, &mutex);	    
    }    
        
    num_avail--;    
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond_empty);       

    return NULL;
}
                                                                             
int main(int argc, char *argv[])
{                    
    pthread_t producer_1, producer_2;
    pthread_t consumer_1, consumer_2;

    // create four threads: two producers, two consumers
    pthread_create(&producer_1, NULL, producer_function, "Producer 1"); 
    pthread_create(&producer_2, NULL, producer_function, "Producer 2");
    pthread_create(&consumer_1, NULL, consumer_function, "Consumer 1");   
    pthread_create(&consumer_2, NULL, consumer_function, "Consumer 2");

    // wait for everyone to finish
    pthread_join(producer_1, NULL);
    pthread_join(producer_2, NULL);
    pthread_join(consumer_1, NULL);
    pthread_join(consumer_2, NULL);
 
    return 0;
}

