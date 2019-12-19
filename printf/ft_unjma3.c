/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unjma3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:41:18 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/19 02:34:39 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_un2(char *a, long long *z, long long *valg, long long *j)
{
	*j = ft_uatoi(a) - ft_ustrlen(ft_uitoa(*valg));
	if (*j > 0)
		*z = -*z - ft_ustrlen(ft_uitoa(*valg)) - *j;
	else
		*z = -*z - ft_ustrlen(ft_uitoa(*valg));
	if (*valg == 0 && *a == '*')
		(*z)--;
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	ft_uputnbr_fd(*valg, 1);
	while ((*z)-- > 0)
		ft_putchar_fd(' ', 1);
	return (1);
}

int		ft_un1(char *a, long long *z, long long *valg, long long *i)
{
	*i = ft_uatoi(a) - ft_ustrlen(ft_uitoa(*valg));
	if (*i > 0)
		*z = *z - ft_ustrlen(ft_uitoa(*valg)) - *i;
	else
		*z = *z - ft_ustrlen(ft_uitoa(*valg));
	while ((*z)-- > 0)
		ft_putchar_fd(' ', 1);
	while ((*i)-- > 0)
		ft_putchar_fd('0', 1);
	ft_uputnbr_fd(*valg, 1);
	return (1);
}

int		ft_un3(char *a, long long *valg, long long *j)
{
	*j = ft_uatoi(a) - ft_ustrlen(ft_uitoa(*valg));
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	ft_uputnbr_fd(*valg, 1);
	return (1);
}

int		ft_unjma3(char *a, const char *ptr, long long z, long long *valg)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (*ptr == '-' && z > 0)
		z = -z;
	if (z > 0)
	{
		if (*valg == 0)
		{
			j = z - ft_uatoi(a);
			z = z - j;
			while (j-- > 0)
				ft_putchar_fd(' ', 1);
			while (z-- > 0)
				ft_putchar_fd('0', 1);
			return (1);
		}
		return (ft_un1(a, &z, valg, &i));
	}
	if (z < 0)
		return (ft_un2(a, &z, valg, &j));
	return (ft_un3(a, valg, &j));
}
