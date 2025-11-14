
# Compiler och flaggor
CC = gcc
CFLAGS = -g -Wall -Wextra -std=c11 -Iinclude

# Källfiler
SRC = main.c ../bank/bank.c
OBJ = $(SRC:.c=.o)

# Namn på det körbara programmet
EXEC = main

# Standardmål
all: $(EXEC)

# Länka objektfiler till körbar fil
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Kompilera .c till .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rensa objekt och körbar fil
clean:
	rm -f $(OBJ) $(EXEC)
