CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = 
OBJ = copy_content.c
NAME = 1-copy_content

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
