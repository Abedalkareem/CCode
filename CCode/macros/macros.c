//
//  macros.c
//  CCode
//
//  Created by abedalkareem omreyh on 24/04/2022.
//

#include "macros.h"

// A macro is a piece of code in a program that is replaced by the value of the macro. Macro is defined by #define directive.
// #define macro_name( list_of_identifiers ) substitution_string
//
// preprocessor operators:
// - \
// - defined
// - # (token pasting)
// - ## (token)
//

#define PI 3.14 // Symbolic constant.

// function macro:
#define PRNT(a, b) \
printf("value 1 = %i\n", a); \
printf("value 2 = %i\n", b);

#define WARNING(...) fprintf(stderr, __VA_ARGS__)
// WARNING("%s: this program is here\n", "AAAA");

#define UpTo(i, n) for ((i) = 0; (i) < (n); (i)++)
// UpTo(i, 10);


#define str(x) #x
#define HELLO(x) printf("Hello, " #x "\n");
#define printint(var) printf(#var "= %i\n", var);

#define CONCATENATE(x, y) x##y // CONCATENATE(O, K) will be OK.

#define make_function(name) void my_ ## name(int foo) {}

make_function(bar);

void tryMacros(void) {
#if defined(DEBUG)
  printf("hello");
#endif

  printf("%s", str(text)); // will give "text"

  HELLO(abed); // printf("Hello, " "abed" "\n");

  int x = 5;
  printint(x) // printf("x" "= %i\n", x); // x = 5

  int xy = 55;

  printf("%i", CONCATENATE(x, y)); // will be printf("%i", xy);

  my_bar(44);

  printf(__FILE__); // current file name.
  printf("%i", __LINE__); // current line.
  printf(__func__); // current function name.
  printf(__DATE__); // the date the source file was compiled. "Mmm dd yyyy", "Jan 19 2002"
  printf(__TIME__); // the time the source file was compiled. "hh:mm:ss", "11:55:22"
  printf("%i", __STDC__); // if compiler support standard C.

}


