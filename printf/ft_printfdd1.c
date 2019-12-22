/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdd1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:02:45 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:50:38 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printfdd1(const char *ptr, long *valg, int *k)
{
	if (ft_isdigit(ptr) || (*ptr == '.' && ptr[1] != '*') || (*ptr == '-' &&
				ft_strchr((ptr + 1), '.')))
	{
		ft_checknum1(ptr, valg, k);
		if (*valg == 0 && ptr[0] != '-' && (ptr[0] == '.' || g_point != 0))
			return (1);
		if (*valg != 0 || (*valg == 0 && ft_strchr(ptr, '.') &&
					ft_atoi(ptr) > ft_atoi(ft_strchr(ptr, '.'))) ||
				(*valg == 0 && !ft_strchr(ptr, '.')))
			ft_putnbr_fd(*valg, 1);
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	if (*ptr == '-' && !ft_strchr((ptr + 1), '.'))
	{
		ft_putnbr_fd(*valg, 1);
		ft_checknum1(ptr, valg, k);
	}
	return (1);
}
