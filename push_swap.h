/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 10:52:33 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/15 16:21:01 by yitoh         ########   odam.nl         */
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
int		dlst_max(t_dlist *lst);

//push_error
t_dlist	*over_twoargs(int argc, char **argv, t_dlist *lst);
t_dlist	*parse_num(int argc, char **argv);
t_dlist	*split_parse(char *str);
int		error_check(t_dlist	*lst);
int		non_integer(int argc, char	**argv);

//push_swap
int		all_sorted(t_dlist *lst);
void	simple_num(t_dlist **a, int len, int min);
int		bit_count(int nbr);
void	radix_sort(t_dlist **a, t_dlist **b, int len);
void	free_dlist(t_dlist *lst);

//push_trio
void	sort_three(t_dlist **lst);
void	small_sort(t_dlist **a, t_dlist **b, int len);
void	push_top(t_dlist **a, int len, int index, int i);

//push_operation1
void	ft_swap(t_dlist **lst);
void	ft_rotate(t_dlist **lst);
void	ft_reverser(t_dlist **lst);
void	ft_push(t_dlist **dst, t_dlist **src);
void	sa_action(t_dlist **a);

//push_operation2
void	sb_action(t_dlist **b);
void	ss_action(t_dlist **a, t_dlist **b);
void	ra_action(t_dlist **a);
void	rb_action(t_dlist **b);
void	rr_action(t_dlist **a, t_dlist **b);

//push_operation3
void	rra_action(t_dlist **a);
void	rrb_action(t_dlist **b);
void	rrr_action(t_dlist **a, t_dlist **b);
void	pb_action(t_dlist **a, t_dlist **b);
void	pa_action(t_dlist **b, t_dlist **a);

#endif
