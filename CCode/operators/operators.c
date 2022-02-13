//
//  operators.c
//  CCode
//
//  Created by abedalkareem omreyh on 27/11/2021.
//

#include "operators.h"

// Operators are functions that use a symbolic name.
// 5 + 3, infix style.
// ++5 prefix style.
// 5++ postfix sryle.
// 5 + 1
// (+) operator, (5 & 1) operand.
// Type of operators:
// logical operators. &&, ||
// arithmetics operators. +, -, *, /, %, ++, --
// assignment operators (=), relattional operators (<, >, !=), bitwise operators (<<, >>, ~, ^, |, &)

// An expression consists of a combination of operators and operand.
// Compound statements: two or more statements grouped together by enclosing them
// in braces (block).

void bitwise(void) {
  unsigned int a = 60; // 0011 1100
  unsigned int b = 13; // 0000 1101
  printf("a & b %u \n", a & b); // 0000 1100
  printf("a | b %u \n", a | b); // 0011 1101
  printf("a ^ b %u \n", a ^ b); // 0011 0001
  printf("~a %u \n", ~a); // 1100 0011
  printf("a<<2 %u \n", a<<2); // 1111 0000
  printf("a>>2 %u \n", a>>2); // 0000 1111
}

