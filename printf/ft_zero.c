/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:33:20 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 21:23:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_zero(long *valg, int *n, int *i, int *nb)
{
	if (*nb >= ft_strlen(ft_itoa(*valg)))
	{
		if (*valg < 0)
			(*i)++;
		*i += *nb - ft_strlen(ft_itoa(*valg));
	}
	while ((*n)-- > (ft_strlen(ft_itoa(*valg)) + *i))
		ft_putchar_fd(' ', 1);
	if (*valg < 0)
	{
		*valg = -*valg;
		ft_putchar_fd('-', 1);
	}
	if (*valg == 0)
	{
		if (*n == 0 && *nb == 0)
		{
			ft_putchar_fd(' ', 1);
			point++;
		}
	}
	while ((*i)--)
		ft_putchar_fd('0', 1);
	return (1);
}
