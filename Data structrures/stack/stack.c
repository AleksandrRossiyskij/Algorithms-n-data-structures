#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STARTEDSTACKCAP 16

struct stack {
    long  top;
    long  cap;
    long* array;
};

Stack new_emptyStack() {
    Stack self = (Stack) malloc(sizeof(struct stack));
    if(!self) {
        fprintf(stderr, "Cannot malloc enough memory for struct stack\n");
        exit(1);
    }
    self->top = -1; // -1 indicates that stack is empty
    self->cap = STARTEDSTACKCAP;
    self->array = (long*) malloc(sizeof(long) * self->cap);
    if(!self->array) {
        free(self);
        fprintf(stderr, "Cannot malloc enough memory for stack's array\n");
        exit(1);
    }

    return self;
}

size_t stack_sizeof(Stack self) {
    if(self)
        return (2 * sizeof(long) + self->cap * sizeof(long));
    return 0;
}

bool stack_isEmpty(Stack self) {
    if(self->top == -1)
        return true;
    return false;
}

void stack_push(Stack self, long element) {
    ++self->top;
    if(self->top == self->cap) {
        self->cap <<= 1; // Just multiply self->cup by 2
        self->array = realloc(self->array, sizeof(long) * self->cap);
    }
    *(self->array + self->top) = element;
}

long stack_pop(Stack self) {
    if(stack_isEmpty(self)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    --self->top;
    return *(self->array + self->top + 1);
}

void free_stack(Stack self) {
    free(self->array);
    free(self);
}
