#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {

struct sched_param p;
struct timespec ts;
int schedpolicy;
int prio;

p.sched_priority = 0;

if(sched_setscheduler((pid_t)0, SCHED_RR, &p) == -1) {
 perror("Error");	
}

if(sched_rr_get_interval((pid_t)0, &ts) != -1) {
 printf("quantum=%ld secs %ld nanosecs\n", ts.tv_sec, ts.tv_nsec); 	
}

schedpolicy = sched_getscheduler((pid_t)0);
switch(schedpolicy) {
  case SCHED_FIFO:
    printf("SCHED_FIFO\n");
    break;

  case SCHED_RR:
    printf("SCHED_RR\n");
    break;

  case SCHED_BATCH:
    printf("SCHED_BATCH\n");
    break;  

  case SCHED_OTHER:
    printf("SCHED_OTHER\n");
    break;

  case SCHED_IDLE:
    printf("SCHED_IDLE\n");
    break;   
  
  default:
    printf("unknown scheduling policy\n");    
}

prio = getpriority(PRIO_PROCESS, (id_t)0);
printf("process priority is %d\n", prio);

setpriority(PRIO_PROCESS, (pid_t)0, 10);

prio = getpriority(PRIO_PROCESS, 0);
printf("process priority is %d\n", prio);

printf("range[%d,%d]\n", sched_get_priority_min(schedpolicy), sched_get_priority_max(schedpolicy));


}
