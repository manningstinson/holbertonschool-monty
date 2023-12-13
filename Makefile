CC = gcc
CFLAGS = -Wall -Werror -pedantic -Wextra
SRC = main.c stack.c create_stack.c parse_instruction.c execute_simple_instruction.c free_stack.c stack_overflow.c stack_push.c
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
