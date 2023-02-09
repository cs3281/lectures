#include <stdio.h>
#include <pthread.h>

#define MAX 16
#define MAX_THREAD 2

int arr[MAX] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int sum[MAX_THREAD] = {0};
int task_controller = 0;

/* A thread that runs this function adds up numbers in only half of the array */
void* sum_array(void* arg) {
  	  
}	

int main() {
  pthread_t thread_id[MAX_THREAD];

  /* Create threads here*/


  /* Wait for threads here */


  int total = 0;
  for(int i = 0; i < MAX_THREAD; ++i) {
    total += sum[i];
  }

  printf("total=%d\n", total);  
}	
