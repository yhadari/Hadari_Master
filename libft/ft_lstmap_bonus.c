/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:58:52 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/30 21:46:36 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*delete(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (lst);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lst1;
	t_list *ptr;

	lst1 = NULL;
	ptr = lst1;
	while (lst)
	{
		if (ptr)
		{
			ptr->next = ft_lstnew(f(lst->content));
			if (!(ptr->next))
				return (delete(ptr->next, del));
			ptr = ptr->next;
		}
		else
		{
			lst1 = ft_lstnew(f(lst->content));
			if (!lst1)
				return (delete(lst1, del));
			ptr = lst1;
		}
		lst = lst->next;
	}
	return (lst1);
}
