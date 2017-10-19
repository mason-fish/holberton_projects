#include "headers.h"

/* pop_queue() returns a copy of the  data of the first element
 * of a queue data structure, if there is one, after freeing and
 * removing that element from the queue.
 */
char *pop_queue(Queue **queue)
{
	char *data;
	Queue *tmp;

	if (*queue == NULL)
		return NULL;
	data = strdup((*queue)->str);
	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp->str);
	free(tmp);
	return data;
}
