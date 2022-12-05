//
//  processes.c
//  CCode
//
//  Created by abedalkareem omreyh on 15/10/2022.
//

#include "processes.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// a process is a program in execution.
//
// a program is a file containing the informaton of a process.
// when you start execution of the programm, it is looaded into RAM and starts execution.
//
// each process has it's own address space and usuallly one tthread of ccontrol.
//
// you can have multiple processes executiong the same program
// but each process has iot's own copy of the program within its own address space and executes it
// independently oof the other coopies.
//
// proocesses are organized hierarchically
// each process has a parent process which explicitly arranged to create it.
//
// the processes created by a given parent are called its child processses
// a child inherts many of its  attributes from the parent process.
//
//
// each proocess is identified with a unique positive integer called a process  id (PID).
//
//
// Interprocess coomunication
// a proccess can be oof two types
// - Independent process
//   - not affected by the execution of other processes.
//   - does not interact with other programs.
// - co-operation process
//   - affected by other execution processes
//   - can be used for increasing computational speed, convenience and modulrity.
//
// interproess comuniation lets processes work together
// programs can be much more powerful by letting them talk to  other programs on your system.
// often referred to as IPC.
//
//Interprocess communication
//* ﻿﻿a process can communicate with another process in many different ways
//* ﻿﻿pipes (same process) first process communicates with the second process, allows flow of data in one direction only (half duplex)
//* ﻿﻿named pipes (different processes, FIFO)
//* ﻿﻿the first process can communicate with the second process and vice versa at the same time (full duplex)
//* ﻿﻿message queues
//* ﻿﻿processes will communicate with each other by posting a message and retrieving it out of a queue (full duplex)
//* ﻿﻿shared memory communication between two or more processes is achieved through a shared piece of memory among all processes
//• sockets mostly used to communicate over a network between a client and a server
//
//* signals communication between multiple processes by way of signaling
//a source process will send a signal (recognized by number) and the destination process will handle it accordingly


void testProcesses(void) {
  int mypid, myppid;
  mypid = getpid();
  myppid = getppid();
  printf("My process ID is: %i\n", mypid);
  printf("My parent process ID is: %i\n", myppid);

  system("ps -ef");
}
