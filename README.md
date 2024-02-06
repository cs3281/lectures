# CS 3281: Principles of Operating Systems I (Spring 2024) 
  
**Credit Hours:** 3

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

## Course Description

This is an introductory course on operating systems. You will learn basic concepts in OS design and implementation. The course content will consist of a balance between theory, concepts, and practical hands-on material. Active participation in class discussions and on Piazza is encouraged. There really are no dumb questions.


## Prerequisites

CS 2281 and CS 3251. Because an OS must make effective use of the underlying hardware, students learning OS concepts need to have a basic understanding of computer architecture; this is covered in CS 2281. Programming assignments are a major part of the course, so students must be comfortable with programming and debugging; this is covered in CS 3251.

Programming assignments will be done in C unless otherwise noted. This is not a course on C programming – it is a course on Operating Systems. While some aspects of the C language will be demonstrated in this course, students are expected to familiarize themselves with the language if they are not familiar with it already.


## Instructors

- Andy Gokhale `a.gokhale@vanderbilt.edu` 
- Abhishek Dubey `abhishek.dubey@vanderbilt.edu`
- Shervin Hajiamini `shervin.hajiamini@vanderbilt.edu`

Due to space limitations in classrooms, please attend the section for which you are registered.


## TAs

- Bo Ni `bo.ni@vanderbilt.edu`
- Saman Kittani `saman.r.kittani@vanderbilt.edu`

## Graders
  
- Salomon Dushimirimana `salomon.dushimirimana@vanderbilt.edu`
- Mohammed Khan `mohammed.m.khan@vanderbilt.edu`
- Rana Muhammad Shahroz Khan `rana.muhammad.shahroz.khan@vanderbilt.edu`
- Chuci Liu `chuci.liu@vanderbilt.edu`
- Xiaohan Liu `xiaohan.liu.1@vanderbilt.edu`
- Akash Munagala `akash.munagala@vanderbilt.edu`
- Yurui Xu `yurui.xu@vanderbilt.edu`
- Binh Mai `binh.t.mai@vanderbilt.edu`
- Ilayda Koca `ilayda.koca@vanderbilt.edu`
- Robert Sheng `robert.sheng@vanderbilt.edu`


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
|Monday|1pm - 2pm|FGH 201|Yurui Xu|Grader|
|Monday|2pm - 3pm|FGH 385|Saman Kittani|TA|
|Monday|3:30pm - 4:30pm|FGH 201|Akash Munagala|Grader|
|Monday|4pm - 5pm|FGH 201|Rana Muhammad Shahroz Khan|Grader|
|Tuesday|11am - 12pm|FGH 201|Ilayda Koca|Grader|
|Tuesday|12:30pm - 1:30pm|FGH 201|Rana Muhammad Shahroz Khan|Grader|
|Tuesday|1pm - 3pm|FGH 201|Meraj Khan|Grader|
|Tuesday|1:30pm - 2:30pm|FGH 201|Olivia Liu|Grader|
|Tuesday|4:30pm - 5:30pm|FGH 201|Salomon Dushimirimana|Grader|
|Wednesday|10am - 11am|FGH 201|Robert Sheng|Grader|
|Wednesday|1pm - 2pm|FGH 201|Yurui Xu|Grader|
|Wednesday|1pm - 2pm|FGH 201|Robert Sheng|Grader||Wednesday|2pm - 3pm|Sony A4022|Bo Ni|TA|
|Wednesday|11am - 12pm|Sony A4022|Bo Ni|TA|
|Wednesday|3:30pm - 4:30pm|FGH 201|Akash Munagala|Grader|
|Wednesday|4pm - 5pm|FGH 384|Shervin Hajiamini|Instructor|
|Thursday|11am - 12pm|FGH 201|Ilayda Koca|Grader|
|Thursday|12:30pm - 2:30pm|FGH 201|Lisa Liu|Grader|
|Thursday|12:30pm - 1:30pm|FGH 350|Andy Gokhale|Instructor|
|Thursday|1:30pm - 2:30pm|FGH 201|Olivia Liu|Grader|
|Thursday|4:30pm - 5:30pm|FGH 201|Salomon Dushimirimana|Grader|
|Friday|1pm - 2pm|Zoom (email for link)|Abhishek Dubey|Instructor|
|Friday|10:30am - 12:30pm|FGH 201|Binh Mai|Grader|
|Friday|2pm - 3pm|FGH 385|Saman Kittani|TA|


## Preferred Contact Method

A Discussion Forum exists on Piazza for students to ask questions and give comments on any aspect of the course. The instructors will respond as appropriate, but students are also encouraged to respond themselves. Students can and should be learning from each other in this course, and your engagement in the learning process may be used to contribute to a “Community Score” at the end of the course (see the “Grading” section for more details.) As such, most questions about class material should be posted to Piazza:

[https://piazza.com/vanderbilt/spring2024/cs32815281](https://piazza.com/vanderbilt/spring2024/cs32815281)

To foster an environment in which students learn from one another, instructors generally will not answer questions the day they were posted, nor over the weekend. So, start working on your assignments early so that you can get help from your instructor if you need it!

For questions about course logistics (e.g., absences), please send your instructor an e-mail.


## Important Links

| What | Link    | 
| ------------- |:-------------:| 
| Textbook  | [http://pages.cs.wisc.edu/~remzi/OSTEP/](http://pages.cs.wisc.edu/~remzi/OSTEP/) | 
| Additional Resources | The Linux Programming Interface (TLPI) by Michael Kerrisk <br> Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron | 
| Discussion Forum | [https://piazza.com/vanderbilt/spring2024/cs32815281](https://piazza.com/vanderbilt/spring2024/cs32815281) | 
| Lectures |  [https://github.com/cs3281/lectures](https://github.com/cs3281/lectures) |
| Programming Assignments | [https://classroom.github.com/classrooms/30844110-cs3281-classroom-spring2024](https://classroom.github.com/classrooms/30844110-cs3281-classroom-spring2024) |
| Assignments, Admin | [https://vanderbilt.edu/brightspace](https://vanderbilt.edu/brightspace) |


## Textbook

We are going to follow an online textbook in the course. The book is freely available at [https://pages.cs.wisc.edu/~remzi/OSTEP/](https://pages.cs.wisc.edu/~remzi/OSTEP/). There are also two excellent books that are not required, but are recommended:

* The Linux Programming Interface by Michael Kerrisk
* Computer Systems: A Programmer's Perspective by Bryant and O'Hallaron

During the class, extra reading material may be provided for each lecture via the GitHub lectures repository. It is your responsibility to read the material before the lecture.


## Programming Assignments

Programming assignments are a key component of the learning experience in this class. Through these assignments, you will gain first-hand experience with operating systems and associated concepts. We plan to use a simple learning-focused, open-source operating system called xv6 that was developed at MIT as the basis for these assignments. Copying solutions from the Internet or posting your solutions are both violations of the Honor Code.

The xv6 operating system is best run in a Unix environment, such as MacOS or Linux. You will have access to personal Linux-based Virtual Machines provided by VUIT and hosted on Amazon AWS with all the necessary software already installed to do your assignments, but you may also use your personal machine if you prefer. See the [xv6 Wiki](https://github.com/cs3281/lectures/wiki) page for more details. Note, however, that your assignments will be evaluated in the same environment as that of the VM provided to you, and instructors and staff will not provide support for other environments.

Assignments will usually be given on Tuesday and will be due the next Monday by 11:59pm Central Time. **Assignment collaborations are forbidden unless explicitly permitted.**

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

A midterm exam will be given in-class and use the entire class (The midterm exam date will be published here). Do not be late. The final exam will cover the entire course – it is not merely a second midterm. It will be administered at the official exam time, which depends upon your section. Refer to the [official exam schedule](https://registrar.vanderbilt.edu/documents/Spring_2024_exam_schedule.pdf).

For each exam, you may prepare a single standard 8.5”x11” piece of notebook paper with your handwritten notes to use during the exam. Importantly, these notes must be entirely *handwritten* directly on the paper *by you*. You cannot photocopy others’ notes or print notes that you wrote by hand on a tablet. You cannot literally cut-and-paste figures from the textbook or other sources, but, if you so choose, you may reproduce them by hand yourself on your note sheet. Note sheets will be collected, and violations of these terms will be considered a violation of the Honor Code.


## In-class Assessments

There will be a series of *brief* and hopefully straightforward in-class assessments, which may be conducted over an online tool such as TopHat. The main objectives of these assessments are to encourage (and measure) class attendance and to gauge understanding of the readings before class. They also serve as a means of evaluating how well the class has understood concepts before moving on to new material.

To take some of the stress out of these assessments, you do not need a perfect score to get full credit for the assessment. The goal is for scores over approximately 80% to earn full credit, but depending upon the assessment, that bar may be lowered at the instructor’s discretion. For example, if there are fewer than five questions, you will receive full credit if you get at most one wrong. If you do not score points sufficient to reach the full-credit bar, your score will be relative to that bar. For example, if an assessment has four questions, you will need three to score full credit. If you only get two correct, your score will be 2/3 = 66%.

Attendance in class is expected. Please inform the instructor ahead of time if you have an excused absence.


## Participation and Professionalism

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
| In-Class Assessments              | 10%           |
| Mid-Term Exam                     | 15%           |
| Final Exam                        | 25%           |
| Participation and Professionalism | +/-2%         |


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
- Memory management, virtual memory, paging, dynamic linking and loading of libraries
- Concurrency, threads, mutual exclusion (mutex and condition variables), including process synchronization and deadlocks
- Interprocess communication,  signals, message queues, pipes, shared memory, sockets
- File systems
- Virtual machines
- Security
