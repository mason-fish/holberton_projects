#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

int add_end_cl_list(List **, char *);
int add_begin_cl_list(List **, char *);
List *find_tail(List *);

void print_cl_list(List *);
int print_char(char);
void print_string(char *);

List *array_to_cl_list(char **);

void free_cl_list(List *);
