#include "shell_head.h"

/*
* execute_command() creates child processes to run
* commands.
*/
int exec_c(char **cmd, char **env)
{
        pid_t pid, child_exit;
        int status;
        char *new;
        if((pid = fork()) == -1) {
              perror("bad fork");
              return (1);
        }
        if(pid == 0) {
                if((new = find_command(cmd[0], env)) == NULL) {
                        perror("Cannot find command");
                        free_str_arr(env);
                        free_str_arr(cmd);
                        exit(EXIT_FAILURE);
                }
                cmd[0] = new;
                if (execve(cmd[0], cmd, env) == -1) {
                        perror("bad execve");
                        free_str_arr(cmd);
                        free_str_arr(env);
                        exit(EXIT_FAILURE);
                }
                exit(EXIT_SUCCESS);
        } else {
                do {
                        child_exit = waitpid(pid, &status, WUNTRACED);
                        if (child_exit == -1) {
                              	perror("bad waitpid");
                              	free_str_arr(env);
                              	free_str_arr(cmd);
                              	exit(EXIT_FAILURE);
                        }
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
                return(status);
        }
}

/* update_dir() updates the PWD and OLDPWD variables */
void update_dir(char *str, char **env) {
        char **old, *new;
        
        new = s_and_r("PWD", env);
        old = get_var("OLDPWD", env);
        free(*old);
        *old = app_ins_rep(new, "OLDPWD", '=');

        new = str;
        old = get_var("PWD", env);
        free(*old);
        *old = app_ins_rep(new, "PWD", '=');
}

/* update_ex() stores the exit code as an env variable '?' */
char **update_ex(char *str, char **env) {
        char **old, **new, *new_str;

        if((old = get_var("?", env)) == NULL) {
                new_str = app_ins_rep(str, "?", '=');
                new = add_to_vector(new_str, env);
                free_str_arr(env);
                return new;
        } else {
                free(*old);
                *old = app_ins_rep(str, "?", '=');
                return env;
        }
}

/* int_to_string() converts an int to a string */
char *int_to_string(int x) 
{
        int size, sign;
        char *cPtr;
        size = find_size(x);
        if (x < 0) {
                sign = -1;
                size++;
        }
        else {
                sign = 1;
        }
        cPtr = malloc(sizeof(char) * size + 1);
        if (cPtr == NULL) {
                return NULL;
        }
        cPtr[size--] = '\0';
        while (size >= 0) {
                if (size == 0 && sign == -1) {
                        cPtr[size] = '-';
                        size--;
                }
                else {
                        cPtr[size] = '0' + ((x % 10) * sign);
                        size--;
                        x /= 10;
                }
        }
        return cPtr;
}
 
/* find_size() returns the size of an int */
int find_size(int x) 
{
        int i;       
        i = 1;
        while (x / 10) {
                i++;
                x /= 10;
        }
        return i;
}
