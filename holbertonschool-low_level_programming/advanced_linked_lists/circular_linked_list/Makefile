CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic
DEPS = headers.h list.h
SRC = add_to_cl_list.c cl_main.c print_char.c print_cl_list.c array_to_cl_list.c free_cl_list.c
OBJ = $(SRC:.c=.o)
NAME = circular_dl_list.out

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ) -o $(NAME)

clean:
	rm -f $(NAME) $(OBJ)

re: clean all


