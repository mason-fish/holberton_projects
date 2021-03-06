#include "shell_head.h"
#include "shell_builtins.h"

/* copy_vector() copies a double char pointer */
char **copy_vector(char **str_arr)
{
        int i, i2;
        char **new_arr;
        if (str_arr == NULL) {
                return NULL;
        }
        for(i = 0; str_arr[i] != NULL; i++) {}
        if((new_arr = malloc(sizeof(char *) * (i + 1))) == NULL) {
                return NULL;
        }
        for(i = 0; str_arr[i] != NULL; i++) {
                for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {}
                if((new_arr[i] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
                        free_str_arr(new_arr);
                        return NULL;
                }
                for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {
                        new_arr[i][i2] = str_arr[i][i2];
                }
                new_arr[i][i2] = '\0';
        }
        new_arr[i] = NULL;
        return new_arr;
}

/*
 * remove_from_vector() removes an element and re allocates
 * a vector.
 */
char **remove_from_vector(char **str, char **str_arr)
{
        int i, i2, i3;
        int flag;
        char **new_arr;
        flag = 0;        
        if (str_arr == NULL) {
                return NULL;
        }
        for(i = 0; str_arr[i] != NULL; i++) {}
        if((new_arr = malloc(sizeof(char *) * (i))) == NULL) {
                return NULL;
        }
        for(i = 0, i3 = 0; str_arr[i] != NULL; i++, i3++) {
                if (str_cmp(*str, str_arr[i]) == 0 && flag == 0) {
                        flag++;
                        i3--;
                }
                else {
                        for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {}
                        if((new_arr[i3] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
                                free_str_arr(new_arr);
                                return NULL;
                        }
                        for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {
                                new_arr[i3][i2] = str_arr[i][i2];
                        }
                        new_arr[i3][i2] = '\0';
                }
        }
        new_arr[i3] = NULL;
        return new_arr;
}


/* add_to_vector() adds a string to a vector, through reallocation */
char **add_to_vector(char *str, char **str_arr)
{
        int i, i2;
        char **new_arr;
        if (str_arr == NULL) {
                return NULL;
        }
        for(i = 0; str_arr[i] != NULL; i++) {}
        if((new_arr = malloc(sizeof(char *) * (i + 2))) == NULL) {
                return NULL;
        }
        for(i = 0; str_arr[i] != NULL; i++) {
                for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {}
                if((new_arr[i] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
                        free_str_arr(new_arr);
                        return NULL;
                }
                for(i2 = 0; str_arr[i][i2] != '\0'; i2++) {
                        new_arr[i][i2] = str_arr[i][i2];
                }
                new_arr[i][i2] = '\0';
        }
        for(i2 = 0; str[i2] != '\0'; i2++) {}
        if((new_arr[i] = malloc(sizeof(char) * (i2 + 1))) == NULL) {
                free_str_arr(new_arr);
                return NULL;
        }
        for(i2 = 0; str[i2] != '\0'; i2++) {
                new_arr[i][i2] = str[i2];
        }
        new_arr[i][i2] = '\0';
        i++;
        new_arr[i] = NULL;
        free(str);
        return new_arr;
}

/* get_vector_element() returns a pointer to a targeted array's string */
char **get_vector_element(char *search, char **env)
{
        int i;
        if (search == NULL) {
                perror("No search criteria");
                return NULL;
        }
        
        for(i = 0; env[i] != NULL; i++) {
                if ((str_cmp(env[i], search)) == 0) {
                        return &(env[i]);
                }
        }        
        return NULL;
}

/* glue_strings() concatenates an array of strings with a seperator */
char *glue_strings(char **str_arr, char seperator)
{
        int i, i2, i3;
        char *new_string;        
        i2 = 0;
        for(i = 0; str_arr[i] != NULL; i++) {
                for(i3 = 0; str_arr[i][i3] != '\0'; i3++, i2++) {}
        }        
        new_string = malloc(sizeof(char) * (i + i2 + 1));
        if (new_string == NULL) {
                return NULL;
        }        
        i2 = 0;
        for(i = 0; str_arr[i] != NULL; i++) {
                new_string[i2] = seperator;
                i2++;
                for(i3 = 0; str_arr[i][i3] != '\0'; i3++, i2++) {
                        new_string[i2] = str_arr[i][i3];
                }
        }
        new_string[i2] = '\0';        
        return new_string; 
}

