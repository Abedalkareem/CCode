//
//  stack_array.c
//  CCode
//
//  Created by abedalkareem omreyh on 13/10/2022.
//

#include "stack_array.h"

STACK s;


void pushToStack(int value) {
  if (s.top == (MAXSIZE - 1)) {
    printf("Stack is Full\n");
    return;
  } else {
    s.top = s.top + 1;
    s.stk[s.top] = value;
  }
}

int popFromStack(void) {
  if (s.top == -1) {
    printf("Stack is empty\n");
    return s.top;
  } else {
    int num = s.stk[s.top];
    s.top = s.top - 1;
    return num;
  }
}

void displayAllStackArray() {
  if (s.top == -1) {
    printf("Stack is empty\n");
    return;
  }

  for (int i = s.top; i>=0; i--) {
    printf("%d:\n", s.stk[i]);
  }
}
