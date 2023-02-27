#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

/***************************************************
 * Using semaphore			                       *
 * Two threads are counting down from MAX_CNT to 0 *
 * and incrementing the global variable cntUp.     *
 * When zero is reached, GO thread prints GO !!!   *
 **************************************************/

// Global Variable
#define MAX_CNT 5
int	cntDown = MAX_CNT;
int cntUp = 0;



// Functions countdown to decrement global variable cntDown
// And increment global variable cntUp
void *countdown(void *t) {
	while (countDown > 0) {

		/* YOUR CODE HERE */

     }
	pthread_exit(NULL);
}


// Function GO to print GO !! when 
// global variable reaches a certain value
void *go (void *arg) {

		/* YOUR CODE HERE */
 }

int main (int argc, char *argv[]) {
   	pthread_t t_id [3];
	printf ("Start values. cntUp: %d, cntDown: %d\n", cntUp, cntDown);

   	// Initialize semaphore (s)


   	// Create threads
   	pthread_create(&t_id[0], NULL, countdown, NULL);
   	pthread_create(&t_id[1], NULL, countdown, NULL);
   	pthread_create(&t_id[2], NULL, go, NULL);

   	// Wait for all threads to complete
	for (int i=0; i<3; i++) {
		pthread_join(t_id[i], NULL);
	}

	/* Clean up and exit */

	printf ("End values. cntUp: %d, cntDown: %d\n", cntUp, cntDown);

 } 
