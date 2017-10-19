CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = 
OBJ = cat.c
NAME = 3-cat

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^
