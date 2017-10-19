#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queue.h"
#include "stack.h"

void print_stack(const Stack *);
void print_queue(const Queue *);
Queue *find_end_of_queue(Queue *queue);

int push_queue(Queue **, char *);
char *pop_queue(Queue **);

int push_stack(Stack **, char *);
char *pop_stack(Stack **);
