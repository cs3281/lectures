#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "common.h"
#include "common_threads.h"
#include <semaphore.h>

sem_t s;

void *child(void *arg) {
    sleep(2);
    printf("child\n");
    sem_post(&s); 
    return NULL;
}

int main(int argc, char *argv[]) {
    // initialize semaphore         
    printf("parent: begin\n");
    pthread_t c;
    sem_init(&s, 0, 0);
    pthread_create(&c, NULL, child, NULL);
    // wait here for peer thread    
    //pthread_join(c, NULL);
    sem_wait(&s);
    printf("parent: end\n");
    return 0;
}
    
