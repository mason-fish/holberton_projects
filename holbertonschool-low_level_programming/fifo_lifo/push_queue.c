
#include "headers.h"

/*
 * push_queue() adds an element to a
 * queue data structure (so the end).
 */
int push_queue(Queue **queue, char *data)
{
	Queue *new, *end;

	new = malloc(sizeof(Queue));
	if (new == NULL)
		return(1);
	new->str = strdup(data);
	new->next = NULL;
	if (*queue == NULL) {
		*queue = new;
	} else {
		end = find_end_of_queue(*queue);
		end->next = new;
	}
	return(0);
}

/*
 * find_end_of_queue() takes a Queue and finds the
 * final element.
 */
Queue *find_end_of_queue(Queue *queue)
{
	Queue *scanner;

	if (queue == NULL)
		return NULL;
	scanner = queue;
	while (scanner->next != NULL) {
		scanner = scanner->next;
	}
	return scanner;
}
