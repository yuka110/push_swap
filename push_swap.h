/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:33 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/03 16:03:34 by yitoh         ########   odam.nl         */
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
t_dlist	*pop_push(t_dlist *dst, t_dlist *src);

//push_error
t_dlist	*parse_num(int argc, char **argv);
t_dlist	*split_parse(char *str);
int		error_check(t_dlist	*lst);
int		non_integer(int argc, char	**argv);
void	free_dlist(t_dlist *lst);

//push_swap
int		all_sorted(t_dlist *lst);
void	simple_num(t_dlist *a, int len);

//push_trio
t_dlist	*which_cases(t_dlist *lst);
t_dlist	*ft_swap(t_dlist *lst);
t_dlist	*ft_rotate(t_dlist *lst);
t_dlist	*ft_reverser(t_dlist *lst);
t_dlist	*ft_push(t_dlist *lst1, t_dlist *lst2);

//push_operation1
t_dlist	*sa_action(t_dlist *a);
t_dlist	*sb_action(t_dlist *b);
t_dlist	*ra_action(t_dlist *a);
t_dlist	*rb_action(t_dlist *b);

//push_operation2
t_dlist	*rra_action(t_dlist *a);
t_dlist	*rrb_action(t_dlist *b);
t_dlist	*pb_action(t_dlist *a, t_dlist *b);
t_dlist	*pa_action(t_dlist *b, t_dlist *a);

#endif
