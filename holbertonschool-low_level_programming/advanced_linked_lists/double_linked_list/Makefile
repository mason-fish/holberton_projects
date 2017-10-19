CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic
DEPS = headers.h list.h
SRC = print_char.c add_to_dl_list.c dl_main.c print_dl_list.c array_to_dl_list.c free_dl_list.c
OBJ = $(SRC:.c=.o)
NAME = TEST.out

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(DEPS) -o $(NAME)

clean:
	rm -f $(NAME) $(OBJ)

re: clean all
