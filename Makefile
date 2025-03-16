CC = gcc 
CFLAGS = -Wall -Wextra -g -Iheaders
TARGET = build/c-redis 

SRC = $(wildcard main.c) $(wildcard src/*.c) 

OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

vpath %.c . src 

all: $(TARGET) 

$(TARGET): $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) 
