#include "shell_head.h"
#include "shell_builtins.h"

/* creates a built in exit command */
int builtin_exit(int ac, char **cmd, __attribute__((unused)) char **env)
{
        int i;
        char *check;
        if (ac == 1) {
                free_str_arr(env);
                free_str_arr(cmd);
                exit(0);
        }
        if (ac > 2) {
                print_string("'exit' takes only one argument\n");
                return (1);
        }
        check = cmd[1];
        for (i = 0; check[i] != '\0'; i++) {
                if (char_is_num(check[i])) {
                        print_string("Argument must be a number\n");
                        return (1);
                }
        }
        i = string_to_integer(cmd[1]);
        free_str_arr(env);
        free_str_arr(cmd);
        exit(i);
}

/* changes directory('cd' functionality) */
int builtin_cd(int ac, char **cmd, char **env)
{
        char *pre, *post, *result;
        if (ac > 2) {
                print_string("'cd' takes only up to one argument\n");
                return(1);
        }
	if (ac == 2 && str_cmp(cmd[1], "-") == 0) {
	        result = app_ins_rep("\0", s_and_r("OLDPWD", env), '\0');
     	        chdir(result);
		update_dir(result, env);
		free(result);
		return (0);
	}
        if (ac == 2) {
                if (chdir(cmd[1]) != 0) {
                        perror("bad cd");
                        return (1);
                }
		if (cmd[1][0] == '/') {
		        update_dir(cmd[1], env);
		        return (0);
		} 
		pre = app_ins_rep(cmd[1], s_and_r("PWD", env), '/');
		post = parse_path(pre);
		free(pre);
		update_dir(post, env);
		free(post);
        }
        if (ac == 1) {
	        result = app_ins_rep("\0", s_and_r("HOME", env), '\0');
                chdir(result);
		update_dir(result, env);
		free(result);
		return (0);
        }
	return (0);
}

/* parse_path() filters out a directory path */
char *parse_path(char *str) 
{
        int i;
        char **temp, **scan, *new, *backup;
	scan = string_split(str, '/');
	for (i = 0; scan[i] != NULL; i++) {
                if ((str_cmp(scan[i], "..")) == 0 && i > 0) {
                        temp = remove_from_vector(&(scan[i]), scan);
                        free_str_arr(scan);
                        scan = remove_from_vector(&(temp[i - 1]), temp);
                        free_str_arr(temp);
                        i = -1;
                } else if (str_cmp(scan[i], ".") == 0 || str_cmp(scan[i], "..") == 0) {
                        temp = remove_from_vector(&(scan[i]), scan);
                        free_str_arr(scan);
                        scan = temp;
                        i = -1;
                }
	}        
	if (*scan == NULL) {
                backup = malloc(sizeof(char) * 2);
                backup[0] = '/';
                backup[1] = '\0';
                free(scan);
                return backup; 
	}
	new = glue_strings(scan, '/');
	free_str_arr(scan);        
	return new;
}

int builtin_env(int ac, __attribute__((unused)) char **cmd, char **env)
{
        int i;

        if(ac > 1) {
                print_string("'env' takes no arguments\n");
                return (1);
        }
        for (i = 0; env[i] != NULL; i++) {
                print_string(env[i]);
                print_char('\n');
        }

        return (0);
}

char **builtin_setenv(int ac, char **cmd, char **env)
{
        char *new, **target;

        if((str_cmp(cmd[1], "PWD")) == 0) {
                print_string("That's a terrible idea. Please type 'help' for a proper Holberton lecture!\n");
                return NULL;
        }
        if(ac > 3) {
                print_string("'setenv' takes only two arguments\n");
                return NULL;
        }
        if(ac == 2 || ac == 1) {
                print_string("'setenv' needs two arguments\n");
                return NULL;
        }

        if((target = get_var(cmd[1], env)) == NULL) {
                new = app_ins_rep(cmd[2], cmd[1], '=');
                target = add_to_vector(new, env);
                free_str_arr(env);
                print_string("Run 'env' to see your changes\n");
                return target;
        }
        else {
                new = app_ins_rep(cmd[2], cmd[1], '=');
                free(*target);
                *target = new;
                print_string("Run 'env' to see your changes\n");
                return env;
        }

        return env;
}

char **builtin_unsetenv(int ac, char **cmd, char **env)
{
        char **target;
        char **new_env;

        if(ac == 2 && (str_cmp(cmd[1], "PWD")) == 0) {
                print_string("That's a terrible idea. Please type 'help' for a proper Holberton lecture!\n");
                return NULL;
        }
        if(ac > 2) {
                print_string("'unsetenv' takes only one argument\n");
                return NULL;
        }
        if(ac == 1) {
                print_string("'unsetenv' needs one argument\n");
                return NULL;
        }

        target = get_var(cmd[1], env);
        new_env = remove_from_vector(target, env);
        free_str_arr(env);
        print_string("Run 'env' to see your changes\n");
        return (new_env);
}
