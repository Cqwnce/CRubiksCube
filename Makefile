CC = gcc
CFLAGS = -I./include  # Include directory for header files
SRC = ./src/main.c ./src/helper.c
OBJ = main.o helper.o
TARGET = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(CFLAGS)

# Rule to compile main.c into main.o
main.o: ./src/main.c
	$(CC) -c ./src/main.c -o main.o $(CFLAGS)

# Rule to compile helper.c into helper.o
helper.o: ./src/helper.c
	$(CC) -c ./src/helper.c -o helper.o $(CFLAGS)

clean:
	rm -f *.o $(TARGET)