
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Iinclude
DEBUGFLAGS = -g

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
DOC_DIR = docs
TEST_DIR = tests

# Program name
NAME = simple_shell

# Source files
SRCS = $(SRC_DIR)/Simple_main.c \
       $(SRC_DIR)/read_and_parse.c \
       $(SRC_DIR)/execute_command.c \
       $(SRC_DIR)/find_path.c \
       $(SRC_DIR)/handle_builtins.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER = $(INC_DIR)/main.h

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m # No Color

# Default rule
all: $(OBJ_DIR) $(NAME)

# Create obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile the program
$(NAME): $(OBJS)
	@echo "$(YELLOW)🔨 Linking objects...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(NC)"

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@echo "$(YELLOW)📦 Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Debug version with symbols
debug: CFLAGS += $(DEBUGFLAGS)
debug: fclean $(OBJ_DIR) $(NAME)
	@echo "$(GREEN)🐛 Debug version compiled with -g flag$(NC)"

# Clean object files
clean:
	@echo "$(RED)🧹 Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✅ Object files cleaned$(NC)"

# Clean everything
fclean: clean
	@echo "$(RED)🗑️  Removing executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)✅ All cleaned$(NC)"

# Rebuild everything
re: fclean all

# Run the program
run: $(NAME)
	@echo "$(GREEN)🚀 Running $(NAME)...$(NC)"
	@./$(NAME)

# Run with valgrind
valgrind: debug
	@echo "$(YELLOW)🔍 Running valgrind memory check...$(NC)"
	@echo "exit" | valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Show help
help:
	@echo "$(GREEN)📖 Available targets:$(NC)"
	@echo "  $(YELLOW)make$(NC) or $(YELLOW)make all$(NC)     - Compile the project"
	@echo "  $(YELLOW)make debug$(NC)           - Compile with debug symbols"
	@echo "  $(YELLOW)make clean$(NC)           - Remove object files"
	@echo "  $(YELLOW)make fclean$(NC)          - Remove all generated files"
	@echo "  $(YELLOW)make re$(NC)              - Rebuild everything"
	@echo "  $(YELLOW)make run$(NC)             - Compile and run the program"
	@echo "  $(YELLOW)make valgrind$(NC)        - Run with valgrind memory check"
	@echo "  $(YELLOW)make help$(NC)            - Show this help message"

# Phony targets
.PHONY: all clean fclean re debug run valgrind help
