//
//  linked_list.h
//  CCode
//
//  Created by abedalkareem omreyh on 09/10/2022.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

typedef struct node_t {
  char data;
  struct node_t *next;
 } node_t;

typedef struct node_t *node;

void linkedListTest(void);

void insertAtEnd(node *head, char value);
void insertAtBeginning(node *head, char value);
void delete(node *head, char value);
void deleteAtBeginning(node *head);
int isEmpty(node *head);
void print(node head);

#endif /* linked_list_h */
