/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:26:07 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 23:56:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_cflag1(const char *ptr, va_list *args, char valg, int valg1)
{
	if (*ptr == '*' || (*ptr == '-' && ft_cstrchr(ptr, '*')))
	{
		valg1 = (int)valg;
		valg = (char)va_arg(*args, int);
		if (valg1 <= 0)
		{
			valg1 = -valg1;
			ft_putchar_fd(valg, 1);
			while (valg1-- > 1)
				ft_putchar_fd(' ', 1);
			return (1);
		}
	}
	else
		valg1 = ft_atoi(ptr);
	while (valg1-- > 1)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd(valg, 1);
	return (1);
}

int		ft_cflag(const char *ptr, va_list *args)
{
	char	valg;
	int		valg1;

	valg1 = 0;
	valg = (char)va_arg(*args, int);
	if (*ptr == 'c' || (*ptr == '.' && *(ptr + 1) == 'c'))
		ft_putchar_fd(valg, 1);
	if (ft_cisdigit(ptr) || *ptr == '*' || (*ptr == '-' &&
				ft_cstrchr(ptr, '*')))
		return (ft_cflag1(ptr, args, valg, valg1));
	if (*ptr == '-')
	{
		valg1 = -ft_atoi(ptr);
		if (ft_cstrchr(ptr, '*'))
		{
			valg1 = (int)valg;
			valg = (char)va_arg(*args, int);
		}
		ft_putchar_fd(valg, 1);
		while (valg1-- > 1)
			ft_putchar_fd(' ', 1);
	}
	return (1);
}
