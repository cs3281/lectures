# Understand the OS, Process Flow and System Calls

One of the jobs of an OS is to share a computer among multiple programs and provide a more useful set of services than the hardware alone supports. You can think of it in layered terms:

 * Hardware: CPU, memory, disks
 * OS kernel: provides many services
 * Libraries: provide access to the above services
 * Applications: vi, emacs, gcc, shell, etc.

Today we'll discuss how the services of the OS kernel are provided to applications. 

## Processes

A *process* is a running instance of a program. It is the unit of isolation provided by the OS. 

  * It prevents a process X from wrecking or spying on a process Y's memory, cpu, FDs, resource exhaustion. 
  * It also prevents a process from wrecking the operating system itself, i.e. from preventing kernel from enforcing isolation in the face of bugs or malice e.g. a bad process may try to trick the h/w or kernel

A process can be thought of as an abstraction that provides the illusion to a program that it has its own abstract machine. The OS provides each process with its own *address space* and what appears to be its own *CPU* to execute its instructions. 

In fact this virtualization of resources is one of key tasks of an operating system.

## How do we create processes.

A process is created when we **execute** a program. A program is a list of instructions compiled together to implement an algorithm or do some computation that we want to perform. Typicall, this program is launched via a shell.

*Definition*: a *shell* is a special-purpose program designed to read commands typed by a user and execute appropriate programs in response to those commands. It's also known as a *command interpreter*.

The shell is *not* part of the operating system. It is an ordinary *user* process that uses the services provided by the OS.

Shells don't only provide interactive use. They can also interpret *shell scripts*, which are text files containing shell commands -- this is why shells contain things like variables, loops and condition statements (like other programming languages).

 A number of shells have been created over the years, for example, ``bash`` (Bourne Again SHell), ``korn shell``, ``c shell``, ``ash``. By default we are using bash in the linux system that we have created for the class.  To find which shell you are using, execute the command
 
 ```
 $ echo $SHELL
 ```

Let's look at see an example of a shell script. 

 ```
	$ vi test.sh
	$ cd /opt
	# save test.sh by pressing esc - shift- zz
 ```

## Environment Variables in Shell
An environment variable is a globally available, in a program and it child programs. A shell variable is only available in the current shell. To make a shell variable available as an environment variable, use ``export VARNAME (without dollar $)``

```
      $ export a=1
      $ echo $a
```

## The `source` prefix
Now let us put this declaration in a file.

```   
      $vi test.sh
       export a=1
      $ ./test.sh
      $ echo $a
```
The reason `a does not have a value is because a shell script is executed in a sub-shell, which dies when the shell script terminates. So the variable a was set in the subshell and not in the shell where you are.

To avoid that you can use the source prefix

     ```
     $ source ./test.sj
     $ echo $a
     ```
     
# System calls
In the layered view of an OS, we said that the OS provides *services*. So what are examples these services?

The OS provides services like reading a file from a disk, writing to a file on disk, creating new processes, and sending data over the network. The OS provides these services, rather than allowing user-level processes to do these sorts of tasks. The reason: user-level processes cannot be trusted to be non-malicious. For example, a single malicious program could destory the contents of a disk.

Instead, user-level processes request these services from the OS using *system calls*. A *system call* is a controlled entry point into the OS kernel, allowing a process to request that the kernel perform some action on the process's behalf. The system call *API* is the interface that makes the OS services available to user-level programs.

The foundation of the isolation between *kernel mode* and *user-mode*? A flag that controls whether instructions can access privileged hardware.

 * Call CPL on x86.
 * It's the bottom two bits of the cs register.
 * CPL=0 -- kernel mode -- privileged
 * CPL=3 -- user mode -- no privilege

On x86, CPL protects everything relevant to isolation:

 * writes to %cs (to defend CPL) (cs == code segment register)
 * every memory read/write
 * I/O port accesses
 * control register accesses (eflags, %cs4, ...)
 * every serious microprocessor has something similar..

So to recap, we have the following situation:

 * The CPL, represented by the bottom two bits of the cs register, determine whether instructions can access privileged hardware.
 * Only the kernel should be allowed to operate in the privileged mode.

The question arises: how and when should the CPL change? The answer on x86 is that it happens when a system call is invoked:

 * The instruction used to invoke the system call sets CPL=0.
 * Execution jumps to a specific entry point in the kernel of the OS, which can then do further validation.
 * The system call return sets CPL=3 before returning to user code.
 

# Tracing system calls

You can use the *strace* command to trace the system calls that are made by a program. As an example, open a shell and type:

 ```bash
 $ strace ls
 ```
 
 This will tell you what system calls are invoked when you do a *ls*. Among the output, you might see things like:
 
  * execve -- this loads a new program and starts running it
  * open -- open a file
  * read -- read from a file
  * close -- close a file
  * fstat -- get information about a file
 
# Privilege levels in system calls
=======================================
	* The kernel tracks the user making the system call.
	* The root (userid =0) is allowed access to all system calls.
	* Other users are not allowed access to calls like *shutdown
	* Try 
		* echo $UID
		* now try sudo su
			* echo $UID

# System call implementation

Let's look at the details of how a program requests a service from the operating system (that is, how a program invokes a system call).

 1. The program invokes a wrapper function in the C library. The reason for this is that the wrapper function sets up the system call arguments as expected by the OS. If you've ever noticed files like "libc.so", that's the C library.
 2. The wrapper function puts any arguments to the system call in the registers expected by the kernel.
 3. All system calls enter the kernel the same way, so the kernel must be able to identify them. The wrapper function in the C library copies the system call number into the %eax register of the CPU.
 4. The wrapper function executes a trap machine instruction. This is *int 0x80*. This causes the processor to switch from user mode to kernel mode (that is, it sets CPL=0) and executes the code pointed to by location *0x80* of the system's trap vector.
 5. The kernel invokes its *system_call* routine to handle the trap to location *0x80*. This is where the meat of the system call logic happens: the kernel does some bookkeeping, checks the validity of the arguments, invokes the service routine, and finally the service routine returns a result status to the *system_call* routine.
 6. The wrapper function checks if the service returned an error, and if so, sets a global variable named *errno* with this error value. The wrapper function then returns to the caller and provides an integer return value to indicate success or failure.

# Understanding Exceptional Flow

The typical control flow of a program (instantiated as a process) is sequential and follows the control logic written into the program. Most cases, it starts at the int main and then finishes at the last return or last statement of the program. Everytime a function call is made, the control jumps to a function using a stack and then returns back. Below are some good links that explain this. Please review it.

1. Easiest way to understand stack usage in function calls is through recursive function calls. Take a look at https://eecs280staff.github.io/notes/02_ProceduralAbstraction_Testing.html and https://eecs280staff.github.io/notes/18_Recursion.html

2. Also, here is an excerpt from CSAPP book that explains exceptions and exceptional control flow. Please read http://csapp.cs.cmu.edu/2e/ch8-preview.pdf
