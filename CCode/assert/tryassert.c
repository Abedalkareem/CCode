//
//  tryassert.c
//  CCode
//
//  Created by abedalkareem omreyh on 16/05/2022.
//

#include "tryassert.h"
#include <assert.h>
#include <limits.h>

// assertion can be switched off by defining the symbol NDEBUG before the #include  directive for assert.h
// #define NDEBUG
// #include <assert.h>
//
// this code snippet will cause all assert() macros in your code to be ignored.
//
// with some nonstandard systems, assertion are disabled by default, in wich case you can enable them by undefining NDEBUG.
// #undef NDEBUG
// #include <assert.h>
//
// by including the directive to undefine NDEBUG, youo ensure that assertions are enabled ffor your source file.
// #undef must appear before the #incllude directive fore assert.h to be effective.

void doassert(void) {
    int x = 5;
    int y = 10;
    assert(x < y);
}

// compile time assertions
// the assert.h header makes static_assert an alias for the c keyword _Static_assert
// more  compatible with c++, which uses static_assert as it's keyword for this feature.
//
// static_assert is treaded as a declartion statement
// unlike most kinds of C statements, it can appear either in a function or external to a function.
//
// the static_assert() macro enables you to output an error message during compilation
// message includes a string literal that you specify.
// whether or not the output is produced depends on the value of an expression that is a compile time constant.
//
// takes two arguments
// first is a constant integer expression
// second is a string
//
// static_assert(constant_expression, string_literal);
//
// when the constant expression evaluates to zero, compiltation stops and the error message is output.
//
//
// Example:
//static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");


