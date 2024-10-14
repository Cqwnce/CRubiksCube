CC = gcc
CFLAGS = -I./include  # Include directory for header files
SRC = ./src/main.c ./src/stickers.c
OBJ = main.o stickers.o
TARGET = rubiks_cube

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

# Rule to compile main.c into main.o
main.o: ./src/main.c
	$(CC) -c ./src/main.c -o main.o $(CFLAGS)

# Rule to compile stickers.c into stickers.o
stickers.o: ./src/stickers.c
	$(CC) -c ./src/stickers.c -o stickers.o $(CFLAGS)

clean:
	rm -f *.o $(TARGET)