# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/19 10:52:21 by yitoh         #+#    #+#                  #
#    Updated: 2023/02/21 10:37:56 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
SRC = push_swap.c doubly_list.c push_error.c push_trio.c mod_lib.c\
		push_operation1.c push_operation2.c push_operation3.c main.c
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = push_swap
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAG) $^ -o $@

%.o: %.c
	@$(CC) -c $(CFLAG) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all
