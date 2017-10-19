CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic
SRC = printf.c helper_functions.c spec_functions_1.c spec_functions_2.c
DEPS = headers.h
OBJ = $(SRC:.c=.o)
NAME = libprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(NAME)

re: clean all
