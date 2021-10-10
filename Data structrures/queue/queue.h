#ifndef QUEUES_H
#define QUEUES_H 1

#include <stddef.h>

typedef struct queue* Queue;

Queue new_queue(long);
size_t queue_sizeof(Queue);
void enqueue(Queue, long);
long dequeue(Queue);
void free_queue(Queue);

#endif // QUEUES_H