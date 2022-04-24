//
//  preprocessor.c
//  CCode
//
//  Created by abedalkareem omreyh on 24/04/2022.
//

#include "preprocessor.h"

// C preprocessor
// - remove all the comments.
// - includes all of the files fro, various libraries that the program needs to compile.
// - expansion of macro definitions.
//
// conditional compilation.
// conditional compilation is compilation implementing methods which allow the
// compiler to produce differences in the executable program produced and controlled
// by parameters that are provided during compilation.
//
// every #if construct ends with an #endif.
// directives #ifdef and #ifndef are  provided as shorthand for #if defined(name) and #if !defined(name).
//
//
// include guards,
// Include guards are used to prevent a file, actually the contents of a file, from being included more than once.
// #ifndef THINGS_H_
// #define THINGS_H_
// ......... contet of header.
// #endif
//
//
// #unndef you can undefine an identifier you have previously defined.
//
// #pragma. (pragmatic information).
// directive llets you place compiler instructions in your source code.
// lets you request special behavior from the compiler.
// #pragmas can be used:
// - to control the amount of memory set aside of automatic variables.
// - to set the strictness of error checking.
// - to enable nonstandard language features.
// #pragma token_name
// #pragma  ios usually followed by single token.
//
// #pragma GCC dependency "somefile.y"
// it will show a warning if the date of the other file is more recent than the current file.
//
// #pragma GCC poison printf sprintf fprintf
// it will remove completely any identifier.
// so it will show error if you use prrintf in this case.
//
// #pragma GCC system_header
// tells the compuler to consider the rest of the current include file as a system header.
//
// #pragma once
// the header file containing this directive is inncluded only once even if the programmer includes it multiple times.
//
// #pragma GCC warning "message" // show warning
// #pragma GCC error "message" // show error
// #pragma GCC message "message" // show message
//
//
// #error some error message. // it will show an error.
// #warnig some warning message.
// #line linenum filename.

#define DEBUGAPP
// you can define macros also using "gcc -D DEBUGAPP profram.c"

void tryTheThing(void) {
#ifdef DEBUGAPP
  printf("hello");
#endif

#ifndef SIZE
#define SIZE 5
#endif

#if SIZE == 5
  printf("wow");
#elif SIZE == 55
  printf("NO WAY")
#else
  printf("NO");
#endif

}
