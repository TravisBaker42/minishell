# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeschill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 14:29:19 by jeschill          #+#    #+#              #
#    Updated: 2025/02/16 14:32:52 by tbaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := testing

CC          := cc
CFLAGS      := -g -O3 -Wall -Wextra -Werror

#Paths
LIB_DIR     := lib/
INC_LIB     := includes/
B_DIR		:= builtins/

LIBFT_DIR   := $(LIB_DIR)libft/

#Source files
SRC_FILES   := utils.c cmd_exec.c executor.c redir.c $(B_DIR)builtins.c \
##$(B_DIR)ft_cd.c $(B_DIR)ft_echo.c $(B_DIR)ft_pwd.c

#Object files
OBJ_FILES   :=$(SRC_FILES:.c=.o)

#library settings
INC_FLAGS   := -I$(INC_LIB)
LIB_FLAGS   := -L$(LIBFT_DIR) -lft

#Rules
all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIB_FLAGS) -o $(NAME) -v

%.o: %.c 
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean 

re: fclean all 

.PHONY: all clean fclean re

