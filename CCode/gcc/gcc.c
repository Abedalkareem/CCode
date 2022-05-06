//
//  gcc.c
//  CCode
//
//  Created by abedalkareem omreyh on 05/05/2022.
//

#include "gcc.h"

// Compilation steps:
// Pre processor
// output: .i (pre processed file, expanded code)
// compiler
// output: .s (assembly code)
// assembler
// output: .o  (object code)
// linker
// output: executable

// gcc test.c -o main = writes the build output to an output file.
// gcc -c myfile.c =  gcc -c compiles source files without linking.
// gcc -o main.exe main.o = do the linking step.
// gcc -Wall enables all compiler's warning messages. This option should always be used, in order to generate better code.
// gcc -E test.c = Stop after the preprocessing stage; do not run the compiler proper.
// The output is in the form of preprocessed source code, which is sent to the standard output.

// gcc  -E test.c > myFile = redirect the output to a file.
// gcc -S test.c = -S flags asks gcc to produce human readable assembly code.
// gcc -save-temps test.c = Store the normally temporary intermediate files(*.s, *.i, *.o) permanently.
// gcc test.c -o  main -l m = gcc -l links with a library file.
//Example1
//For static library file libmath.a use -lmath:
//
//$ gcc -static myfile.c -lmath -o myfile
//
//
//Example2
//For shared library file libmath.so use -lmath:
//
//$ gcc myfile.c -lmath -o myfile

// gcc -g generates debug information to be used by GDB debugger.
//-g0  no debug information
//-g1  minimal debug information
//-g  default debug information
//-g3  maximal debug information

// gcc -D DEBUG myfile.c -o myfile
// gcc -D defines a macro to be used by the preprocessor.

// -Werror Make all warnings into errors.

// you can use @ to pass option file.
// gcc test.c @option_file
//
// option_file content:
// -Wall
//

// to see all the optimizers:
// gcc -q--help=optimizers

// GCC uses the following environemnt variables
// PATH: for searching the executables and run time shared libraries. (.dll, .so).
// CPATH: for searching the include paths for headers.
// searched after paths specified in -l<dir> options.
// C_INCLUDE_PATH can be used to specify C headerrs if the particular language was indicated in pre-processing.
//
// LIBRARY_PATH: for searching library paths  for link libraries.
// it is searched after paths specified in -L<dir> options.

// nm is commonly used to check if a particular function is defined in an object file.
// a 'T' in the second column indicates a function that is defined.
// a 'U' indicates a function which is undefined and should be resolved by the linker.

// ldd Utility.  (List dynamic link librraries)
// examines an executable and displays a list of the shared libraries that it needs.

