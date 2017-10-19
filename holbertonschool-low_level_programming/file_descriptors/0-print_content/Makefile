CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = 
OBJ = print_content.c
NAME = 0-print_content

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
