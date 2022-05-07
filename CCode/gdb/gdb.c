//
//  gdb.c
//  CCode
//
//  Created by abedalkareem omreyh on 06/05/2022.
//

#include "gdb.h"

//A debugger is a program that runs other programs, allowing the user to exercise control over these programs, and to examine variables when problems arise.
//
//GNU Debugger, which is also called gdb, is the most popular debugger for UNIX systems to debug C and C++ programs.
//
//GNU Debugger helps you in getting information about the following:
//
//If a core dump happened, then what statement or expression did the program crash on?
//
//If an error occurs while executing a function, what line of the program contains the call to that function, and what are the parameters?
//
//What are the values of program variables at a particular point during execution of the program?
//
//What is the result of a particular expression in a program?
//
//How GDB Debugs?
//GDB allows you to run the program up to a certain point, then stop and print out the values of certain variables at that point, or step through the program one line at a time and print out the values of each variable after executing each line.
//
//GDB uses a simple command line interface.
//
//Points to Note
//Even though GDB can help you in finding out memory leakage related bugs, but it is not a tool to detect memory leakages.
//
//GDB cannot be used for programs that compile with errors and it does not help in fixing those errors.

// gcc -g main.c
// gdb a.exe
// to run the program
// $ run
//
// to show more lines around the lines the app crashed on.
// $ list 10 // will show code around that line.
// $ l 10 // will show code around that line.
// $ list +
// $ list -
// $ list +10
// $ list -10
// $ list 23, 28 => from 23 to 28
//
// to print a varible:
// $ print variable
// $ p variable
// $ p /x i // print hex
//
// to quit
// $ quit
//
// to assign a value to a variable
// set var i=5
//
// to access a varibale inside a function:
// print main::i // main is the function and i is the variable.
//
// To setup a break point:
// $ list
//  => to show the code and the number of lines
// $ break 10 // you can say also $ break function_name, or on file $ break file_name
//  => to set the break point on line number 10
// $ c
// => to continue execution.
// $ s
// $ step
// => to do a single step.
// $ step 5
// step 5 times.
// $ info locals
// show all the local variables values.
// $ info break
// it show all the break points.
// $ clear line_number (clear 10)
// delete the break point
// $ clear foo
// clear the break point on function.
// $ bt
// to show break trace (call stack)
// $ frame
// When used without any argument, this command does not change which frame is selected, but prints a brief description of the currently selected stack frame. It can be abbreviated f. With an argument, this command is used to select a stack frame.
// $ info args
// to print the function arguments values.
// $ print foo(date)
// print value of foo with passed date.
// $ help breakpoints
// will show information about other commands for breakpoints.
