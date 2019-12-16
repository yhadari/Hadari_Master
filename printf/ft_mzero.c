/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 23:03:55 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/15 23:17:45 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_con(char a, char *ptr)
{
	char *p;
	int i;
	int j;

	j = 0;
	i = ft_strlen(ptr) + 1;
	p = malloc(i + 1);
	p[j++] = a;
	while (*ptr)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

int		ft_mzero(const char *ptr, long *valg, va_list *args, int *k)
{
	int i;
	int j;
	long num;
	char *p;

	i = *valg;
	j = va_arg(*args, int);
	num = va_arg(*args, int);

	if (*ptr == '-')
	{
		if (i > 0)
			i = -i;
		p = ft_join(ft_itoa(i), ft_itoa(j), '.');
	}
	if (*ptr == '0')
	{
		if (j < 0)
		{
			if (i <= 0)
				p = ft_itoa(i);
			else
				p = ft_con('0', ft_itoa(i));
		}
		if (j >= 0)
		{
			if (i <= 0)
				p = ft_join(ft_itoa(i), ft_itoa(j), '.');
			else
			{
				p = ft_con('0', ft_itoa(i));
				p = ft_join(p, ft_itoa(j), '.');
			}
		}
	}
	if (ft_isdigit(p) || (*p == '-' && checkpoint(p + 1)))
	{
		ft_checknum1(p, &num, k);
		if (num == 0 && p[0] != '-' && (p[0] == '.' || point != 0))
			return (1);
		if (num != 0 || (num == 0 && ft_strchr(p, '.') && ft_atoi(p) > ft_atoi(ft_strchr(p, '.'))) ||
				(num == 0 && !ft_strchr(p, '.')))
			ft_putnbr_fd(num, 1);
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	if (*p == '-' && !checkpoint(p + 1))
	{
		ft_putnbr_fd(num, 1);
		ft_checknum1(p, &num, k);
	}
	return (1);
}
