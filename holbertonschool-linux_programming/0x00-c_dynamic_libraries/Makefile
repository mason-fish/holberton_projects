CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic
DEPS = holberton.h
SRC = 0-main.c prototypes.c
OBJ = $(SRC:.c=.o)
NAME = program
ENV_IMG = mefish/holberton_c

# Help
.PHONY: default
default:
	@echo "Please specify a build target. The choices are:"
	@echo "     run:          Build and run program in ubuntu:14.04"
	@echo "     build:        Compile program"	
	@echo "     clean:        Cleanup object files and executables"
	@echo "     re:           Clean, then Build"

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: run
run:
	@echo "============= Compiling and Running in Ubuntu:14.04 ==============="	
	docker run --rm -v `pwd`:/host/program -w="/host/program" $(ENV_IMG) make build

.PHONY: build
build: $(SRC) $(DEPS)
	@echo "============================ Building ============================="
	$(CC) $(CFLAGS) $(DEPS) $(SRC) -o $(NAME) && ./$(NAME)

.PHONY: clean
clean:
	@echo "============================ Cleaning ============================="
	rm -f $(NAME) $(OBJ)

.PHONY: re
re: clean build


