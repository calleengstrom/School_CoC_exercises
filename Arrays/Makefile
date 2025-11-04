# Enkel Makefile för att kompilera main.c

# Kompilator
CC = gcc

# Flaggor (lägg till -Wall för varningar)
CFLAGS = -Wall -Wextra -std=c11

# Målfil
TARGET = main

# Standardregel
all: $(TARGET)

# Regler för att bygga exekverbara filen
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

# Rensa byggfiler
clean:
	rm -f $(TARGET)