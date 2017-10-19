#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int print_char(char);
int add_end_dl_list(List **, char *);
int add_begin_dl_list(List **, char *);
List *get_tail(List **);

void print_dl_list(List *);
void print_string(char *);

List *array_to_dl_list(char **);

void free_dl_list(List *);
