/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:33:20 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/13 16:41:14 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_zero(long *valg, const char *str, int *n, int *i, int *nb)
{
	if (*nb >= ft_strlen(str))
	{
		if (*valg < 0)
			(*i)++;
		*i += *nb - ft_strlen(str);
	}
	while ((*n)-- > (ft_strlen(str) + *i))
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
