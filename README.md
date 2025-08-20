# CS 3281: Principles of Operating Systems I (Fall 2025) 
  
**Credit Hours:** 3

<!---
## Lecture Summary and additional notes

We are providing a quick summary of the lectures - some additional notes whenever they have been made available for reference here.

| Concept | Lecture Slides | Additional Notes | Examples|
| ------------- | ------------- |------------- |------------- |
|Understanding Shell| External Reference| https://linuxcommand.org/index.php and the missing semester notes -- see below| External Reference|
|Some Basic Computing Concepts| External Reference| https://missing.csail.mit.edu/|External Reference - go through the missing semester notes and videos at your pace|
| Executable Files, Compilation and Linking, Makefile, Function Pointers, C Overview, Cmake, Architecture| [Lecture 2](https://github.com/cs3281/lectures/blob/main/lecture-02/L02-virtualization.pdf)| [lecture-02](https://github.com/cs3281/lectures/blob/main/lecture-02/Readme.md)| [c-tutorial](https://github.com/cs3281/examples/tree/main/c-tutorial)|
| Process Control Flow, Environment Variables, Privilege Levels | [lecture 03](https://github.com/cs3281/lectures/blob/main/lecture-03/L03-exceptional-control.pdf)|[readme](https://github.com/cs3281/lectures/blob/main/lecture-03/readme.md)|[exceptions](https://github.com/cs3281/examples/tree/main/exceptions)|
| Process Creation and Anomatomy, fork and exec, basic termination| [lecture 04](https://github.com/cs3281/lectures/blob/main/lecture-04/L04-process-creation.pdf)|[readme](https://github.com/cs3281/lectures/blob/main/lecture-04/readme.md)|[examples](https://github.com/cs3281/examples/tree/main/processManagement) look at basic fork, basic exec, advanced execvpexample|
| Signals, Wait, WaitPid, Process Termination| [Lecture 05](https://github.com/cs3281/lectures/blob/main/lecture-05/L05-process-termination.pdf)|[readme](https://github.com/cs3281/lectures/blob/main/lecture-05/readme.md) pay attention to the wait flowchart and signal handler| [examples](https://github.com/cs3281/examples/tree/main/processManagement) pay attention to sigchld and basic signal and wait examples|
| Virtual Memory, Paging |[Lecture 06](lecture-06/CS3281-Processes-lecture6.pptx) and [Lecture 07](lecture-07/CS3281-Processes-lecture7.pptx)|[readme](lecture-07/readme.md)|[examples](https://github.com/cs3281/examples/tree/main/memorymanagement) look at malloc and own malloc implementation|
| Threads and Concurrency | [Lecture 08](https://github.com/cs3281/lectures/tree/main/lecture-08)| [readme](/lecture-08/readme.md)| [examples](https://github.com/cs3281/examples/tree/main/threads)|
| Synchronization and Condition Variables | [lecture 09](https://github.com/cs3281/lectures/tree/main/lecture-09)| [Readme](https://github.com/cs3281/lectures/blob/main/lecture-09/readme.md)|[examples](https://github.com/cs3281/examples/tree/main/threads/race_condition) and [semaphores](https://github.com/cs3281/examples/tree/main/threads/semaphore)| 
| Condition Variables |   [lecture 10](https://github.com/cs3281/lectures/tree/main/lecture-10) |   [Readme 2](https://github.com/cs3281/lectures/blob/main/lecture-10/readme.md) | [examples](https://github.com/cs3281/examples/tree/main/threads/conditionvariables)|
| Scheduling including overview of Linux Policies | [lecture 12](https://github.com/cs3281/lectures/tree/main/lecture-12) | [Readme](https://github.com/cs3281/lectures/tree/main/lecture-12) | [examples](https://github.com/cs3281/examples/tree/main/scheduling)|
| Real time scheduling | [lecture 13](https://github.com/cs3281/lectures/tree/main/lecture-13)| [Readme](https://github.com/cs3281/lectures/tree/main/lecture-13)||
| InterProcess Communications | [lecture 14](https://github.com/cs3281/lectures/tree/main/lecture-14)| [Readme](https://github.com/cs3281/lectures/tree/main/lecture-14)|[example mqueue](https://github.com/cs3281/examples/tree/main/mqueue) [mequeue sending integers](https://github.com/cs3281/examples/tree/main/mqueue_with_int) [dup2](https://github.com/cs3281/examples/tree/main/dup2) [pipes](https://github.com/cs3281/examples/tree/main/pipe)|
| network and sockets | [lecture 15](https://github.com/cs3281/lectures/tree/main/lecture-15) [lecture 16](https://github.com/cs3281/lectures/tree/main/lecture-16)| [Readme](https://github.com/cs3281/lectures/tree/main/lecture-16)|[examples](https://github.com/cs3281/examples/tree/main/sockets) [c example](https://github.com/cs3281/examples/tree/main/sockets-2)| 
| Devices | [lecture 18](https://github.com/cs3281/lectures/tree/main/lecture-18)| [Readme](https://github.com/cs3281/lectures/tree/main/lecture-18)||
| Files | [lecture 19](https://github.com/cs3281/lectures/tree/main/lecture-19)| [Readme](https://github.com/cs3281/lectures/tree/main/lecture-18)|[files and directory](https://github.com/cs3281/examples/tree/main/filesAndDirs) [file descriptors](https://github.com/cs3281/examples/tree/main/fileDescriptors) [file system watch](https://github.com/cs3281/examples/tree/main/fileSystemWatch)|
|security|[lecture 20](https://github.com/cs3281/lectures/tree/main/lecture-20)||
--->

This is an introductory course on operating systems. You will learn basic concepts in OS design and implementation. The course content will consist of a balance between theory, concepts, and practical hands-on material. Active participation in class discussions and on Piazza is encouraged. There really are no dumb questions.


## Prerequisites

CS 2281 and CS 3251. Because an OS must make effective use of the underlying hardware, students learning OS concepts need to have a basic understanding of computer architecture; this is covered in CS 2281. Programming assignments are a major part of the course, so students must be comfortable with programming and debugging; this is covered in CS 3251.

Programming assignments will be done in C unless otherwise noted. This is not a course on C programming – it is a course on Operating Systems. While some aspects of the C language will be demonstrated in this course, students are expected to familiarize themselves with the language if they are not familiar with it already.


## Instructors

- Mohammad Kavousi  `mohammad.kavousi@vanderbilt.edu`
- Shervin Hajiamini `shervin.hajiamini@vanderbilt.edu`

Due to space limitations in classrooms, please attend the section for which you are registered.


## TAs

## Graders

## Office Hours

Office hours are an opportunity for instructors, TAs, and graders to help you **learn** course material and concepts. Programming assignments are designed to help you learn course concepts and skills through practical experience and application. For these assignments to accomplish this goal, you must be engaged and invested in learning through doing. Experimenting, debugging, and struggling to get assignments to work is part of that learning process, as when you figure things out, you will better understand how and why things work the way they do.

Giving out solutions or otherwise solving problems for students who have not invested in the learning experience robs those students of part of that learning experience. It is in this spirit that we adopt the following guidelines for office hours:

*	Come prepared to explain what you don’t understand. Reflect on the challenges you are facing, see what you have learned and what you have concluded in the process of understanding the problem.
*	Carefully consider the expected behavior of the program on different inputs. What inputs is your program failing on? What inputs is it succeeding on? Sometimes this mental exercise can help you identify and solve the problem yourself.
*	Come prepared to explain what you have tried to fix the problem. This shows that you have engaged in the learning experience authentically. You have learned what doesn’t work, and hopefully why!
*	Prepare your code for office hours. The office hours host will need to understand your code before they can help you to learn how to solve the problem. This means your code should compile, and you should use good coding practices including comments, functions, and well-chosen variable names. Remove any superfluous printouts or code from things you tried that did not work.

Examples of unacceptable office hour conduct include:

*	Coming with code that doesn’t compile. You should at least be able to get your code to compile, even if it doesn’t work properly. We can’t easily evaluate how or why it isn’t working properly without seeing what the code is doing.
*	Asking something akin to “Why doesn’t this work?” or “What is this error?” Instead, try something to the effect of “I am getting this error message XXX, which I think means that YYY is happening. However, it is still occurring after I tried this and that. Can you help me understand what this error message means, I’m not sure I understand the problem.”

For a more thorough guide on how to make effective use of office hours, you are encouraged to read the following: [https://www2.seas.gwu.edu/~gparmer/resources/2021-09-20-Office-Hours-HOWTO.html](https://www2.seas.gwu.edu/~gparmer/resources/2021-09-20-Office-Hours-HOWTO.html)

Office hour times are listed below:


|Day|Time|Location|Person|Role|
| ------------- |:-------------:| :-------------:|:-------------:|:-------------:|
|||||Grader|
|||||Instructor|
|||||TA|

## Preferred Contact Method

A Discussion Forum exists on Piazza for students to ask questions and give comments on any aspect of the course. The instructors will respond as appropriate, but students are also encouraged to respond themselves. Students can and should be learning from each other in this course, and your engagement in the learning process may be used to contribute to a “Community Score” at the end of the course (see the “Grading” section for more details.) As such, most questions about class material should be posted to Piazza:
[https://piazza.com/vanderbilt/fall2025/cs32815281](https://piazza.com/vanderbilt/fall2025/cs32815281)

To foster an environment in which students learn from one another, instructors generally will not answer questions the day they were posted, nor over the weekend. So, start working on your assignments early so that you can get help from your instructor if you need it!

For questions about course logistics (e.g., absences), please send your instructor an e-mail.


## Important Links

| What | Link    | 
| ------------- |:-------------:| 
| Textbook  | [http://pages.cs.wisc.edu/~remzi/OSTEP/](http://pages.cs.wisc.edu/~remzi/OSTEP/) |
| zybook  | [learn.zybooks.com/zybook/VANDERBILTCS3281_5281HajiaminiFall2025](learn.zybooks.com/zybook/VANDERBILTCS3281_5281HajiaminiFall2025) |
| Additional Resources | The Linux Programming Interface (TLPI) by Michael Kerrisk <br> Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron | 
| Discussion Forum | [https://piazza.com/vanderbilt/spring2025/cs32815281](https://piazza.com/vanderbilt/spring2025/cs32815281) | 
| Lectures |  [https://github.com/cs3281/lectures](https://github.com/cs3281/lectures) |
| Programming Assignments | [https://classroom.github.com/classrooms/30844110-cs3281-classroom-spring2025](https://classroom.github.com/classrooms/30844110-cs3281-classroom-spring2025) |
| Announcements, grades | [https://vanderbilt.edu/brightspace](https://vanderbilt.edu/brightspace) |


## Books

We are going to follow a textbook in the course. The book is freely available at [https://pages.cs.wisc.edu/~remzi/OSTEP/](https://pages.cs.wisc.edu/~remzi/OSTEP/). 

We also use an online book (zybook). This book explains the lecture contents with visualizations. In addition, it provides interactive exercises. You will do exercises from assigned chapters regularly. The deadline of all zybook activities is 11:59pm on the due dates. No late zybook activities are accepted without valid evidence for the serious medical problems or documented emergencies. You will receive full credit for the zybook activities if you complete >= 90% over all assigned activities.

To subscribe for the zybook, visit learn.zybooks.com and enter VANDERBILTCS3281_5281HajiaminiFall2025 for code. The subscription costs $77.

There are also two excellent books that are not required, but are recommended:

* The Linux Programming Interface by Michael Kerrisk
* Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron

During the class, extra reading material may be provided for each lecture via the GitHub lectures repository. It is your responsibility to read the material before the lecture.


## Programming Assignments

Programming assignments are a key component of the learning experience in this class. Through these assignments, you will gain first-hand experience with operating systems and associated concepts. You will develop and run the assignments in Ubuntu. The assignments will be also graded in Ubuntu. Copying solutions from the Internet or posting your solutions are both violations of the Honor Code.

Assignments will usually be given on Monday or Tuesday and will be due the next Monday by 11:59pm Central Time. **Assignment collaborations are forbidden unless explicitly permitted.**

Any submission that does not compile will be penalized at least **50%**. The instructors and graders reserve the right to give a **0%** for any assignment that does not have a substantive solution to the assignment – in other words you cannot earn points by merely submitting the provided code.


## ChatGPT and Generative AI

ChatGPT and other generative AI techniques such as Co-Pilot are transformative new technologies that we must explore how to productively use in an educational environment. On one hand, these technologies can aid in the learning process by helping you make progress when you are completely unable to move forward. On the other hand, if they solve all your problems for you, then you have been robbed of the learning experience. Nonetheless, these technologies are here to stay, and their effective use will boost the productivity of professionals, so we want to prepare you to use these tools in your careers. We are therefore adopting an **experimental** new policy for the use of AI tools.

You **may** use AI tools to aid and assist you in working on your programming assignments. However, **any use of AI tools must be disclosed**. This disclosure is a report that includes what AI tools you used, what it helped you with, and what it could not help you with. **You will not be penalized for using AI tools**, but you may be penalized for inadequate or incomplete disclosure. So be honest!

This disclosure serves three purposes. First, it helps the instructors to better understand how to teach in this new era of AI. Second, it is part of our Honor Code policy. Any use of AI tools without disclosure will be considered an Honor Code violation. And third, we hope that by reflecting upon what worked and what didn’t, you will become more proficient users of these tools!

The instructors reserve the right to change or amend this experimental policy at any time.


## Late submission policy

Submissions are due by midnight on the day listed in the assignment description. Late submissions will be penalized with an automatic 20 percentage-point penalty per day.

Assignments submitted more than two days after the due date will not be accepted. For example: if an assignment is due by 11:59pm on Monday night, it will not be accepted after 11:59pm Wednesday night.


## Late days

You have a total of four late days that you can use across programming assignments as you wish. A maximum of two late days can be used on a given programming assignment. For example, if an assignment is due at 11:59pm on Monday evening, you can use two of your late days to submit that assignment by 11:59pm on Wednesday with no penalty.

The expectation is that assignments will be submitted by the due date. The late-day policy is designed to give you flexibility in the case of unexpected circumstances, without having to negotiate a deadline extension. Therefore, requests for additional late days will not be granted. Use your late days judiciously, and it is recommended to preserve them as “insurance.”

To indicate that you are using late days on an assignment, please push a file named `late_days.md` to the top-level directory of your assignment repo with a line stating whether you’re using one or two late days.


## Regrade Requests

The graders and instructors are human and occasionally make mistakes, despite our best efforts and intentions. We do not want such mistakes to negatively impact your grade; however, regrading assessments takes time, and should not be requested merely because you are unsatisfied with your grade. For this reason, if your request is deemed frivolous or does not find fault in the original grading, the instructors reserve the right to penalize by forfeiting one late day. If you do not have any remaining late days and your regrade request is deemed frivolous, one of your previously used late days will be forfeited, and an assignment previously submitted late will receive the late-day penalty.

This rule is inspired by the NFL review rules, in which you lose a timeout if you challenge a call that is not overturned. Similarly, there must be “irrefutable evidence” to overturn a grade. Sometimes grading is subjective, and therefore, if the original grade is fair or valid, the “ruling on the field stands”; that is, the original grade remains, and the late day is forfeit.


## Exams
There will be two in-class exams during the semester and no final exam. The first exam will be given in the week of October 6th and the second exam is in the last class of CS3281 for the section that you are enrolled in. Do not be late. 

For each exam, you may prepare a single standard 8.5”x11” piece of notebook paper with your handwritten notes to use during the exam. Importantly, these notes must be entirely *handwritten* directly on the paper *by you*. You cannot photocopy others’ notes or print notes that you wrote by hand on a tablet. You cannot literally cut-and-paste figures from the textbook or other sources, but, if you so choose, you may reproduce them by hand yourself on your note sheet. Note sheets will be collected, and violations of these terms will be considered a violation of the Honor Code.


## Quizzes

There will be a series of regular take-home assessments, which will be conducted over Brightspace. The main objective of these assessments is to gauge understanding of the lecture material.

# Attendance and participation

Attendance will be taken in each lecture. You only need to earn a score of >=75% of lecture attendance to earn the full credits (2%) for your final grade. In our classes, we will hold Q&A activities through Top Hat. You are expected to participate in Top Hat activities of each class.

## Professionalism

This class will be more enjoyable and productive for all involved if students participate, maintain proper etiquette, and are professional. Examples of inappropriate and unprofessional classroom etiquette are:

* Commonly arriving late or coming and going during class
* Talking, eating, or otherwise making unnecessary noise that may interfere with the learning environment of others
* Not paying attention, e.g., browsing the web, doing other homework, sleeping, or otherwise being inattentive in class. We notice this!

The instructor reserves the right to round up the grades of students who are professional, responsible, and engaged in the class, and similarly deduct points for students who are not.


## Evaluation

The following grading criteria are subject to change. The instructor reserves the right to apply a curve to the final grades.


## Grading Criteria

| Category                          | Percentage    |
| --------------------------------- |:-------------:| 
| Programming Assignments           | 50%           |
| Mid-Term Exam 1                   | 20%           |
| Mid-Term Exam 2                   | 20%           |
| Take-home Quizzes                 | 5%            |
| zybook activities                 | 3%            |
| Attendance & participation        | 2%            |


## Honor Code

The Vanderbilt Honor Code will govern all course assessments. Students are expected to familiarize themselves with the Honor Code:

[https://www.vanderbilt.edu/student_handbook/the-honor-system/](https://www.vanderbilt.edu/student_handbook/the-honor-system/)

ANY VIOLATIONS will result in the case being reported to the Honor Council. You are welcome to refer to the online sources for your assignments; however, you must not copy the code and must provide citation of the source of inspiration if you refer to online sites. Notably, the following are expressly prohibited, and will be reported to the Honor Council:

* Copying homework solutions from peers in violation of any stated collaboration policies
* Copying homework solutions from the internet (Chegg, stack overflow, etc.)
* Copying homework solutions of previous students at Vanderbilt or other institutions
* Reading off the exams of nearby students or unapproved resources (e.g., phone, notes in violation of the above exam-notes policy)
* Using ChatGPT or other AI tools without disclosing their use (see the above policies)

There is absolutely **zero tolerance** for plagiarism or Honor Code violations. If you have questions regarding what is or is not acceptable, please ask.


## Letter Grade Distribution

| Score         | Letter        |
| ------------- |:-------------:| 
| >= 93.00      | A             |
| 90.00 - 92.99 | A-            |
| 87.00 - 89.99 | B+            |
| 83.00 - 86.99 | B             |
| 80.00 - 82.99 | B-            |
| 77.00 - 79.99 | C+            |
| 73.00 - 76.99 | C             |
| 70.00 - 72.99 | C-            |
| 67.00 - 69.99 | D+            |
| 63.00 - 66.99 | D             |
| 60.00 - 62.99 | D-            |
| <= 59.99      | F             |


## Disability Statement

Vanderbilt is committed to equal opportunity for students with disabilities. If you have a physical or learning disability, you should ask the Opportunity Development Center to assist you in identifying yourself to your instructors as having a disability, so that appropriate accommodation may be provided. Without notification, your instructors assume that you have no disabilities or seek no accommodation.


## Topics

The course will cover the following topics throughout the semester:

- History of operating systems
- Architecture of a modern computing system
- System calls
- Interrupts and interrupt handling
- Process creation, management, and termination
- Scheduling policies and mechanisms
- Memory management, virtual memory, and paging
- Concurrency, threads, mutual exclusion (mutex and condition variables), including process synchronization and deadlocks
- Interprocess communication,  signals, pipes, shared memory, sockets
- File systems
