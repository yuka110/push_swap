/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 12:08:18 by yitoh         #+#    #+#                 */
/*   Updated: 2023/01/26 15:16:46 by yitoh         ########   odam.nl         */
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
	while (p->next != NULL)
		p = p->next;
	p->next = new;
	new->prev = p;
}

void	dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!new)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
