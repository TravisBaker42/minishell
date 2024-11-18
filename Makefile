NAME		:= minishell

INC_DIR		:= include/
INCLUDE		:= -I $(INC_DIR) $(LIB_DIR)

C			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
LDFLAGS		:= -lreadline 
RM			:= rm -rf

SRC_DIR		:= src
SRC_FILES	:= main.c
SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR	:= build
OBJ_FILES	:= $(SRC_FILES:.c=.o)
OBJ			:= $(addprefix $(BUILD_DIR)/, $(OBJ_FILES)) 

LIB_DIR		:= libft
LIBFT		:= $(LIB_DIR)/libft.a
LIBFT_FLAGS	:= -L$(LIB_DIR) -lft
 

all: $(NAME)

$(NAME): $(OBJ) libft
	$(C) $(CFLAGS) $(INCLUDE) $(OBJ) -o $@ $(LDFLAGS) $(LIBFT_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(BUILD_DIR)
	$(C) $(CFLAGS) $(INCLUDE)-c $< -o $@

libft:
	make -C $(LIB_DIR)/

clean:
	$(RM) $(BUILD_DIR)/
	$(MAKE) -C $(LIB_DIR) clean
	@echo "clean"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re libft
