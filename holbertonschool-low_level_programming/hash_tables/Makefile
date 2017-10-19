CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
DEPS = headers.h hashtable.h
SRC = hash.c print_char.c ht_create.c ht_put.c ht_get.c ht_free.c 
MAIN = main.c
OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)
NAME = HASH.out

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $^ -o $(NAME) 

clean:
	rm -f $(OBJ) $(NAME)

re: clean all
