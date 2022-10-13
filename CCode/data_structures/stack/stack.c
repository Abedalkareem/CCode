//
//  stack.c
//  CCode
//
//  Created by abedalkareem omreyh on 12/10/2022.
//

#include "stack.h"
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

struct node* top;

void push(int data) {
  struct node* temp = malloc(sizeof(node));
  if (temp != NULL) {
    temp->data = data;
    temp->next = top;
    top = temp;
  }
}

int isStackEmpty(void) {
  return top == NULL;
}

void pop(void) {
  struct node* temp;
  if (top != NULL) {
    temp = top;
    top = temp->next;
    temp->next = NULL;
    free(temp);
  }
}

void displayAll(void) {
  struct node *temp;

  if (top !=  NULL) {
    temp = top;
    while (temp  != NULL) {
      printf("%d:\n", temp->data);
      temp = temp->next;
    }
  }
}
