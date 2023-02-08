# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/19 10:52:21 by yitoh         #+#    #+#                  #
#    Updated: 2023/02/08 18:55:49 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC = cc
SRC = push_swap.c doubly.c push_error.c push_trio.c push_operation1.c push_operation2.c\
		push_operation3.c push_radix.c main.c
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = push_swap
LIBFT_DIR = ../personal_libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAG) *.c $(LIBFT_DIR)/*.c -o ./push_swap

%.o: %.c
	@$(CC) -c $(CFLAG) $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all clean
	@mv $(LIBFT) $(NAME)

#$(BUILDDIR):
#	@mkdir $(BUILDDIR)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all

# test: $(NAME)
# 	@$(CC) $(CFLAG) *.c $(LIBFT_DIR)/*.c -o ./push_swap
