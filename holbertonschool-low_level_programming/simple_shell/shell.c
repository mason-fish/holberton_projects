#include "shell_head.h"

/*
* main function of marcel_the_shell -
* reads the user input, checks for builtins,
* checks for builtin environmentals,
* and attempts to execute command
*/
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **argv, char **env) 
{
        char **shell_cmd, **shell_env, **check, *input, *int_str;
        int ex_status, shell_ac;        
        shell_env = copy_vector(env);        
        signal(SIGINT, sig_handle_ctl_c);      
        while(TRUE) {
                input = read_line(0);
                if((ex_status = pre_process_comments(input)) == 1) {
                        free(input);
                        continue;
                }
                shell_ac = count_words(input, ' ');
                shell_cmd = string_split(input, ' ');
                free(input);
                if((ex_status = check_b(shell_ac, shell_cmd, shell_env)) != -1) {
                        free_str_arr(shell_cmd);
                        continue;
                }
                if((check = check_b_e(shell_ac, shell_cmd, shell_env)) != NULL) {
                        shell_env = check;
                        free_str_arr(shell_cmd);
                        continue;
                }
                if((ex_status = exec_c(shell_cmd, shell_env)) == EXIT_FAILURE) {
                        free_str_arr(shell_env);
                        free_str_arr(shell_cmd);
                        exit(ex_status);
                }
                int_str = int_to_string(ex_status);
                shell_env = update_ex(int_str, shell_env);
                free(int_str);
                free_str_arr(shell_cmd);
        }        
        exit(0);       
}

/*
 * this function is a way to handle ctl_c.
 * If ctl_c is tryped into the shell
 * you are prompted to type 'exit' to quit
 */
void sig_handle_ctl_c(int sign)
{
        char prompt[] = ">>> ";

        signal(sign, SIG_IGN);
        write(1 , "\nPlease type 'exit' to quit.\n", 29);
        write(1, prompt, 4);
        signal(SIGINT, sig_handle_ctl_c);
}
