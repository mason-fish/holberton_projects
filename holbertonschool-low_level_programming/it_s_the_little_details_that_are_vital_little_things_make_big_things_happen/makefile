IDIR =./inc
ODIR=./src/obj
SDIR=./src

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -I$(IDIR)

_DEPS = libholbertonschool.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = absolute.o nconcat_strings.o reverse_array.o strings_compare.o cap_string.o positive_or_not.o reverse_string.o swap_int.o contact_strings.o power.o square_root.o uppercase.o first_digit.o print_array.o str_len.o uppercase_string.o is_prime_number.o print_char.o string_copy.o lowercase.o print_number.o string_ncopy.o main.o print_string.o string_to_integer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	ar -src libholbertonschool.a

.PHONY: clean

clean:
	rm -f $(OBJ)

re: all clean
