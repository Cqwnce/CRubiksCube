CC = gcc
CFLAGS = -I./include  # Include directory for header files
SRC_DIR = ./src
BUILD_DIR = ./build
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/stickers.c $(SRC_DIR)/permutations.c
OBJ = $(BUILD_DIR)/main.o $(BUILD_DIR)/stickers.o $(BUILD_DIR)/permutations.o
EXEC = rubiks_cube  # Name of the final executable

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o $(CFLAGS)

$(BUILD_DIR)/stickers.o: $(SRC_DIR)/stickers.c
	$(CC) -c $(SRC_DIR)/stickers.c -o $(BUILD_DIR)/stickers.o $(CFLAGS)

$(BUILD_DIR)/permutations.o: $(SRC_DIR)/permutations.c
	$(CC) -c $(SRC_DIR)/permutations.c -o $(BUILD_DIR)/permutations.o $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)