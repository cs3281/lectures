#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "common_threads.h"

void *mythread(void *arg) {
    pthread_detach(pthread_self());	
    long value = (long) arg;
    printf("%ld\n", value);
    value = value + 1;             
    return &value;    
}

int main(int argc, char *argv[]) {
    pthread_t p;
    void* rvalue;
    Pthread_create(&p, NULL, mythread, (void *) 100);    
    Pthread_join(p, &rvalue);            
    printf("returned %ld\n", *(long*)rvalue);
    free(rvalue);
    return 0;
}
