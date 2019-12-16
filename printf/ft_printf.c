/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:25:56 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 22:44:52 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *ptr, ...)
{
	va_list		args;
	int			i;

	count = 0;
	point = 0;
	i = 0;
	va_start(args, ptr);
	while (ptr[i] != '\0')
	{
		while (ptr[i] != '%')
		{
			if (ptr[i] == '\0')
				return (count);
			ft_putchar_fd(ptr[i], 1);
			i++;
		}
		ft_checkptr(ptr + i + 1, &i, &args);
		i++;
	}
	va_end(args);
	return (count);
}
