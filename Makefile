# Compiler
CC = cc

#Directories
SRC_DIR = src
LIBFT_DIR = libft
VPATH = src:libft:includes:map

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g
INCFLAGS = -Iincludes -Ilibft/includes

# Main project files
SRC_FILES = so_long.c arg_input.c map_handling.c main.c map_validation.c\
utils.c walls.c collectibles.c flood_fill.c
#flood_fill.c
OBJ_FILES = $(SRC_FILES:.c=.o)
EXECUTABLE = so_long

# Libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)/includes
LIBFT_LINK = -L$(LIBFT_DIR) -lft

all: $(EXECUTABLE)
	@echo "\033[1;32m[✔] GOOD HEAVENS! LOOK AT THE EXECUTABLE!\033[0m"

$(EXECUTABLE): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_LINK) -o $(EXECUTABLE)
	@echo "\033[1;33m[✔] Compiling so_long...\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) $(LIBFT_INC) -c $< -o $@

$(LIBFT): $(LIBFT_MAKEFILE)
	$(MAKE) -C $(LIBFT_DIR)
	@echo "\033[1;33m[✔] Linking to libft Makefile...\033[0m"

$(LIBFT_MAKEFILE):
	@echo "Creating symbolic link for libft Makefile..."
	ln -s $(CURDIR)/$(LIBFT_MAKEFILE) $(LIBFT_MAKEFILE)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[1;33m[X] Cleaning...\033[0m"
	rm -f $(OBJ_FILES) $(DEP)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[1;31m[XXX] Cleaning it GOOOOOOD...\033[0m"
	rm -f $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re