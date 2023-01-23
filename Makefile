# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/19 10:52:21 by yitoh         #+#    #+#                  #
#    Updated: 2023/01/23 11:08:38 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


CC = cc
SRC = push_swap.c
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
	@rm -f $(NAME) a.out
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all bonus test

test: $(NAME)
	@$(CC) $(CFLAG) *.c $(LIBFT_DIR)/*.c -o ./push_swap
