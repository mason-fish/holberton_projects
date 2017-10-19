CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = cross.c print_char.c helper_func.c
DEPS = headers.h
OBJ = $(SRC:.c=.o)
NAME = CROSS

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	rm -f $(OBJ) $(NAME)

re: clean all 
