#include "queues.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isReachedEnd = false;

struct queue {
    long  len;
    long  tail;
    long  head;
    long* array;
};

Queue new_queue(long length) {
    Queue self = (Queue) malloc(sizeof(struct queue));
    if(!self) {
        fprintf(stderr, "Cannot malloc enough memory for struct queue\n");
        exit(1);
    }
    self->len = length;
    self->array = (long*) malloc(sizeof(long) * self->len);
    if(!self->array) {
        free(self);
        fprintf(stderr, "Cannot malloc enough memory for queue's array\n");
        exit(1);
    }
    self->head = self->tail = 0;

    return self;
}

size_t queue_sizeof(Queue self) {
    if(self)
        return (3 * sizeof(long) + self->len * sizeof(long));
    return 0;
}

void enqueue(Queue self, long element) {
    if(isReachedEnd && self->tail == self->head) {
        fprintf(stderr, "Queue overflowed\n");
        exit(1);
    }
    *(self->array + self->tail) = element;
    if(self->tail == (self->len - 1)) {
        self->tail = 0;
        isReachedEnd = true;
    }
    else
        ++self->tail;
}

long dequeue(Queue self) {
    if(!isReachedEnd && self->head == self->tail) {
        fprintf(stderr, "Queue underflowed\n");
        exit(1);
    }
    long out = *(self->array + self->head);
    if(self->head == (self->len - 1)) {
        self->head = 0;
        isReachedEnd = false;
    }
    else
        ++self->head;
    return out;
}

void free_queue(Queue self) {
    free(self->array);
    free(self);
}