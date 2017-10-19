#include "shell_head.h"
#include "shell_builtins.h"

/* pre_process_comments() replaces # with '\0' */
int pre_process_comments(char *str)
{
        char *target;
        if((target = first_in_string('#', str)) != NULL) {
	        *target = '\0';
	}
	if(*str == '\0') {
	        return (1);
	} 
	else {
	        return (0);
	}
}

/* first_in_string() finds the first occurence in a string */
char *first_in_string(char c, char *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i++) {
	  if (str[i] == c) {
	    return &(str[i]);
	  }
	}

	return NULL;
}


