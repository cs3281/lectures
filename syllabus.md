# CS 3281: Principles of Operating Systems I (Spring 2023) 
  
**Credit Hours:** 3

## Course Description

This is an introductory course on operating systems. You will learn basic concepts in OS design and implementation. The course content will consist of a balance between theory, concepts, and practical hands-on material. Active participation in class discussions and on Piazza is encouraged. There really are no dumb questions.

## Prerequisites

EECE 2123 and CS 3251. Because an OS must make effective use of the underlying hardware, students learning OS concepts need to have a basic understanding of computer architecture; this is covered in EECE 2123. Programming assignments are a major part of the course, and so students must be comfortable with programming and debugging; this is covered in CS 3251. Most of the programming will be done in C.

## Instructors

- Daniel Balasubramanian `daniel.a.balasubramanian@vanderbilt.edu` 
- Shervin Hajiamini `shervin.hajiamini@vanderbilt.edu`

Due to space limitations in classrooms, please attend the section for which you are registered.

## Teaching assistants

- Oluwatito(Tito) Ebiwonjumi `oluwatito.p.ebiwonjumi@vanderbilt.edu` 

## Graders

- Ritvik Singh `ritvik.singh@vanderbilt.edu`
- Lucas Smulders `lucas.smulders@vanderbilt.edu`
- Rohit Khurana `rohit.khurana@vanderbilt.edu`
- Wesley Minton `wesley.a.minton@vanderbilt.edu`
- Xiaoliang(Toby) Zhu `xiaoliang.zhu@vanderbilt.edu`

## Instructor, TA, and Grader Office Hours

| Day | Time    | Location | Person  |
| ------------- |:-------------:| :-------------:|:-------------:|
|Monday|1:15pm - 2:15pm|FGH 384|Shervin Hajiamini|
|Monday|12:30pm - 2pm|FGH 201|Tito Ebiwonjumi|
|Monday|2pm - 3:30pm|FGH 201|Toby Zhu|
|Monday|3pm - 4pm|[Zoom](https://vanderbilt.zoom.us/j/7262771408)|Wesley Minton|
|Tuesday|3pm - 4pm|FGH 201|Lucas Smulders|
|Tuesday|7pm - 8pm|FGH 201|Rohit Khurana|
|Wednesday|1:15pm - 2:15pm|FGH 384|Shervin Hajiamini|
|Wednesday|12:30pm - 2pm|FGH 201|Tito Ebiwonjumi|
|Wednesday|2pm - 3pm|FGH 201|Toby Zhu|
|Wednesday|3pm - 4pm|[Zoom](https://vanderbilt.zoom.us/j/7262771408)|Wesley Minton|
|Wednesday|4:30pm - 6:30pm|[Zoom](https://vanderbilt.zoom.us/j/96350668989)|Ritvik Singh|
|Thursday|7pm - 8pm|FGH 201|Rohit Khurana|
|Friday|1:15pm - 2:15pm|FGH 384|Shervin Hajiamini|
|Friday|1:30pm - 3pm|FGH 201|Lucas Smulders|

Please read the following guide for an explanation of how to make effective use of office hours: [https://www2.seas.gwu.edu/~gparmer/resources/2021-09-20-Office-Hours-HOWTO.html](https://www2.seas.gwu.edu/~gparmer/resources/2021-09-20-Office-Hours-HOWTO.html)

## Preferred Contact Method

For general questions about class material that may be beneficial to others, please create a post on Piazza:

[https://piazza.com/class/lcniyvg2buj1tc](https://piazza.com/class/lcniyvg2buj1tc)

For questions about course logistics (e.g., absences), please send your instructor an e-mail. Note that we may have pop quizzes in class and unexplained absences will not be excused.

## Important Links

| What | Link    | 
| ------------- |:-------------:| 
| Textbook  | [http://pages.cs.wisc.edu/~remzi/OSTEP/](http://pages.cs.wisc.edu/~remzi/OSTEP/) | 
| Recommended books | The Linux Programming Interface (TLPI) by Michael Kerrisk <br> Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron | 
| Announcments, discussion forum | [https://piazza.com/class/lcniyvg2buj1tc](https://piazza.com/class/lcniyvg2buj1tc) | 
| Lectures and course notes |  [https://github.com/cs3281/lectures](https://github.com/cs3281/lectures) |
| Assignments |  Announced on Brightspace; submitted on GitHub |

## Textbook

We are going to follow an online textbook in the course. The book is freely available at [https://pages.cs.wisc.edu/~remzi/OSTEP/](https://pages.cs.wisc.edu/~remzi/OSTEP/)

There are also two excellent books that are not required, but are recommended:

* The Linux Programming Interface by Michael Kerrisk
* Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron

During the class extra reading material will be provided for each lecture via the GitHub repository. It is your responsibility to read the material before the lecture as there can be a pop quiz at the start of the class. 

## Late submission policy

Submissions are due by midnight on the day listed in the assignment description. Late submissions will be penalized with an automatic 20 percent penalty per day (applied relative to the graded score for the submission).

Assignments submitted more than two days after the due date will not be accepted. For example: if an assignment is due by 11:59pm on Monday night, it will not be accepted after 11:59pm Wednesday night.

## Late days

You have a total of 7 late days that you can use across programming assignments as you wish. A maximum of two late days can be used on a given programing assignment. For example: if an assignment is due at 11:59pm on Monday evening, you can use two of your late days to submit that assignment by 11:59pm on Wednesday with no penalty.

To indicate that use are using late days on an assignment, please push a file named ```late_days.md``` to the top-level directory of your assignment repo with a line stating whether you're using one or two late days.

**No collaborations unless explicitly permitted**. 

The Vanderbilt Honor Code will govern work done. ANY VIOLATIONS WILL RESULT in the case to be reported to the honor council. You are welcome to refer to the online sources for your assignments. However, you must not copy the code and must provide citation of the source of inspiration if do refer to the online sites. All work will be submitted via GitHub.

In particular, do not plagarize your programming assignments.

## Programming Assignments 

Programming assignments will be tested using Ubuntu and are expected to be developed and run in that environment. You should expect to receive on an average one assignment a week. Assignments will usually be given on a Tuesday and will be due the next Monday by 11:59pm central time.  
The instructions for setting up the environment using VirtualBox are available in [the VM Setup document](./vmsetup/vmsetup.md). However, you're free to run whatever Virtual Machine Monitor software you would like, such as UTM, VMWare Fusion, Parallels, or QEMU. 
Any submission that does not compile will be penalized **50%**. 

## Reading Quizzes

We plan to have short reading quizzes that you will take on Brightspace before class. The plan is to have these due on Wednesday nights by 11:59pm.

## Evaluation

The following grading criteria are subject to change. The instructor reserves the right to apply a curve to the final grades.

## Grading Criteria

| Category        | Percentage  |
| ------------- |:-------------:| 
| Programming Assignments | 60% |
| Mid-term Exam I | 10% |
| Mid-term Exam II | 10% |
| Final Project | 20% |

## Letter Grade Distribution

| Score        | Letter  |
| ------------- |:-------------:| 
| >= 93.00    |   A      |
| 90.00 - 92.99  |  A-   |
| 87.00 - 89.99 | B+     |
| 83.00 - 86.99  | B     |
| 80.00 - 82.99  | B-     |
| 77.00 - 79.99  | C+  |
| 73.00 - 76.99  | C  |
| 70.00 - 72.99  | C-  |
| 67.00 - 69.99  | D+  |
| 63.00 - 66.99  | D  |
| 60.00 - 62.99  | D-  |
| <= 59.99   |  F  |


## Disability Statement

Vanderbilt is committed to equal opportunity
for students with disabilities. If you have a physical or learning
disability, you should ask the Opportunity Development Center to assist
you in identifying yourself to your instructors as having a disability,
so that appropriate accommodation may be provided. Without notification,
your instructors assume that you have no disabilities or seek no
accommodation.

## Emergency Evacuation Plan

In the event of a fire or other emergency,
the occupants of this class should collect their coats and personal
belongings and leave the building using the stairs. VANDERBILT
UNIVERSITY POLICY FORBIDS REENTRY TO A BUILDING IN WHICH AN ALARM HAS
OCCURRED WITHOUT AUTHORIZATION BY VANDERBILT SECURITY. If, in
consequence of a disability, you anticipate the need for assistance,
please discuss that need with the instructors.

If a tornado siren is heard, please go to the nearest interior hallway or interior rooms away from windows.

## Topics

The course will cover the following topics throughout the semester:

-	History of operating systems
-	Architecture of a modern computing system
-	System calls
-	Interrupts and interrupt handling
-	Process creation, management, and termination
-	Scheduling policies and mechanisms
-	Memory management, virtual memory, paging, dynamic linking and loading of libraries
-	Concurrency, threads, mutual exclusion (mutex and condition variables), including process synchronization and deadlocks
-	Interprocess communication,  signals, message queues, pipes, shared memory, sockets
-	File systems
-   Security

## Mandatory Reporter Obligations

All University faculty and administrators are mandatory reporters.  What this means is that all Faculty, including us, must report allegations of sexual misconduct and intimate partner violence to the Title IX Coordinator.  In addition, all faculty are obligated to report any allegations of discrimination to the Title IX Coordinator.

We are very willing to discuss with you such incidents should you so desire, but we can only do so in the context of us both understanding my reporting obligations.  If you want to talk with someone in confidence, officials in the Student Health Center, the University Counseling Center, and officials in the Office of the Chaplain and Religious Life (when acting as clergy) can all maintain confidentiality.  In addition, officials in the Project Safe Center (Crisis Hotline: 615-322-7233) have limited confidentiality, in that they have to report the incidents they are told of, but can do so without providing identifying information about the victim(s).
