# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g
INCFLAGS = -Iincludes

# Main project files
SRC_FILES = so_long.c arg_input.c map_handling.c main.c check_map.c
OBJ_FILES = $(SRC_FILES:.c=.o)
EXECUTABLE = so_long

# Directories
LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)/includes
LIBFT_LINK = -L$(LIBFT_DIR) -lft

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LINK) -o $(EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) $(LIBFT_INC) -c $< -o $@

$(LIBFT): $(LIBFT_MAKEFILE)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT_MAKEFILE):
	@echo "Creating symbolic link for libft Makefile..."
	ln -s $(CURDIR)/$(LIBFT_MAKEFILE) $(LIBFT_MAKEFILE)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES) $(DEP)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
