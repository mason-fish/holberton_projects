CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic
DEPS = headers.h list.h
SRC = add_to_dcl_list.c dcl_main.c print_char.c print_dcl_list.c array_to_dcl_list.c free_dcl_list.c
OBJ = $(SRC:.c=.o)
NAME = circular_dcl_list.out

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) $(OBJ) -o $(NAME)

clean:
	rm -f $(NAME) $(OBJ)

re: clean all


