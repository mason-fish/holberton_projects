CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = 
OBJ = print_permissions.c
NAME = 2-print_permissions

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
