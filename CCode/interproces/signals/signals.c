//
//  signals.c
//  CCode
//
//  Created by abedalkareem omreyh on 16/10/2022.
//

#include "signals.h"
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

//Overview
//* ﻿﻿signals are a limited form of inter-process communication (IC), typically used in Unix like operating systems
//* ﻿﻿a notification to a process indicating the occurrence of an event
//* ﻿﻿signals are a way to communicate information to a process about the state of other processes, the operating system and hardware, so that the process can take appropriate action signals are generated by the system or the user can also generate the signal programmatically
//* ﻿﻿when a signal is sent, the operating system interrupts the target process' normal flow of execution to deliver the signal
//* ﻿﻿a process can receive a particular signal asynchronously (at any time)
//* ﻿﻿after receiving the signal, the process will interrupt its current operations
//* ﻿﻿the process has to stop whatever it is doing and go deal with the signal
//* ﻿﻿it will either handle or ignore the signal, or in some cases terminate
//there are fix set of signals that can be sent to a process defined by the operating system
//* a signal is just a short message which contains a single integer value
//
//Examples
//* ﻿﻿when we are working in the shell and wish to "kill all cat programs" we type the command
//* ﻿﻿killall cat - sends a signal to all processes named cat that says "terminate." (SIGTERM)
//* ﻿﻿signals are also used in the context of terminal signaling which is how programs stop, start and terminate
//* ﻿﻿typing Ctrl-c that is the same as sending a SIGINT signal
//* ﻿﻿typing Ctrl-z that is the same as sending a SIGTSTP signal
//* ﻿﻿typing fg or bg that is the same as sending a SIGCONT signal
//* ﻿﻿when a program calls the fgets() function
//* ﻿﻿the operating system reads the data from the keyboard, and when it sees the user hit CtrI-C, sends an interrupt signal to the program
//* ﻿﻿some other signal events include
//* ﻿﻿illegal instructions, segmentation violations, termination orders from the operating system
//* ﻿﻿floating-point exceptions(division by zero or multiplying large floating-point values)
//
//Default actions
//* ﻿﻿whenever a signal is raised (either programmatically or system generated signal), a default action is performed for some signals
//* ﻿﻿Term - the process will terminate
//* ﻿﻿Core - the process will terminate and produce a core dump file that traces the process state at the time of termination
//* ﻿﻿Ign - the process will ignore the signal
//* ﻿﻿Stop - the process will stop, like with a Ctrl-Z
//* urse content
//* • Cont - the process will continue from being stopped
//
//Signal names
//* ﻿﻿each signal has a name, value, and default action that a process will take in response
//* ﻿﻿each signal starts with SIG
//* ﻿﻿available signals can be checked with the command kill -I (I for Listing signal names)
//  Signal | Value | Action | Comment
//* SIGHUP | 1     | Term   | Hangup detected on controlling terminal or death of controlling process
//* SIGINT | 2     | Term   | Interrupt from keyboard
//* SIGQUIT| 3     | Core   | Quit from keyboard
//* SIGILL | 4     | Core   | Illegal Instruction
//* SIGABRT| 6     | Core   | Abort signal from abort(3)
//* SIGFPE | 8     | Core   | Floating point exception
//* SIGKILL| 9     | Term   | Kill signal
//* SIGSEGV| 11    | Core   | Invalid memory reference
//* SIGPIPE| 13    | Term   | Broken pipe: write to pipe with no readers
//
// the command "kill -l" shows all the signals that the os can generate.
//


void testSignal(void) {
  raise(SIGSTOP);

}

//it is possible to handle or catch almost all signals in your program
//* ﻿﻿sometimes you need to run your own code when receiving a signal (handle/catch)
//- ﻿﻿maybe your process has files or network connections open
//* ﻿﻿it might want to close things down and tidy up before exiting
//
//- ﻿﻿it is also possible to ignore almost all signals
//* ﻿﻿neither performing the default action nor handling the signal
//
//- ﻿﻿a few signals cannot be ignored or handled/caught
//- ﻿﻿SIGKILL, SIGABRT and SIGSTOP (which is why "kill 9" is the ultimate kill statement)
//
//* ﻿﻿the actions performed for signals are
//- ﻿﻿default action
//- handle the sianal
//- ﻿﻿ignore the sienal
//
// to ignore a signal you can pass, SIG_IGN function.

void handler_divedbyzero(int signum);
void testSignalHandling(void) {

  void (*sigHandlerReturn) (int);
  sigHandlerReturn = signal(SIGFPE, handler_divedbyzero);
  if (sigHandlerReturn == SIG_ERR) {
    perror("Signal eerror: ");
    return;
  }
//  int result = 1/0;
//  printf(result);
}

void handler_divedbyzero(int signum) {
  if (signum == SIGFPE) {
    printf("Received SIGFPE, DDivide by zro exception");
  } else {
    printf("Recevied %d Signal", signum);
    return;
  }
}

//fork() is often used with the exec() system call in order to start the execution of a different program
//- ﻿﻿a typical use case is that a process will first invoke the fork function to create a copy of itself
//* ﻿﻿then, the copy (child process), calls the exec system call to overlay itself with the other program
//* ﻿﻿it ceases execution of its former program in favor of the other
//* ﻿﻿after a new child process is created, both processes will execute the next instruction following the fork() system call
//- ﻿﻿child and parent processes run in parallel
//* ﻿﻿we have to distinguish the parent from the child
//* ﻿﻿this can be done by testing the returned value of fork()
//
//the fork() function does not take any parameters and returns a process ID
//pid=fork();
//the returned process ID is of type pidt defined in sys/types.h
//the process ID is an integer
//as mentioned in a previous lecture, a process can use function getpid() to retrieve the process ID assigned to this process
//in the subsequent blocks of code you need to check the value of pid
//* ﻿﻿returns a negative value when the creation of a child process was unsuccessful returns a zero value to the newly created child process returns a positive value, the process ID of the child process, to the parent
//* ﻿﻿when we test the value of pid to find whether it is equal to zero or greater than it we are effectively finding out whether we are in the child process or the parent process

void testFork(void) {
  fork();

  printf("Hello World"); // will be printed twice.
}


void childProcess(void);
void parentProcess(void);

void testForkAgain(void) {
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    childProcess();
  } else if (pid > 0) {
    parentProcess();
  }
}

void childProcess(void) {
  printf("child");
}

void parentProcess(void) {
  printf("parent");
}