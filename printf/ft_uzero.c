/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:44:41 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:51:08 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_uzero(long long *valg, long long *n, long long arr[2],
		const char *ptr)
{
	if (arr[1] >= ft_ustrlen(ft_uitoa(*valg, ptr)))
		arr[0] += arr[1] - ft_ustrlen(ft_uitoa(*valg, ptr));
	while ((*n)-- > (ft_ustrlen(ft_uitoa(*valg, ptr)) + arr[0]))
		ft_putchar_fd(' ', 1);
	if (*valg == 0)
	{
		if (*n == 0 && arr[1] == 0)
		{
			ft_putchar_fd(' ', 1);
			g_point++;
		}
	}
	while (arr[0]--)
		ft_putchar_fd('0', 1);
	return (1);
}
