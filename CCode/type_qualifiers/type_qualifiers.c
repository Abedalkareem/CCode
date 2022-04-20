//
//  type_qualifiers.c
//  CCode
//
//  Created by abedalkareem omreyh on 25/03/2022.
//

#include "type_qualifiers.h"

// const: the value will not be changed.
// compiler will place it into read-only memory.

const double hi = 4.4;
//extern const double hi; // when you use extern in another file it should be also const.

typedef const int hello;

hello x = 55; // const;

const float *ptr_float; // points to a constant float value. (the value is const not the pointer).
//float const *ptr_float; // samething

float * const ptr; // ptr is a const pointer. (you can change the value but not the pointer).

const float * const ptrandvalue; // value and pointer are const.

void display(const int array[]) { // same as const int * array.

}

// volatile: it tells the compiler explicitly that the variable will change its value.
// it's provided so that the program can tell compiler to suppress various kinds of optimizations.
// it also prevents the compiler from caching it.
// it should be used by: memory mapped peripheral registers, global variables modified by an interrupt
// service routine, global variables accessed by multiple tasks within a multi-threaded application.

volatile int location;
volatile int *locationptr;

// restrict: tells the compiler that a particular pointer is the only refrence to the value
// it points to throughout it's scope.

int * restrict intptrA;

