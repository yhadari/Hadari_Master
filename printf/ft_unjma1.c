/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unjma1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:07:00 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/17 19:55:57 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_unjma2(const char *ptr, long long *valg, long long z)
{
	if (z < 0 && *valg != 0 && *ptr == '*')
	{
		ft_uputnbr_fd(*valg, 1);
		z = -z;
		z = z - ft_ustrlen(ft_uitoa(*valg));
		while (z-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	if (z < 0 && *ptr == '0')
	{
		ft_uputnbr_fd(*valg, 1);
		z = -z;
		z = z - ft_ustrlen(ft_uitoa(*valg));
		while (z-- > 0)
			ft_putchar_fd(' ', 1);
		return (1);
	}
	if (z == 0 && *ptr == '*')
	{
		if (*valg != 0)
			ft_uputnbr_fd(*valg, 1);
		return (1);
	}
	return (0);
}

int		ft_unjma1(char *a, const char *ptr, long long *valg, long long z)
{
	a = ft_strchr(ptr, '.');
	if ((*ptr == '*' || *ptr == '0' || *ptr == '-'))
	{
		if (a && (a[1] > 48 && a[1] < 58))
			return (ft_unjma3(a, ptr, z, valg));
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
			z = z - ft_ustrlen(ft_uitoa(*valg));
			while (z-- > 0)
				ft_putchar_fd(' ', 1);
			ft_uputnbr_fd(*valg, 1);
			return (1);
		}
		if (ft_unjma2(ptr, valg, z))
			return (1);
	}
	return (0);
}
