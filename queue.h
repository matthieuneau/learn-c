#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
  int *data;
  int size;
  int front;
  int rear;
} Queue;

Queue *init_queue(int size);
void enqueue(Queue *q, int data);
void dequeue(Queue *q);
bool is_empty(Queue *q);
void free_queue(Queue *q);

#endif
