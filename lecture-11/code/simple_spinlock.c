#include <pthread.h>
#include <stdio.h>

int count = 0;

// Build a simple spinlock using an int to represent the lock
int lock = 0;

void get_lock(int *lock_ptr)
{
  while (__atomic_exchange_n(lock_ptr, 1, __ATOMIC_SEQ_CST))
    ;
}

void release_lock(int *lock_ptr)
{
  *lock_ptr = 0;
}
  
// this is the function our threads will run first
void *thread_func1(void *arg)
{
  int val = 0;
  printf("Hello from thread 1!\n");
  for (int i = 0; i < 2000000; i++) {
    get_lock(&lock);
    count++;
    release_lock(&lock);
  }
}

// this is the function our threads will run first
void *thread_func2(void *arg)
{
  int val = 0;
  printf("Hello from thread 2!\n");
  for (int i = 0; i < 2000000; i++) {
    get_lock(&lock);
    count++;
    release_lock(&lock);
  }
}

int main(int argc, char *argv[])
{
  pthread_t t1, t2;

  pthread_create(&t1, NULL, thread_func1, NULL);
  pthread_create(&t2, NULL, thread_func2, NULL);

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Final value of count: %d\n", count);
}
