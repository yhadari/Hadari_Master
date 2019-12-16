/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_njma1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 23:11:12 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 18:29:34 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_njma2(const char *ptr, long *valg, int z)
{
	if (z < 0 && *valg != 0 && *ptr == '*')
	{
		ft_putnbr_fd(*valg, 1);
		z = -z;
		z = z - ft_strlen(ft_itoa(*valg));
		while (z-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	if (z < 0 && *ptr == '0')
	{
		ft_putnbr_fd(*valg, 1);
		z = -z;
		z = z - ft_strlen(ft_itoa(*valg));
		while (z-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	if (z == 0 && *ptr == '*')
	{
		if (*valg != 0)
			ft_putnbr_fd(*valg, 1);
		return (1);
	}
	return (0);
}

int		ft_njma1(char *a, const char *ptr, long *valg, int z)
{
	a = ft_strchr(ptr, '.');
	if ((*ptr == '*' || *ptr == '0' || *ptr == '-'))
	{
		if (a && (a[1] > 48 && a[1] < 58))
			return (ft_njma3(a, ptr, z, valg));
		if (*valg == 0 && z != 0 && ft_strchr(ptr, '.'))
		{
			if (z < 0)
				z = -z;
			while (z-- > 0)
				ft_putchar_fd(' ', 1);
			return (1);
		}
		if (z > 0 && *valg != 0 && *ptr == '*')
		{
			z = z - ft_strlen(ft_itoa(*valg));
			while (z-- > 0)
				ft_putchar_fd(' ', 1);
			ft_putnbr_fd(*valg, 1);
			return (1);
		}
		if (ft_njma2(ptr, valg, z))
			return (1);
	}
	return (0);
}
