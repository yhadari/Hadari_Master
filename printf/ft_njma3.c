/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:26:44 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 21:06:23 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_n2(char *a, int *z, long *valg, int *j)
{
	if (*valg == 0)
	{
		*j = ft_atoi(a);
		*z = -*z - *j;
		while ((*j)-- > 0)
			ft_putchar_fd('0', 1);
		while ((*z)-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	*j = ft_atoi(a) - ft_strlen(ft_itoa(*valg));
	*z = -*z - ft_strlen(ft_itoa(*valg)) - *j;
	if (*valg < 0 && (*valg = -*valg))
	{
		(*j)++ ? (*z)-- : (*z)--;
		ft_putchar_fd('-', 1);
	}
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(*valg, 1);
	if (ft_atoi(a) < ft_strlen(ft_itoa(*valg)))
		*z = *z - 2;
	while ((*z)-- > 0)
		ft_putchar_fd(' ', 1);
	return (1);
}

int		ft_n1(char *a, int *z, long *valg, int *i)
{
	if (ft_atoi(a) < ft_strlen(ft_itoa(*valg)))
		*z = *z - 2;
	*i = *z - ft_atoi(a);
	if (*valg < 0)
		(*i)--;
	*z = *z - ft_strlen(ft_itoa(*valg)) - *i;
	if (*i != 0)
		while ((*i)-- > 0)
			ft_putchar_fd(' ', 1);
	if (*valg < 0)
	{
		ft_putchar_fd('-', 1);
		*valg = -*valg;
	}
	while ((*z)-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(*valg, 1);
	return (1);
}

int		ft_n3(char *a, long *valg, int *j)
{
	if (*valg < 0)
	{
		ft_putchar_fd('-', 1);
		*valg = -*valg;
	}
	*j = ft_atoi(a) - ft_strlen(ft_itoa(*valg));
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(*valg, 1);
	return (1);
}

int		ft_njma3(char *a, const char *ptr, int z, long *valg)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*ptr == '-' && z > 0)
		z = -z;
	if (z > 0)
	{
		if (*valg == 0)
		{
			j = z - ft_atoi(a);
			z = z - j;
			while (j-- > 0)
				ft_putchar_fd(' ', 1);
			while (z-- > 0)
				ft_putchar_fd('0', 1);
			return (1);
		}
		return (ft_n1(a, &z, valg, &i));
	}
	if (z < 0)
		return (ft_n2(a, &z, valg, &j));
	return (ft_n3(a, valg, &j));
}
