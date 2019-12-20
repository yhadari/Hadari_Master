/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 23:03:55 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/19 23:50:54 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_con(char a, char *ptr)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = ft_strlen(ptr) + 1;
	p = malloc(i + 1);
	p[j++] = a;
	while (*ptr)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

char	*ft_join(char *a, char *b, char c)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = (ft_strlen(a) + ft_strlen(b) + 1);
	if (*b == '-')
		i = (ft_strlen(a) + 1);
	p = malloc(i + 1);
	while (*a && i--)
		p[j++] = *a++;
	if (*b != '-')
	{
		p[j++] = c;
		while (*b && i--)
			p[j++] = *b++;
	}
	p[j] = '\0';
	return (p);
}

void	ft_mzero1(char **p, const char *ptr, int *i, int *j)
{
	if (*ptr == '0')
	{
		if (*j < 0)
		{
			if (*i <= 0)
				*p = ft_itoa(*i);
			else
				*p = ft_con('0', ft_itoa(*i));
		}
		if (*j >= 0)
		{
			if (*i <= 0)
				*p = ft_join(ft_itoa(*i), ft_itoa(*j), '.');
			else
			{
				*p = ft_con('0', ft_itoa(*i));
				*p = ft_join(*p, ft_itoa(*j), '.');
			}
		}
	}
}

int		ft_mzero2(char **p, long *num, int *k)
{
	if (ft_isdigit(*p) || (**p == '-' && ft_strchr((*p + 1), '.')))
	{
		ft_checknum1(*p, num, k);
		if (*num == 0 && *p[0] != '-' && (*p[0] == '.' || point != 0))
			return (1);
		if (*num != 0 || (*num == 0 && ft_strchr(*p, '.') &&
					ft_atoi(*p) > ft_atoi(ft_strchr(*p, '.'))) ||
				(*num == 0 && !ft_strchr(*p, '.')))
			ft_putnbr_fd(*num, 1);
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	if (**p == '-' && !ft_strchr((*p + 1), '.'))
	{
		ft_putnbr_fd(*num, 1);
		ft_checknum1(*p, num, k);
	}
	return (1);
}

int		ft_mzero(const char *ptr, long *valg, va_list *args, int *k)
{
	int		i;
	int		j;
	long	num;
	char	*p;

	i = *valg;
	j = va_arg(*args, int);
	num = va_arg(*args, int);
	if (*ptr == '-')
	{
		if (i > 0)
			i = -i;
		p = ft_join(ft_itoa(i), ft_itoa(j), '.');
	}
	ft_mzero1(&p, ptr, &i, &j);
	return (ft_mzero2(&p, &num, k));
}
