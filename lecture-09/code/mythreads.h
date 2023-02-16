#ifndef __MYTHREADS_h__
#define __MYTHREADS_h__

#include <pthread.h>
#include <assert.h>
#include <sched.h>

void
Pthread_mutex_lock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_lock(m);
    assert(rc == 0);
}
                                                                                
void
Pthread_mutex_unlock(pthread_mutex_t *m)
{
    int rc = pthread_mutex_unlock(m);
    assert(rc == 0);
}
                                                                                
void
Pthread_create(pthread_t *thread, const pthread_attr_t *attr, 	
	       void *(*start_routine)(void*), void *arg)
{
    int rc = pthread_create(thread, attr, start_routine, arg);
    assert(rc == 0);
}

void
Pthread_join(pthread_t thread, void **value_ptr)
{
    int rc = pthread_join(thread, value_ptr);
    assert(rc == 0);
}

extern int sched_setaffinity (__pid_t __pid, size_t __cpusetsize,  __const cpu_set_t *__cpuset) __THROW;

void
cpubind()
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    int rc = sched_setaffinity(0, sizeof(cpu_set_t), &set);
    assert(rc == 0);
}

#endif // __MYTHREADS_h__
