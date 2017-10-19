CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic
DEPS = holberton.h
SRC = 0-main.c helpers.c
OBJ = $(SRC:.c=.o)
NAME = hls
ENV_IMG = mefish/holberton_c
ARGS = /usr/lib / /host/program/Makefile /poop

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

.PHONY: test
test:
	@echo "\n============= Compiling and Running in Ubuntu:14.04 ==============="	
	docker run --rm -v `pwd`:/host/program -w="/host/program" $(ENV_IMG) make all

.PHONY: correct
correct:
	@echo "\n========================= Correct Output =========================="
	ls $(ARGS)

.PHONY: all
all: build run correct clean

.PHONY: test-persist
test-persist:
	@echo "\n============= Compiling and Running in Ubuntu:14.04 ==============="
	docker run --name hbtn -ti --rm -v `pwd`:/host/program -w="/host/program" $(ENV_IMG)

.PHONY: run
run:
	@echo "\n============================ Running =======-======================"
	valgrind -v ./$(NAME) $(ARGS)

.PHONY: build
build: $(SRC) $(DEPS)
	@echo "\n============================ Building ============================="
	$(CC) $(CFLAGS) $(DEPS) $(SRC) -o $(NAME)

.PHONY: clean
clean:
	@echo "\n============================ Cleaning ============================="
	rm -f $(NAME) $(OBJ)

.PHONY: re
re: clean build


