/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:44:41 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/17 19:58:34 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_uzero(long long *valg, long long *n, long long *i, long long *nb)
{
	if (*nb >= ft_ustrlen(ft_uitoa(*valg)))
		*i += *nb - ft_ustrlen(ft_uitoa(*valg));
	while ((*n)-- > (ft_ustrlen(ft_uitoa(*valg)) + *i))
		ft_putchar_fd(' ', 1);
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
