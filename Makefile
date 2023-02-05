# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/19 10:52:21 by yitoh         #+#    #+#                  #
#    Updated: 2023/02/05 16:19:59 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC = cc
SRC = push_swap.c doubly.c push_error.c push_trio.c push_operation1.c push_operation2.c\
		push_operation3.c
OBJ = $(SRC:.c=.o)
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = push_swap.a
LIBFT_DIR = ../personal_libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@ar -crs $@ $(OBJ)

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
	@rm -f $(NAME) push_swap
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all bonus test

test: $(NAME)
	@$(CC) $(CFLAG) *.c $(LIBFT_DIR)/*.c -o ./push_swap
