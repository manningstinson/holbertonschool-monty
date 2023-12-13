CC = gcc
CFLAGS = -Wall -Werror -pedantic -Wextra
SRC = main.c stack.c add.c error.c instruction.c nop.c pall.c pint.c pop.c push.c
OBJ = $(SRC:.c=.o)
EXEC = monty

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

clean_all:
	rm -f $(OBJ) $(EXEC)
