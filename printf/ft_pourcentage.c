/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcentage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:33:31 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 01:12:40 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_writepo(int num, char i)
{
	if (num > 0)
	{
		while (num-- > 1)
			ft_putchar_fd(i, 1);
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('%', 1);
		while (num-- > 1)
			ft_putchar_fd(i, 1);
		return (1);
	}
	else
		ft_putchar_fd('%', 1);
	return (1);
}

int		ft_check(const char *ptr)
{
	int i;

	i = 0;
	while (ptr[i] != '%')
	{
		if (ptr[i] == '*' && ptr[i + 1] == '.' && ptr[i + 2] == '*')
			return (1);
		if (ptr[i] == '.' && ptr[i + 1] == '*' && ptr[i + 2] == '%')
			return (2);
		i++;
	}
	return (0);
}

void	ft_pourcentage1(const char *ptr, char *i, int *num)
{
	if (*ptr == '0' && *num > 0)
		*i = '0';
	if (*ptr == '-' && !ft_cstrchr(ptr, '*'))
		*num = ft_atoi(ptr);
	if (*ptr == '-' && *num > 0)
		*num = -*num;
}

int		ft_pourcentage(const char *ptr, va_list *args)
{
	int		num;
	int		num1;
	char	i;

	num = 0;
	i = ' ';
	if (ft_cstrchr(ptr, '*'))
	{
		if (ft_check(ptr) == 1)
		{
			num = va_arg(*args, int);
			num1 = va_arg(*args, int);
		}
		else if (ft_check(ptr) == 2)
		{
			num = ft_atoi(ptr);
			num1 = va_arg(*args, int);
		}
		else
			num = va_arg(*args, int);
	}
	else if (ft_atoi(ptr) >= 0 && *ptr != '.')
		num = ft_atoi(ptr);
	ft_pourcentage1(ptr, &i, &num);
	return (ft_writepo(num, i));
}
