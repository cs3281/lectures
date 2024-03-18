# Condition variables

Mutexes offer a higher-level abstraction than a basic spin-lock, but they don't solve the following common problem.

Suppose we have the following. There is a process has two threads, a *producer* thread and a *consumer* thread. The *producer* thread writes data to a shared buffer, and the consumer thread *reads* data from the shared buffer. The *producer* thread can only write data when there is space in the buffer, and the *consumer* thread can only consume data when there is at least one piece of data in the buffer.

Obviously the buffer is a shared resource to which we must restrict access using a lock or mutex. However, even a mutex is not a good enough solution when there are multiple consumers and multiple producers: the consumers and producers don't only care about whether they can have access to the shared resource (the buffer), but they also care about changes in the *state* of the buffer. Specifically, the producers want to be notified when there is space available in the buffer to put data, and the consumers want to be notified when there is data in the buffer that can be consumed.

The solution to this problem is something called a *condition variable*, which (1) allows one thread to inform other threads about changes in the state of a shared variable, and (2) allows the other threads to wait for such a notification. Condition variables are used together with a mutex: the mutex guarantees exclusive access to the shared resource, and the condition variable allows a thread do the above.

The external reference [https://computing.llnl.gov/tutorials/pthreads/#ConditionVariables](https://computing.llnl.gov/tutorials/pthreads/#ConditionVariables) describes condition variables in Linux and shows an example of how to use them; below we highlight a few important points with the producer/consumer example.

A mutex variable is always used to guard access to a shared resource. Only after obtaining a mutex lock can the *predicate*, or condition of the shared resource, be checked. For example, in a producer/consumer example, a consumer thread would obtain a lock on a mutex and then check whether the shared buffer has any data available. Let's suppose the code is initialized like the following:

```c
pthread_mutex_t mutex;      // mutex to guard access
pthread_cond_t empty, full; // 2 condition variables

int buf[10];           // a shared integer array
int numAvailable = 0;  // initially no data available
int readPos, writePos; 

readPos = writePos = 0;
```

Then the consumer would do something like this:

```c
for(;;) {
  // 1. Lock the mutex
  pthread_mutex_lock(&mutex);
  
  // 2. Check the condition of the shared resource
  while (numAvailable == 0) {
    // It's important to put this in a while loop!
    pthread_cond_wait(&full, &mutex);
  }
  
  // 3. At this point, you hold the mutex, so the consumer
  // can safely take data from buf
  while (numAvailable > 0) {
    // consume from buf
    numAvailable--;
  }
  
  // 4. Make sure to unlock the mutex when you're done
  pthread_mutex_unlock(&mutex);
  
  // 5. Signal the condition that space in buf is available
  pthread_cond_signal(&empty);
}
```

*pthread_cond_wait* does 3 things:

1. Unlocks its mutex parameter
2. Blocks the calling thread until another thread signals its condition variable parameter
3. Relocks the mutex parameter

Similarly, the producer would do something like this:

```c
int slots = sizeof(buf) / sizeof(buf[0]);

for(;;) {
  // 1. Lock the mutex
  pthread_mutex_lock(&mutex);
  
  // 2. Check the condition of the shared resource
  while (numAvailable >= slots) {
    // It's important to put this in a while loop!
    pthread_cond_wait(&empty, &mutex);
  }
  
  // 3. At this point, you hold the mutex, so the consumer
  // can safely take data from buf
  while (numAvailable < slots) {
    // insert into buf
    numAvailable++;
  }
  
  // 4. Make sure to unlock the mutex when you're done
  pthread_mutex_unlock(&mutex);
  
  // 5. Signal the condition that data is available
  pthread_cond_signal(&full);
}
```


## Important note about condition variables

Whenever you use the condition variable you should follow the following design pattern.

### Signal (or Broadcast) Pattern

1. Aquire mutex associated with the condition variable
2. Check the condition
3. If condition is true, signal (or broadcast) using condition variable
4. Unlock the muex


### Wait Pattern

1. Aquire mutex
2. While(condition is false)
  - wait on condition // this is a blocking call. But can be interrupted erroneously. The wait guarantees that the mutex will be required when the control in thread is returned from the condvar wait function
  - End of while 
3. Do some work
4. Unlock the mutex


The while loop in the wait pattern is very important. This is because the condition variable wait can be interrupted erroneously. 

# Condition variable implementation

Like mutexes, condition variables are implemented using the *futex* system call. For the curious reader, [this link](http://www.eglibc.org/cgi-bin/viewvc.cgi/trunk/libc/nptl/DESIGN-condvar.txt?view=markup) contains pseudocode describing the implementation used by eglibc.
