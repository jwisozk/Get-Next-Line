/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:01:12 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/17 12:25:48 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*head;

	if (f == NULL)
		return (NULL);
	head = NULL;
	tmp = NULL;
	while (lst != NULL)
	{
		if (!(new = f(lst)))
		{
			free(tmp);
			return (NULL);
		}
		if (!head)
		{
			head = new;
			tmp = head;
		}
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (head);
}
