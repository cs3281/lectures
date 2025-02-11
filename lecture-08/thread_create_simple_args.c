#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "common_threads.h"

void *mythread(void *arg) {
    long value = (long) arg;
    printf("%ld\n", value);
    long* a = (long*) malloc(sizeof(long));
    *a = value + 1;
    return a;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    void* rvalue;
    Pthread_create(&p, NULL, mythread, (void *) 100);
    Pthread_join(p, &rvalue);
    printf("returned %ld\n", *(long*)rvalue);
    return 0;
}

