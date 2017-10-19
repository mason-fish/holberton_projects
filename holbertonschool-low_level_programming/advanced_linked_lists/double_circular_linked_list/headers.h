#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

int add_end_dcl_list(List **, char *);
int add_begin_dcl_list(List **, char *);
List *find_tail(List *);

void print_dcl_list(List *);
int print_char(char);
void print_string(char *);

List *array_to_dcl_list(char **);

void free_dcl_list(List *);
