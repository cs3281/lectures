Look at the slides and the following chapters from the book for a basic coverage about scheduling
- http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched.pdf
- http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-sched-mlfq.pdf

Key points to remember are:

 - What is the FIFO scheduling policy? What are its benefits and what are the disadvantages?
 - What is the shorted job first
 - what is the difference between preemptive and non-preemptive policy?
 - What do we need to do if the tasks arrive at different times - this leads us to the short job to completion first.
 - Then we need to think about the IO vs CPU bound jobs?
 - Multi-level feedback queue based schedule policies : this is what is used in practical systems - for example Linux
 - What are the additional considerations for multi-core scheduling.

# Understanding Linux Scheduling Policies

## References:
- https://www.kernel.org/doc/Documentation/scheduler/sched-design-CFS.txt

# Linux Scheduling Policies

Schedulers are implemented in linux kernel through scheduler classes. The two important classes are CFS (completely fair scheduler) and the RT (Real-time scheduler). The real-time scheduler class two policies
- SCHED_FIFO (A Real-time first in first out scheduler)
- SCHED_RR (A Real-time round robin scheduler)

The CFS scheduler has on policy SCHED_OTHER (completely fair scheduler). There is a fourth policy called SCHED_BATCH (used for batch oriented jobs). Linux allows different scheduling policies to be used in the system at the same time. But only one policy is used for a thread at one time. Note that a process by default is single threaded and the policy of the process is the policy associated with its main thread.

## Scheduling priorities.

The priority mechanism applicable to a thread depends upon the scheduling policy of the thread. By default all threads have SCHED_OTHER (completely fair scheduler) policy. Within this policy the priority of a thread is  eferred to as the "niceness levels".  The nice levels go from -20 to +19. A thread with -20 nice value has the highest priority - lower the nice value the higher the priority (a thread with higher priority is not being nice to other threads - get it). 

You can change the nice number for any command or task by using the nice function.

```
$ nice -10 python helloword.py
```

**Note**: Remember that -10 in the above command sets the priority of a process to 10. The – in nice command stands for the hypen, which we use to pass options to the command.

To set higher nice value

```
$ nice --10 python helloword.py
```

To change the nice value of an already running process, use renice

```
$ renice -n -19 -p 3534
```

### Real-time priorities

Real-time tasks that run with either SCHED_FIFO or SCHED_OTHER take prioriy from 0 to 99. 99 being the highest priority. You change the real-time scheduling policy attributes for a process by using the chrt command as shown at **http://linux-tips.com/t/how-to-use-chrt-command/268**
```
$ pidof firefox
17588
$ chrt -p 17588
pid 17588's current scheduling policy: SCHED_OTHER
pid 17588's current scheduling priority: 0
```

Use chrt command to set real time attributes of a Linux process?
```
$ sudo chrt -p prio pid
```

For example,
```
$ sudo chrt -p 20 17588
```
To set scheduling policy to SCHED_BATCH (-b or --batch), for example:
```
$ chrt -b -p 0 17588
```
To set scheduling policy to SCHED_FIFO (-f or --fifo), for example:
```
$ sudo chrt -f -p 20 17588
```
Note: Range of number is [1-99]=>20.
To set policy scheduling policy to SCHED_OTHER (-o or --other), for example:
```
$ chrt -o -p 0 17588
```
To set scheduling policy to SCHED_RR (-r or --rr), for example:
```
$ sudo chrt -r -p 50 17588
```
Note: Range of number is [1-99]=>50.

Note: Setting a realtime scheduling policy (SCHED_RR or SCHED_FIFO) requires root permissions, so you either have to be root or run it with sudo.
Before setting new scheduling policy, you need to find out min and max valid priorities for each scheduling algorithm, show min and max valid priorities. For example,
```
$ chrt -m
SCHED_OTHER min/max priority	: 0/0
SCHED_FIFO min/max priority	: 1/99
SCHED_RR min/max priority	: 1/99
SCHED_BATCH min/max priority	: 0/0
SCHED_IDLE min/max priority	: 0/0
```

## Finding the scheduling policies and priorities programmatically
 
The following code shows you how to find out the policy of a process

```C
/* Example taken from http://www.cs.cofc.edu/~leclerc/340/examples/schedtest.c*/

#include <stdio.h>        // for printf()
#include <sched.h>        // for sched_xxx() function calls
#include <sys/types.h>    // for pid_t
#include <sys/time.h>     // for getpriority()
#include <sys/resource.h> // for getpriority()
#include <unistd.h>       // for nice()

int main(int argc, char** argv)
{
  int schedpolicy;
  int prio;
  int minprio, maxprio;
  struct sched_param p;
  int rrinterval;
  struct timespec ts;

  p.sched_priority = 1;

  if (sched_setscheduler((pid_t) 0, SCHED_RR, &p) == -1) {
    printf("couldn't set scheduler to SCHED_RR\n");
  }

  if (sched_rr_get_interval((pid_t) 0, &ts) != -1) {
    printf("quantum = %ld secs %ld nanosecs\n", ts.tv_sec, ts.tv_nsec);
  }

  schedpolicy = sched_getscheduler((pid_t) 0);  // i.e. this process

  switch (schedpolicy) {
    case SCHED_FIFO:
      printf("SCHED_FIFO\n");
      break;
    case SCHED_RR:
      printf("SCHED_RR\n");
      break;
    case SCHED_OTHER:
      printf("SCHED_OTHER\n");
      break;
    default:
      printf("unknown scheduling policy\n");
  }

  // get and print priority of this process
  prio = getpriority(PRIO_PROCESS, 0);
  printf("process priority is %d\n", prio);

  // NOTE:  only root can increase the priority of a process
  nice(10);   // i.e. lower the priority of this process

  // get and print priority of this process
  prio = getpriority(PRIO_PROCESS, 0);
  printf("process priority is %d\n", prio);

  // get minimum and maximum priority for this scheduling policy
  // NOTE:  on Linx using SCHED_OTHER, both values are 0
  minprio = sched_get_priority_min(schedpolicy);
  maxprio = sched_get_priority_max(schedpolicy);
  printf("priority in range [%d, %d]\n", minprio, maxprio);

  // an example of a voluntary yeild
  sched_yield();   // no blocking, put at end of runqueue

  return 0;
}
```

# Internal scheduler loop in linux

The scheduler loop in linux is [``` scheduler_tick(void)``` ](http://lxr.free-electrons.com/source/kernel/sched/core.c#L3062). This function is called every Hz ticks

```C
 int cpu = smp_processor_id();
 struct rq *rq = cpu_rq(cpu);  // Get the run queue associated with the CPU. The run queue
 //is where the tasks running on the CPU are located
 
 struct task_struct *curr = rq->curr;// get the current task that is running
 // advance the cloce
 sched_clock_tick();
 //get the lock
 raw_spin_lock(&rq->lock);
 update_rq_clock(rq);
 // calculate the next task to run (depends upon the policy of current task).
 // The scheduling order is to first find if there is a real-time tasks
 // Then find if there is a CFS task.
 // often, the next task will be same as the current task
 // then there will be no context switch
 curr->sched_class->task_tick(rq, curr, 0);
 cpu_load_update_active(rq);
 calc_global_load_tick(rq);
 raw_spin_unlock(&rq->lock);

 perf_event_task_tick();
 
 #ifdef CONFIG_SMP
 // in SMP - we might need to do load balancing
         rq->idle_balance = idle_cpu(cpu);
         trigger_load_balance(rq);
 #endif
         rq_last_tick_reset(rq)
```

The run queue for the CFS class is a red black tree (https://www.ibm.com/developerworks/library/l-completely-fair-scheduler/).  The run queue for real-time class both fifo and RR is a 99 level priority queue. The other 40 user level tasks are for niceness levels -20 to +19.

![Example](http://www.ibm.com/developerworks/linux/library/l-scheduler/figure1.gif)
