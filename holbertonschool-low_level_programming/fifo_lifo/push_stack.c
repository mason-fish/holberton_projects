#include "headers.h"

/*
 * push_stack() adds an element to a
 * stack data structure.
 */
int push_stack(Stack **stack, char *data)
{
        Stack *new;

        new = malloc(sizeof(Stack));
        if (new == NULL)
                return(1);
        new->str = strdup(data);
        if (*stack == NULL)
                new->next = NULL;
        else
                new->next = *stack;
        *stack = new;
        return(0);
}
