#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <semaphore.h>
#include <string.h>
  /*
	* Demo unamed semaphore - RENDEZVOUS
	* All threads wait at the rendez vous until they are all arrived.
	*/


#define TRUE 1
#define FALSE 0
#define DEBUG TRUE			// Print messages related to semaphore functions
#define TRACE TRUE			// Print messages related to program logic
#define THREAD_MAX  5		// Max number of threads


// Semaphores
sem_t semBarrier;				// Manage RendezVous
sem_t semMutex;				        // Ensures unique access to rvCnt

// Tracking number of threads arrived at rendezvous.
int rvCnt = 0;


void *thread (void *arg) {
	int id = *((int *) arg);
	int retVal;

        printf ("[THREAD %d] Starting.\n", id);

	// Working hard
	usleep (rand() % 1000000);

	// arriving at rendez vous. Increment count
	printf ("[THREAD %d] at rendez-vous.\n", id);
	sem_wait(&semMutex);
	rvCnt++;
	
	// Last one to arrive tells others
	if (rvCnt == THREAD_MAX) {
		printf ("[THREAD %d] last one to arrive\n", id);
		sem_post(&semBarrier);
	}
	
	// Release lock
	sem_post(&semMutex);


	// Use turnstyle
	printf ("[THREAD %d] passing turnstyle\n", id);
	sem_wait(&semBarrier);

	sem_post(&semBarrier);
		
	printf ("[THREAD %d] exiting\n", id);
 	pthread_exit(NULL);	

}


int main(int argc, char *argv[]) {
	pthread_t t [THREAD_MAX];		// Threads id
	int arr [THREAD_MAX];			// Threads numbers
	int retVal;

	// Initialize randomizer
	srand(time(NULL));

	// Initialize semaphores
	sem_init(&semMutex, 0, 1);
	sem_init(&semBarrier, 0, 0);	

	// Create threads
	for(int i=0; i < THREAD_MAX; i++){
		arr [i] = i;
  	retVal = pthread_create (&t [i], NULL, thread, (void *) &arr[i]);
		assert (retVal == 0);
	}

	// Wait
	for(int i=0; i < THREAD_MAX; i++){
  	retVal = pthread_join (t [i], NULL);
		assert (retVal == 0);
	}
	
	printf ("Main: Done.\n");
}
