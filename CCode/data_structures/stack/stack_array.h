//
//  stack_array.h
//  CCode
//
//  Created by abedalkareem omreyh on 13/10/2022.
//

#ifndef stack_array_h
#define stack_array_h

#include <stdio.h>

#define MAXSIZE 5

struct stack {
  int stk [MAXSIZE];
  int top;
};

typedef struct stack STACK;

void pushToStack(int value);
int popFromStack(void);
void displayAllStackArray(void);

#endif /* stack_array_h */
