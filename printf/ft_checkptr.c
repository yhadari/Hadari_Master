/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:20:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/03 18:03:14 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checkptr(const char *ptr, int *i, va_list *args)
{
	int j;

	j = 0;
	while (ft_strchr("-.*0123456789", ptr[j]))
	{
		j++;
		(*i)++;
	}
	(*i)++;
	while (ptr[j] != '\0')
	{
		if (ptr[j] == 'd' && ft_printfdd(ptr, args))
			return (0);
	}
	return (0);
}