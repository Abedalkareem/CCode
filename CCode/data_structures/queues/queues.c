//
//  queues.c
//  CCode
//
//  Created by abedalkareem omreyh on 13/10/2022.
//

#include "queues.h"
#include <stdlib.h>

struct QNode {
  int key;
  struct QNode* next;
};

struct Queue {
  struct QNode *front, *rear;
};

struct QNode* newNode(int k) {
  struct QNode* temp = malloc(sizeof(struct QNode));
  temp->key = k;
  temp->next = NULL;
  return temp;
}

struct Queue* createQueue(void) {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

void enQueue(struct Queue* q, int k) {
  struct QNode* temp = newNode(k);
  if (q->rear == NULL) {
    q->front = q->rear = temp;
    return;
  }

  q->rear->next = temp;
  q->rear = temp;
}

struct QNode* deQueue(struct Queue *q) {

  if (q->front == NULL) {
    return NULL;
  }

  struct QNode * temp = q->front;
  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  return temp;
}

