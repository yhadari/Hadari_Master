/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:45:36 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 23:22:13 by yhadari          ###   ########.fr       */
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
				*p = ft_ujoin(ft_itoa(*i), ft_itoa(*j), '.',
						*(ptr + ft_strlen(ptr) - 1));
			else
			{
				*p = ft_ucon('0', ft_itoa(*i));
				*p = ft_ujoin(*p, ft_itoa(*j), '.',
						*(ptr + ft_strlen(ptr) - 1));
			}
		}
	}
}

void	ft_umzero3(char **p, long long *num, long long *k, const char *ptr)
{
	if (**p == '-' && !ft_strchr((*p + 1), '.'))
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*num, ptr));
		else
			ft_uputnbr_fd(*num, 1);
		if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
			*p = ft_uconx(*(ptr + ft_strlen(ptr) - 1), *p);
		ft_uchecknum1(*p, num, k);
	}
}

int		ft_umzero2(char **p, long long *num, long long *k, const char *ptr)
{
	if (ft_isdigit(*p) || (**p == '-' && ft_strchr((*p + 1), '.')))
	{
		if (ft_strchr(ptr, 'x') || ft_strchr(ptr, 'X'))
			*p = ft_uconx(*(ptr + ft_xstrlen(ptr)), *p);
		ft_uchecknum1(*p, num, k);
		if (*num == 0 && *p[0] != '-' && (*p[0] == '.' || point != 0))
			return (1);
		if (*num != 0 || (*num == 0 && ft_strchr(*p, '.') &&
					ft_uatoi(*p) > ft_uatoi(ft_strchr(*p, '.'))) ||
				(*num == 0 && !ft_strchr(*p, '.')))
		{
			if (!ft_strchr(ptr, 'u'))
				ft_putstr(ft_uitoa(*num, ptr));
			else
				ft_uputnbr_fd(*num, 1);
		}
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	ft_umzero3(p, num, k, ptr);
	return (1);
}

int		ft_umzero(const char *ptr, long long *valg, va_list *args, long long *k)
{
	long long	i;
	long long	j;
	long long	num;
	char		*p;

	i = *valg;
	j = va_arg(*args, int);
	num = va_arg(*args, unsigned int);
	if (*ptr == '-')
	{
		if (i > 0)
			i = -i;
		p = ft_ujoin(ft_itoa(i), ft_itoa(j), '.', *(ptr + ft_strlen(ptr) - 1));
	}
	ft_umzero1(&p, ptr, &i, &j);
	return (ft_umzero2(&p, &num, k, ptr));
}
