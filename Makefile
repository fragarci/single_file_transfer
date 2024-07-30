# Files Setup
NAME = sft

SRC_DIR = src
OBJ_DIR = obj

CFILES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
INCLUDE = -I inc

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(INCLUDE) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $(INCLUDE) $<

clean:
	@rm -rf $(OBJ_DIR)
	@clear

fclean: clean
	@rm $(NAME)
	@clear

re: fclean all

.PHONY : all clean fclean re
