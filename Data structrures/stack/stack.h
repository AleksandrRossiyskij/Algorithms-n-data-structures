#ifndef STACK_H
#define STACK_H 1

#include <stdbool.h>
#include <stddef.h>

typedef struct stack* Stack;

Stack new_emptyStack();
size_t stack_sizeof(Stack);
bool stack_isEmpty(Stack);
void stack_push(Stack, long);
long stack_pop(Stack);
void free_stack(Stack);

#endif // STACK_H