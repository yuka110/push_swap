/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:33 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/31 15:38:08 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../personal_libft/libft.h"

typedef struct s_dlist
{
	int				data;
	int				num;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

//doubly
t_dlist	*dlstnew(int data);
void	dlstadd_back(t_dlist **lst, t_dlist *new);
void	dlstadd_front(t_dlist **lst, t_dlist *new);
int		dlst_size(t_dlist *lst);

//push_error
t_dlist	*parse_num(int argc, char **argv);
t_dlist	*split_parse(char *str);
int		error_check(t_dlist	*lst);
int		non_integer(int argc, char	**argv);
void	free_dlist(t_dlist *lst);

//push_swap
int		all_sorted(t_dlist *lst);
void	simple_num(t_dlist *a, int len);

#endif
