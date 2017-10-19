/* header files for marcel_the_shell */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define TRUE 1

char *read_line(int);
void copy_string(char *, char *, int);
int pre_process_comments(char *);
char *first_in_string(char, char *);
char **string_split(char *, char);
int count_chars(char *, char);
int count_words(char *, char);
int exec_c(char **, char **);
char *app_ins_rep(char *, char *, char);
void update_dir(char *, char **);
char *s_and_r(char *, char **);
char **get_var(char *, char **);
char *find_command(char *, char **);
void free_str_arr(char **);
void sig_handle_ctl_c(int);
void update_dir(char *, char **);
char *glue_strings(char **, char);
int str_cmp(char *, char *);
int check_b(int, char **, char **);
char **check_b_e(int, char **, char **);
char *parse_path(char *);
char **copy_vector(char **);
char **remove_from_vector(char **, char **);
char **add_to_vector(char *, char **);
char **get_vector_element(char *, char **);
int print_char(char);
void print_string(char *);
int char_is_char(char);
int char_is_num(char);
void cut_string(char*, int, char*);
int make_number(char*, int, int);
int expon(int);
int string_to_integer(char *);
char **update_ex(char *, char **);
char *int_to_string(int);
int find_size(int);
