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
