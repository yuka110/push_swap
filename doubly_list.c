/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 12:08:18 by yitoh         #+#    #+#                 */
/*   Updated: 2023/02/15 16:23:28 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*dlstnew(int data)
{
	t_dlist	*newnode;

	newnode = (t_dlist *)malloc (sizeof(t_dlist));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->num = 0;
	return (newnode);
}

void	dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*p;

	if (!new)
		return ;
	if (!lst || !(*lst))
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
	new->prev = p;
}

void	dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	if (!lst || !(*lst))
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

int	dlst_size(t_dlist *lst)
{
	t_dlist	*ptr;
	int		count;

	count = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		++count;
	}
	return (count);
}

int	dlst_max(t_dlist *lst)
{
	t_dlist	*p1;
	t_dlist	*p2;

	p1 = lst;
	p2 = p1;
	while (p2->next)
	{
		p2 = p1->next;
		while (p2->next && p1->num > p2->num)
			p2 = p2->next;
		if (!p2->next)
			break ;
		p1 = p2;
	}
	return (p1->num);
}
