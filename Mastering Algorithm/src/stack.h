#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef struct List Stack;

#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stac)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#endif /* ifndef STACK_H */
