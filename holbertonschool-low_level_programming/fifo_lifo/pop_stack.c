#include "headers.h"

/* pop_stack() returns a copy of the  data of the first element
 * of a stack data structure, if there is one, after freeing and
 * removing that element from the stack.
 */
char *pop_stack(Stack **stack)
{
	char *data;
	Stack *tmp;

	if (*stack == NULL)
		return NULL;
	data = strdup((*stack)->str);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp->str);
	free(tmp);
	return data;
}
