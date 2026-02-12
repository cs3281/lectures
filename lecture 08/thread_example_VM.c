#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int common = 162;

void *threadfun(void *threadid)
{
    long tid = (long)threadid;
    printf("Thread %ld stack: %p common: %p (%d)\n", 
           tid, 
           &tid, 
           &common, 
           ++common);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    long t;
    int nthreads = 2;
    if (argc > 1) {
        nthreads = atoi(argv[1]);
    }

    pthread_t threads[nthreads]; 
    printf("Main stack: %p, common: %p (%d)\n", 
           &t, 
           &common, 
           common);

    for (t = 0; t < nthreads; t++) {
        int rc = pthread_create(&threads[t], NULL, threadfun, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < nthreads; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL);   /* last thing in the main thread */
}

