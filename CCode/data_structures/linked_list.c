//
//  linked_list.c
//  CCode
//
//  Created by abedalkareem omreyh on 09/10/2022.
//

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void linkedListTest(void) {
  node head = malloc(sizeof(node_t));
  head->data = 'c';
  insertAtBeginning(&head, 'v');
  print(head);
  insertAtBeginning(&head, 'x');
  print(head);
  insertAtBeginning(&head, 'c');
  print(head);
  insertAtEnd(&head, 'w');
  print(head);
  deleteAtBeginning(&head);
  print(head);
  delete(&head, 'x');
  print(head);
}

void insertAtBeginning(node *head, char value) {
  node new_node = malloc(sizeof(node_t));
  new_node->data = value;
  new_node->next = *head;
  *head = new_node;
}

void insertAtEnd(node *head, char value) {
  node current = *head;

  if (current != NULL) {
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = malloc(sizeof(node));
    current->next->data = value;
    current->next->next = NULL;
  } else {
    current = malloc(sizeof(node));
    current->data = value;
    current->next = NULL;
    *head = current;
  }

}

void deleteAtBeginning(node *head) {
  node temp = NULL;

  if (head == NULL) {
    return;
  } else {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

void delete(node *head, char value) {
  node previous = NULL;
  node current = NULL;
  node temp = NULL;

  if (value == (*head)->data) {
    temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    previous = *head;
    current = (*head)->next;
    while (current != NULL && current->data != value) {
      previous = current;
      current = current->next;
    }
    if (head != NULL){
      temp = current;
      previous->next = current->next;\
      free(temp);
    }
  }
}

void print(node head) {
  if (head == NULL) {
    printf("List is empty");
  } else {
    printf("The list is:");
    while (head != NULL) {
      printf("%c --> ", head->data);
      head = head->next;
    }
  }
}

int isEmpty(node *head) {
  return head == NULL;
}

