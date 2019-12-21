/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:20:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/21 01:04:35 by yhadari          ###   ########.fr       */
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
		if ((ptr[j] == 'd' || ptr[j] == 'i') && ft_printfdd(ptr, args))
			return (0);
		if ((ptr[j] == 'u' || ptr[j] == 'x' || ptr[j] == 'X') &&
			ft_uprintfdd(ptr, args))
			return (0);
		if (ptr[j] == 'c' && ft_cflag(ptr, args))
			return (0);
		if (ptr[j] == '%' && ft_pourcentage(ptr, args))
			return (0);
	}
	return (0);
}
