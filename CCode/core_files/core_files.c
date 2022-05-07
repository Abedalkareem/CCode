//
//  core_files.c
//  CCode
//
//  Created by abedalkareem omreyh on 07/05/2022.
//

#include "core_files.h"

//a core dump is generated when a program crashes or is terminated abnormally because of segmentation fault.
//  possibly division by zero oor attempts to access past the end of an array (lillegal memory access).

// a segmentation fault s speccific kind of error  caused by accessing memory that does not belong to you
// a pice of code tries to do read and wirte operation in a read only location in memory or freed block of memory.

// a core dump is also called a memory dump, storage dump or dump.
// a core dump results in the creation of a file.
// this core file contains a snapshot of the coontents of the process's memory at the time it terminated.
// this file used for debugging purposes (used to assist in diagnosing and fixing errors)
// core dumps allow a user to save a crash for later or off site analysis, or comparison with other crashes.
// core dumps can be used to capture data freed during dynamic memory allocation and may thus be used to retrieve information from
// a programm that is no longer running.

// a core dump is contained in a file named something similer to core.<process_id>
// created in current working directory.

// on windows which uses Cygwin the dump may not be named core, it will likely be named something like mybadprog.exe.stackdump.
// your system might be configured to disable the automatic creation of this core file, often due to the large size of these files.
// to enable writing core files you use the ulimit command
// $ ulimit -c unlimited

// to view a core dump you will need a debugger.
// it will allow you to examine the state  of the process.
// includes listing the stack traces for all the threads of the process.
// you can also print the values of variables and registers.

// to analyze the core we need gdb.
// $ gdb file.exe core_file
