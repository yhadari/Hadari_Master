/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:45:36 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/17 23:14:24 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ucon(char a, char *ptr)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = ft_ustrlen(ptr) + 1;
	p = malloc(i + 1);
	p[j++] = a;
	while (*ptr)
		p[j++] = *ptr++;
	p[j] = '\0';
	return (p);
}

char	*ft_ujoin(char *a, char *b, char c)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	i = (ft_ustrlen(a) + ft_ustrlen(b) + 1);
	if (*b == '-')
		i = (ft_ustrlen(a) + 1);
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

void	ft_umzero1(char **p, const char *ptr, long long *i, long long *j)
{
	if (*ptr == '0')
	{
		if (*j < 0)
		{
			if (*i <= 0)
				*p = ft_itoa(*i);
			else
				*p = ft_ucon('0', ft_itoa(*i));
		}
		if (*j >= 0)
		{
			if (*i <= 0)
				*p = ft_ujoin(ft_itoa(*i), ft_itoa(*j), '.');
			else
			{
				*p = ft_ucon('0', ft_itoa(*i));
				*p = ft_ujoin(*p, ft_itoa(*j), '.');
			}
		}
	}
}

int		ft_umzero2(char **p, long long *num, long long *k)
{
	if (ft_isdigit(*p) || (**p == '-' && ft_strchr((*p + 1), '.')))
	{
		ft_uchecknum1(*p, num, k);
		if (*num == 0 && *p[0] != '-' && (*p[0] == '.' || point != 0))
			return (1);
		if (*num != 0 || (*num == 0 && ft_strchr(*p, '.') &&
					ft_uatoi(*p) > ft_uatoi(ft_strchr(*p, '.'))) ||
				(*num == 0 && !ft_strchr(*p, '.')))
			ft_uputnbr_fd(*num, 1);
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	if (**p == '-' && !ft_strchr((*p + 1), '.'))
	{
		ft_uputnbr_fd(*num, 1);
		ft_uchecknum1(*p, num, k);
	}
	return (1);
}

int		ft_umzero(const char *ptr, long long *valg, va_list *args, long long *k)
{
	long long		i;
	long long		j;
	long long	num;
	char	*p;

	i = *valg;
	j = va_arg(*args, int);
	num = va_arg(*args, unsigned int);
	if (*ptr == '-')
	{
		if (i > 0)
			i = -i;
		p = ft_ujoin(ft_itoa(i), ft_itoa(j), '.');
	}
	ft_umzero1(&p, ptr, &i, &j);
	return (ft_umzero2(&p, &num, k));
}