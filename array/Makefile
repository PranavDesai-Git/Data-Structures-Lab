CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC_DIR = src
OBJ_DIR = obj
TARGET = dsa_array

# 1. Get all .c files in src/, then remove main.c so we handle it manually
ALL_SRC = $(wildcard $(SRC_DIR)/*.c)
SRC = $(filter-out $(SRC_DIR)/main.c, $(ALL_SRC))

# 2. Build OBJ list: explicitly add main.o, then the rest
OBJ = $(OBJ_DIR)/main.o $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Rule for main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for other .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) compile_commands.json

.PHONY: all clean
