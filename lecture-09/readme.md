# Review: race conditions

A race condition occurs when the result or output of a computation depends on the sequence or timing of events that are outside of our direct control. We noted that race conditions often manifest in multi-threaded code when two different threads both operate on the same data.

We noted that race conditions can still occur even if there is only a single CPU. Below are some examples of race conditions.

* A user-level process running on a single core machine creates a second thread. The "main" thread and the second thread both execute a statement like *x++* on a variable *x* that is shared between the two threads. The race condition occurs because the statement *x++* doesn't happen atomically, which means the scheduler can interrupt one process after it has fetched the current value of *x* but before it has increment that value by one and assigned it back to *x*.
* A user-level process running on a multi-core machine creates a second thread. The "main" thread and the second thread both execute a statement like *x++* on a variable *x* that is shared between the two threads. Again, the statement *x++* doesn't happen atomically, and there's the possibility that the two threads are executed on different cores, which means the instructions can be interleaved in any order, leading to the race condition.
* A system call in your operating system kernel running on a single core machine begins to modify a data structure like a linked-list. Before the system call is finished modifying the linked list, an interrupt arrives and is serviced, and the code that processes the interrupt (the interrupt handler) also modifies the linked list.

The typical way to handle these race conditions is to use a *lock*, which ensures *mutual exclusion* and guarantees that *critical-sections* can be executed atomically.

# Atomic instructions: the building blocks for locks

Recall that modern operting systems often use special hardware instructions as the building blocks for locks. These include the *XCHG* and *CMPXCHG* instructions on the x86 processor. These instructions guarantee that compare and exchange operations happen *atomically*. 

These instructions can be used to build a simple *spin-lock* like the following from your book:

```c
typedef struct __lock_t {
  int flag;
} lock_t;

void init(lock_t *lock) {
// 0 indicates that lock is available, 1 that it is held
  lock->flag = 0;
}

void lock(lock_t *lock) {
  // note to reader: invoking the xchg instruction would be done in assembly
  // challenge: figure out how to invoke xchg from a c program!
  while (xchg(&lock->flag, 1) == 1)
  ; // spin-wait (do nothing)
}

void unlock(lock_t *lock) {
  lock->flag = 0;
}
```

(As noted in the comments in the code above, the *XCHG* instruction would need to be invoked using some assembly code -- see if you can figure out how to do that!)

We say that the lock above is a *spin-lock* because if the lock is taken (i.e., the value of flag is already set to 1), then we just keep trying to obtain it until we succeed.


Other similar atomic operations are:

* compare and swap
* test and set

See the code in https://github.com/CS3281-2016/examples/blob/master/threads/introduction/main-thread-5.c and https://github.com/CS3281-2016/examples/blob/master/threads/introduction/main-thread-4.c

# Mutexes

Spin-locks are used in the real-world and also in the Linux kernel. In general, it makes sense to use spin-locks when you expect the lock to be released very soon.

However, if the lock is not released soon, a spin-lock is very inefficient. A better solution is to sleep (let the operating system schedule another process to run) and ask the operating system to wake you (schedule you) when the lock is released.

The general term for such a solution is a *mutex*. The Pthreads library provides a data type called a *pthread_mutex_t*, along with associated functions, for doing just this.

Under Linux, the mutexes provided by the Pthreads library are implemented partly in user-space library code and partly in kernel code. The reason for this is as follows. When you try to obtain a lock, there are two cases: either the lock is taken or it is not taken. If the lock is not taken, then an atomic instruction issued from the Pthreads library code (which operates in user-space) can take the lock. Avoiding a call into the kernel is good because system calls have a lot of associated overhead.

In the case that the lock is taken, the Pthreads library code first tries to spin for a short amount of time to see if the lock becomes available. It does this to try to avoid making a (relatively expensive) system call into the kernel. If the lock has been released, then it can grab it atomically and avoid a system call. In the case that the lock is still taken, the Pthreads library code invokes the *futex()* system call, which asks the kernel to put the calling process on a queue of processes waiting for the lock to be available. The kernel then schedules another process to run, and wakes the process at some point in the future when the lock is available.

### Mutex Sequence

A typical sequence in the use of a mutex is as follows:
* Create and initialize a mutex variable
* Several threads attempt to lock the mutex
* Only one succeeds and that thread owns the mutex
* The owner thread performs some set of actions
* The owner unlocks the mutex
* Another thread acquires the mutex and repeats the process
* Finally the mutex is destroyed

When several threads compete for a mutex, the losers block at that call
* An unblocking call is available with "trylock" instead of the "lock" call


## Mutex Types

Pthread supports the following mutex types

* NORMAL
* ERRORCHECK
* RECURSIVE


# Semaphores

Semaphores are similar to mutexes. However, there is one key difference. While mutexes have binary state i.e. they are either locked or unlocked.  A semaphore may be initialized to a nonnegative integer value. Thereafter, instead of lock and unlock operations, a semaphore provides Semwait and semsignal operations.

* The semWait operation decrements the semaphore value. If the value becomes negative, then the process executing the semWait is blocked.
Otherwise, the process continues execution.
* The semSignal operation increments the semaphore value. If the resulting value is less than or equal to zero, then a process blocked by a semWait operation,

Thus a semaphore with a max counter value of 1 will behave like a mutex.

POSIX provides the following operations to operate on semaphores.

```C
/* Create a semaphore or open an existing semaphore*/ 
sem_t *sem_open(const char *, int, ...);
 
/* Just close the semaphore - do not delete it */ 
int sem_close(sem_t *);

/* delete the named semaphore */ 
int sem_unlink(const char *);

/* Release the resource */ 
int sem_post(sem_t *);

/* check the resource */ 
int sem_getvalue(sem_t *restrict, int *restrict);

/* get the resource */ 
int sem_timedwait(sem_t *restrict, const struct timespec *restrict);
int sem_trywait(sem_t *); 
int sem_wait(sem_t *); 
```

Another difference between semaphore and mutex is that semaphore can be used to implement mutual exclusion across two processes, while mutex only works across threads of a process.
