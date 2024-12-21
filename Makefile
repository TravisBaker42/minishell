# Make file working and not relinking
# No getnextline
# Every thing else in libft should be working & excessable from the "minishell.h"
# Remove test.c from SRC
# Remove comment block before final testing
NAME		:= 	minishell

INC_DIR		:= 	include/
INCLUDE		:= 	-I $(INC_DIR)

CC			:= 	gcc
CFLAGS		:= 	-Wall -Wextra -Werror -g
LDFLAGS		:= 	-lreadline 
RM			:= 	rm -rf

SRC_DIR		:= 	src
SRC_FILES	:= 	minishell.c lexer.c lexer_utils.c utils.c lexer_token_functions_1.c \
				lexer_token_functions_2.c
SRC			:= 	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= 	build
OBJ_FILES	:= 	$(SRC_FILES:.c=.o)
OBJ			:= 	$(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

LIB_DIR		:= 	libft
LIBFT		:= 	$(LIB_DIR)/libft.a
 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $@ $(LDFLAGS) $(LIBFT)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIB_DIR) clean
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
