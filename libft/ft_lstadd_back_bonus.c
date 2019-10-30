/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:58:47 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/29 21:06:49 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!alst)
		return ;
	if (*alst)
	{
		ptr = ft_lstlast(*alst);
		ptr->next = new;
	}
	if (!*alst)
		*alst = new;
}
