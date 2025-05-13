#include "stack.h"

stack_t stack_new(int size)
{
    static int bottom = 0;
    stack_t stack = (stack_t)new_node(); // defined in list.c

    if ((stack->data = malloc(size * sizeof(int))) == NULL)
    {
        free(stack->data); // Free stack before exit
        exit(EXIT_FAILURE);
    }

    stack->top = size;
    stack->ptr = bottom;
    stack->size = size;

    return stack;
}