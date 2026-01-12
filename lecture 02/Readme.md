# System Call and Strace

1. https://github.com/cs3281/examples/tree/main/c-tutorial
2. Then see https://github.com/cs3281/examples/tree/main/systemcall
3. Run strace on the program from step 2.

To run the programs you will need cmake and gcc on your AWS linux machine.

# Shell Commands 
Additionally we will encourage you to revisit some of the key commands that are required to use the Linux systems

1. chmod -- change the ownership permission of a file and be able to execute a file. Please review this [medium article](https://medium.com/@deepeshjaiswal6734/linux-file-permissions-tutorial-for-beginners-d539c1acad35#:~:text=chmod%20and%20chown%20are%20both,file%20permissions%20and%20ownership%20respectively.&text=Here%2C%20mode%20represents%20the%20desired,whose%20permissions%20are%20being%20modified.)
2. ls -l -- look at following [medium article](https://medium.com/@akintolamayode1/understanding-ls-l-c-command-in-linux-4f9891679fd5)
3. Understand what does it mean for a file to be executable in Linux.
4. Finally review Makefiles and Pointers Below


# Concept of Executable Files

- An executable file in linux is either a binary (compiled)program or a script that can be interpreted by a shell.

###Shell Script
Shell is a executable binary program that can read the scripts and perform the work described by commands specified in the shell script. You also interact with the shell when you enter keyboard strokes on the command line. An example shell script would contain the following commands:

```bash
#!/bin/sh
echo "Hello World"
echo "you are working in the `pwd`" directory
```

The first line in the shell script indicates the interpreter that the command line will use when you execute the script. The second and third lines are statements that print the contents of the statements in quotes. Note that `pwd` is a shell shortcut to tell to run a command and then combine its output (directory name in this case) with rest of the string.  To run the program execute $./hello.sh . Here './' indicates the path where the interpeter can find the "program". One single dot means current working directory. Two dots mean parent directory.

Here is the output 
```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ ./hello.sh
bash: ./hello.sh: Permission denied
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

The error permission denied is thrown by the command line because the shell script has not been marked as executable. This is shown by the following command

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ ls -l
total 4
-rw-rw-r-- 1 vagrant vagrant 75 Jan 12 03:53 hello.sh
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

Note the '-rw-rw-r--' in the first column. These are called permission bits. The permission bits are divided into three sections rw- rw- and the third rw- (from left to right). The first permission section is for user who is the owner of the file (second column in illustration above). The second permission section is for all users who belong to the group to which the owner of the file belongs to (shown as vagrant -3rd column in the illustration above.). The third section is for  everyone else. 

So as shown in the privleges the owner of the file can read it and write to it. All users in the groups of vagrant can read and write to the hello.sh and everyone else can read the hello.sh. To add the execute permission we need to execute the following command: chmod +x hello.sh. This adds the execute permission for the owner, the group and everyone else.

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ chmod +x hello.sh 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ ls -l
total 4
-rwxrwxr-x 1 vagrant vagrant 75 Jan 12 03:53 hello.sh
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

To provide permission to only the owner use chmod u+x hello.sh (g+x will add the permission to the group, gu+x will add permission to the group and the owner. Note that -x removes the execute permission)

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ chmod u+x hello.sh 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ ls -l
total 4
-rwxrw-r-- 1 vagrant vagrant 75 Jan 12 03:53 hello.sh
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

okay, so now lets run the script. You can see the output.

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ ./hello.sh 
Hello World
you are working in the /home/vagrant/lectures/lecture-02/examples/shell directory
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

Note that at anytime you can see the content of the shell script by using the cat command.

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ cat hello.sh 
#!/bin/sh
echo "Hello World"
echo "you are working in the `pwd`" directory
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/shell$ 
```

## Concept of compiled executable program

Unlike a  script that is interpreted by the shell, a compiled program is a binary file that is directly executed by the operating system kernel. The binary file contains a "compiled and linked program".  This compiled program contains the assembly opcodes that can be interpreted by the CPU. 

The program is often written in a higher level programming language, for example 'C' or  'C++'.  You compile it using another executable program called gcc  (to compile C) , or g++ (to compiler c++). There are several other compilers , for example  llvm. 

Here is a hello world program called 1-hello.c.

```C
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$  cat 1-hello.c 
#include <stdio.h>

/*
 For more explanation, see the console and exits.
 * page 5 of the K & R book. This is the book if you want to have it https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628
 */ 
int 
main(int argc, char *argv[])
{
	
	printf("Hello, world!\n");
	return 0;
	
} 
```
 Note that I am using the cat executable program to see the contents of the C program , which is not a shell script. Trying to execute it as a shell script will result in this funny output. If you get this error, then you know you tried to execute a C program as a shell script. The shell does not know how to interpret the text insider the C program. This is a very common problem that we have seen at the start of the class. Do not repeat this mistake.
 
 ```
 vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ ./1-hello.c 
./1-hello.c: line 2: $'\r': command not found
./1-hello.c: line 3: /bin: Is a directory
./1-hello.c: line 4: 1-hello.c: command not found
./1-hello.c: line 5: 1-hello.c: command not found
./1-hello.c: line 5: R: command not found
./1-hello.c: line 6: tests/: Is a directory
./1-hello.c: line 7: int: command not found
./1-hello.c: line 8: syntax error near unexpected token `int'
./1-hello.c: line 8: `main(int argc, char *argv[])'
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ 
```

Okay, so how do we run a C program. For that we have to compile it. You can compile the program as shown in the following illustration.

```bash
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ gcc -o hello 1-hello.c 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ 
```

The gcc compile takes a command line argument '-o', which tells it the name of the compiled program. The last line is the program to compile. If the compilation succeeded, you will see a file called hello (with execute permissions) in your directory.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ ls -l
total 40
-rwxrwxr-x 1 vagrant vagrant  223 Sep 15 19:31 1-hello.c
-rwxrwxr-x 1 vagrant vagrant 8608 Jan 12 04:17 hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ 
```

Now you can run hello.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ ./hello 
Hello, world!
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/c-tutorial$ 
```
## Compiling a program where source code is split across multiple files.

Often we can refactor the source code of a program in multiple files. Often this is done for organization purpose. You can compile such a program by passing all the source files as strings to the compiler. The compiler creates an executable program if it can find a 'main' function in exactly one of the passed source files. For example consider the following two files. hello-1.c and greeter.c. 

```C
//  hello-1.c 
#include <stdio.h>
extern char * greeter ();
int main (int argc, char** argv)
{

  printf("%s\n",greeter());
  return 0;
}
```

```C
// greeter.c 
char * greeter ()
{

   return "hello";
}
```
Now try to compile the hello-1.c to create an executable program.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ gcc -o hello hello-1.c 
/tmp/ccilhsK7.o: In function `main':
hello-1.c:(.text+0x15): undefined reference to `greeter'
collect2: error: ld returned 1 exit status
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ 
```

The error is thrown by the linker associated with the compiler. The linker is complaining that though the source code mentions the use of the greeter function, it does not have access to the definition of the function. Note that the greeter function is in the second file. To help the linker we provide the second file in the command line.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ gcc -o hello hello-1.c greeter.c 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ 
```

Now you can run the hello program.
```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ ls -l
total 20
-rw-rw-r-- 1 vagrant vagrant   42 Jan 12 04:24 greeter.c
-rwxrwxr-x 1 vagrant vagrant 8672 Jan 12 04:28 hello
-rw-rw-r-- 1 vagrant vagrant  123 Jan 12 04:23 hello-1.c
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ ./hello 
hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ 
```

This particular example showed you an important step associated with "compiling" source code into executable program. This step is called linking. Internally the transformation of the source code to the executable program happens in two steps.

- compilation : it converts the source code file into binary object files: ending in .o extension.
- linking: The .o function contains functions calls that might not have been completely resolved because one  object file might be using a function that is defined in another object file. This we need link multiple object files to resolve all function links. This step is done by the linker called 'ld'. When you executed the compiler 'gcc' earlier it performed both these steps without showing the details to you.

you can perform these two detailed steps as follows. Note that in the first two steps we created the object files and the last step we combined them to create the executable.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ gcc -o greeter.o -c greeter.c 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ gcc -o hello-1.o -c hello-1.c 
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ ls -l
total 16
-rw-rw-r-- 1 vagrant vagrant   42 Jan 12 04:24 greeter.c
-rw-rw-r-- 1 vagrant vagrant 1440 Jan 12 04:36 greeter.o
-rw-rw-r-- 1 vagrant vagrant  123 Jan 12 04:23 hello-1.c
-rw-rw-r-- 1 vagrant vagrant 1448 Jan 12 04:36 hello-1.o
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ gcc -o hello hello-1.o greeter.o
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ ls -lrt
total 28
-rw-rw-r-- 1 vagrant vagrant  123 Jan 12 04:23 hello-1.c
-rw-rw-r-- 1 vagrant vagrant   42 Jan 12 04:24 greeter.c
-rw-rw-r-- 1 vagrant vagrant 1440 Jan 12 04:36 greeter.o
-rw-rw-r-- 1 vagrant vagrant 1448 Jan 12 04:36 hello-1.o
-rwxrwxr-x 1 vagrant vagrant 8672 Jan 12 04:39 hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ 
```

**Note** The advantage of this 2 step process is not immediately apparent. However, if you have to compile really large source code and an object file is shared between mutiple programs then this two phase process ensures that the more time consuming compilation to object file step is only run once because then you resuse the object files to link different executable programs. 

**Note**: Given that the linking step requires resolution of symbols i.e. finding the object file that contains a function name this step can also generate some errors if it cannot find the function definition in one of the object files or if it finds multiple definitions of the functions.

**Note** you can use the nm command to find the function symbols in an object file. See here http://www.thegeekstuff.com/2012/03/linux-nm-command/ for more details on nm.

## Static library

You can combine multiple object files into an archive, which you can link later into a program by using the 'ar' command. See http://www.thegeekstuff.com/2010/08/ar-command-examples for more details. 

# Makefile 

You will soon realize that if you have a large source tree then you have carefully sequence the compilation and linking steps. This is often difficult as you have to remember the dependencies while trying to compile the program. A Makefile is a specification of a sequence of steps that are interpreted by the 'GNUMake' program and peformed in the specified sequence. often these sequence of steps are used to compile and link source code.

Here is the makefile to compile our hello-1.c and greeter.c

```Make
all: hello

hello: hello-1.o greeter.o
        gcc hello-1.o greeter.o -o hello

hello-1.o: hello-1.c
        gcc -c hello-1.c

greeter.o: greeter.c
        gcc -c greeter.c
clean:
        rm *.o hello
```

Each line in the makefile follows the pattern

```Make
target-step: files or other targets this target depends upon
	the actual command that needs to be executed 
```

we specify the target to exectuted when we run the make command with the name of the target as follows. 


```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ make clean
rm *.o hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ 
```


We can ommit the target name. In that case, GNUMake interprets that you are trying to execute the default target, which is 'all'.   This, the command make will actually determine that the all target depends on hello, which is a target (file) that depends upon hello-1.o and greeter.o. because these two targets (files) are not present in the directory, the make program will execute the target greeter.o and hello-1.o These two targets depend upon the two source files respectively. If the target greeter.o is not present then the command `gcc -c greeter.c` is executed to create the target. If the target is present, then the make system runs the command only if the timestamp of the greeter.o file is older than the timestamp of the source code (greeter.c). Thus, it ensures that the target is always compiled from latest source code and that we do not waste time compiling if the target is already latest. This saves a lot of time in large projects.

For more details about makefile, please see https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

Often writing the makefile for large projects also become very cumbersome. To help we use tools like cmake for generating makefiles. A Cmake file for the hello-1.c and greeter.c is shown below

```cmake
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ cat CMakeLists.txt 

cmake_minimum_required (VERSION 2.8)
project (examples)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
add_executable(hello hello-1.c greeter.c)
```

The first line tells the version of cmake to use. The second is the name of the project. The third line tells where the final output should be generated. The last line tells to create an executable using the two source files. 

Given a cmake file you can generate a makefile, which when run will create the executable file. Note that typically with cmake you keep the source directory and build directory seperate. For example, see the steps in the following illustration.

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ ls -l
total 16
-rw-rw-r-- 1 vagrant vagrant 169 Jan 12 05:07 CMakeLists.txt
-rw-rw-r-- 1 vagrant vagrant  42 Jan 12 04:24 greeter.c
-rw-rw-r-- 1 vagrant vagrant 123 Jan 12 04:23 hello-1.c
-rw-rw-r-- 1 vagrant vagrant 176 Jan 12 05:08 Makefile
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ mkdir build
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program$ cd build/
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program/build$ cmake ..
-- The C compiler identification is GNU 5.4.0
-- The CXX compiler identification is GNU 5.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/vagrant/lectures/lecture-02/examples/2-file-program/build
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program/build$  
```

Note that we created a build diretory, changed the current working directory to the build directory and then executed cmake telling it where to find the file containing the cmake script. This file is always named CMakeLists.txt. Once the make file is created in the build folder, you can run the make command

```
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program/build$ make
Scanning dependencies of target hello
[ 33%] Building C object CMakeFiles/hello.dir/hello-1.c.o
[ 66%] Building C object CMakeFiles/hello.dir/greeter.c.o
[100%] Linking C executable ../bin/hello
[100%] Built target hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program/build$ ../bin/hello 
hello
vagrant@Xubuntu-Vagrant:~/lectures/lecture-02/examples/2-file-program/build$  
```

Note that cmake generate nice makefiles that also provides the progress percentage. This is very handy when building projects where the make process can take several hours.

Also note that the final output hello is copied over to the bin folder in the source directory because of the following command in the CMakelists.txt `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")`.  

More information on CMake is provided below. 


# Pointers in C  - a review

et to do??
}

int *getAge() {
  // allocate space on the heap for an int
  int *p = (int*) malloc(sizeof(int));
  
  return p; // return the address of this int
}
```

In the example above, function *foo()* calls *getAge()* to obtain the address of an int. *getAge()* allocates space for that int on the *heap* and returns its address. *foo()* then writes a value to that address (*\*age = 34*).

However, at the end of *foo()*, we forgot a critical step: we forgot to *free* the heap-allocated memory. After *foo()* completes, there are no references to the heap-allocated memory. This program contains what we call a *memory leak*.

The correct thing to do at the end of *foo()* is to call *free(age)* to release the heap-allocated memory. We'll cover memory in more detail in future lectures.

# Pointers and function arguments

Pointers are also very useful as arguments to functions. In C, the arguments to a function are passed by *value*. If we want a function to be able to modify variables that were passed to it, and have those modifications seen by the caller, we need to pass *pointers* as arguments.

For instance, in the canonical swap example:

```c
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void foo() {
  int age = 138;
  int weight = 34;
  if (age > weight)
    swap(&age, &weight); // age and weight are now swapped!
}
```

We pass the *address* of age and weight to the function swap (using the `&` operator) , which allows swap to modify the original variables. If we don't use pointers to pass the address of age and weight, then *swap* can't modify the original variables.

## Pointers and arrays

Pointers and arrays are very similar in C. Recall that an array defines a consecutive block of objects. For instance:

```c
int  intarr[10]; // create space for 10 consecutive ints
char name[25];  // create space to 25 consecutive chars
```

You can use pointers to refer to array elements like this:

```c
int *intptr = &intarr[0];
intptr = intarr; // same as the line above

char *charptr = &name[0];
charptr = name; // same as the line above
```

We can use *pointer arithmetic* to refer to elements in the array:

```c
*(intptr + 0) = 10;   // sets intarr[0] to 10
*(intptr + 1) = 20;   // sets intarr[1] to 20

*(charptr + 0) = 'd'; // sets name[0] to 'd'
*(charptr + 1) = 'a'; // sets name[0] to 'a'
```

Now you might say to yourself, "how does this work? I thought an int usually takes up 4 bytes, and a char usually takes up 1 byte!" And you would be correct.

This works because when you have a statement like:

```c
*(intptr + 1)
```

The compiler knows the *size* of the elements being pointed to by *intptr*: each one is 4 bytes. When you say (intptr + 1), the compiler generates code that grabs the address held by intptr and adds the *size* of the type being pointed to be *intptr*. Thus, it adds *4 bytes* to *intptr*, assuming that the size of an int is 4 bytes.

Similarly, when you say

```c
*(charptr + 1);
```

The compiler takes the address held in *charptr* and adds the size of the type of element that *charptr* points to, which is a *char*. The size of char is usually 1, and so the statement adds *1 byte* to *charptr*.

Another way to do this is to use the postfix *++* operator, like this:

```c
int  firstInt  = *(intptr++);  // assign firstInt the value at intarr[1]
char firstChar = *(charptr++); // assign firstChar the value at name[1]
```

## Character pointers

A *string constant* is an array of characters. An array of characters needs to be terminated with the null character, '\0', so that the end can be found.

Defining a char* and an array of characters has one big difference:

```c
char myName[]   = "Daniel B"; // can change individual elements in the array
char *myNamePtr = "Daniel B"; // undefined if you try to change the contents
```

One function you may find useful in future assignments is *strdup()*. Its signature looks like this:

```c
char *strdup(const char *s);
```

The manpage gives the following documentation:

```
The strdup() function returns a pointer to a new string which is a duplicate of the string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3).
```

Now that we've reviewed pointers, you can see what this documentation is saying: strdup() allocates memory for a new string, copies the contents of the existing string into that newly allocated memory, then returns the address of the newly allocated memory.

## Arrays of pointers and pointers to pointers

Consider the definition of a main function:

```c
int main(int argc, char *argv[]) { ... }
```

*argv* is an array of pointers to characters. That is, each element in argv is a *char\**. Recall that each *char\** should end with a terminating *'\0'*.

Recall that a pointer holds an address. Then we should be able to have a pointer that holds the address of a pointer -- such a pointer would look like this:

```c
int x = 3; // x and y are ints
int y = 4;

int *ptr = &x; // ptr is an int ptr -- it can hold the address of x or y
*ptr = 5; // now x = 5

int **ptrptr = &ptr; // ptrptr is a pointer to a pointer to an int
*ptrptr = &y; // now ptr holds the address of y
**ptrptr = 6; // now y = 6
```

We could keep going: pointers to pointers to pointers. But thankfully you rarely see more than a double pointer.

## Function pointers

Recall that a pointer is a variable that holds an address. Also recall that every part of a running program (aka a *process*) resides somewhere in memory -- this includes functions. So, it should be possible to obtain the address of a function and store it in a pointer to a function.

This is indeed possible, and function pointers are used when interacting with the operating system; we'll see real examples of this a little later with *signal handlers*. 

The syntax for function pointers can be a little tricky. Below are some examples.

```c
void foo() {} // foo is a function that takes no parameters and returns void
void (*fp)(); // fp is a pointer to a function that takes no parameters and returns void

fp = foo; // assign the address of foo to fp
(*fp)();  // invoke foo() using a pointer to it
```

```c
int bar() { return 0; } // bar is a function that takes no parameters and returns an int
int (*bp)(); // bp is a pointer to a function that takes no parameters and returns an int

bp = bar;
int x = (*bp)(); // invoke bp and assign its return value to x 
```

```c
// calc is a function that takes no parameters and returns a pointer to an int
int *calc() {

  int *x = (int*) malloc(sizeof(int)); // call malloc to obtain memory for an int
  
  return x; // x holds the address of an int -- return it
}

// calcptr is a pointer to a function that takes no parameters and returns an int pointer
int *(*calcptr)();
calcptr = calc; // calcptr points to calc

int *np = (*calcptr)(); // invoke calc via calcptr

// question: what does the following line do?
*((*calcptr)()) = 1;
```

## Using pointers to change the value of a variable across a function call.

Consider a main function and a subroutine shown below. In this invocation, the address of x and y are passed by value to the subroutine swap. The subroutine uses the dereferencing  operator to swap the values.  This is important because C does not have a pass-by reference semantics as in C++ (see a c++ example using passby reference to do the  swapping at http://courses.washington.edu/css342/zander/css332/passby.html)

```c
void swap(int*a , in*b)
{
  int templ=*a;
  *a=*b;
  *b=temp1;  
}

int main ()
{
	int x =2;
	int y =3;
	swap (&x,&y);// This invocation should swap the contents of x and y
}
```

## Initializing pointers across a function call.

Consider a case where you want to implement a subroutine which will allocate new student record nodes so that you add them to a linked list. Suppose the student record structure is defined as follows.

```C
struct student_record {
  long num;
  struct node* next;
};
```

You are implementing a funtion that initializes the student record. You want to use that function as follows in your main function.

```C
.... \\main
student_record* new_record;
student_record_init(&student_record);
```

You will notice that because you want to change the value of the new_record and initialize it you have to pass its address as we did in previous section. Thus the student_record_init function will have a signature that uses double point to student_record.

```C
void student_record_init(student_record** new_student)
{
student_record * temp =0;
temp= (student_record*)malloc(sizeof(student_record));
*new_student=temp;
return;
// allocate student 
}
```

## Complex declarations

Reading complex C declarations can be tricky, but the [right-left](http://ieng9.ucsd.edu/~cs30x/rt_lt.rule.html) rule can help you decipher them.


# About CMAKE

CMAKE is an easy to use alternative for makefiles and you should know about it. The advantage of using CMake is that you can manage the build process of your software in a compiler-independent way. For instance, from the same CMake file, you could generate a Linux makefile and a Visual Studio project file.

The most common commands we will use in this course are

 - project(assignment)
 - add_library(LibraryName file1.cpp file2.cpp)
 - add_executable(ExecutableName file3.cpp file4.cpp)
 - target_link_libraries(ExecutableName  LibraryName)

A basic tutorial is available [here](https://cmake.org/cmake-tutorial).

Once you have a CMakeLists.txt file, you can generate either unix makefiles or unix makefiles along with an eclipse project file. The generated eclipse project can then be imported into eclipse.

1. To generate a simple makefile, do the following

 ```bash
  $ cd directory-with-CMakeLists.txt
  $ cmake .
 ```

 This will generate a makefile. Once this is generated, you can build your project by issuing a make command

 ```bash
  $ make
 ```

# Git Review 

Git is the version control system that we use in this class. More details are available at following links:

* Review the instructions at https://help.github.com/articles/set-up-git/#platform-linux.  
* See the slides at https://dbrgn.ch/slides/20130207_getting_git/#/
* For more details you can review the following links
	* https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control
	* https://git-scm.com/book/en/v2/Git-Basics-Getting-a-Git-Repository
	* https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository
	* https://git-scm.com/book/en/v2/Git-Basics-Viewing-the-Commit-History
	* https://git-scm.com/book/en/v2/Git-Basics-Working-with-Remotes (Necessary for pushing your changes back)


