/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintfdd1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:51:54 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/19 17:56:08 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_uprintfdd1(const char *ptr, long long *valg, long long *k)
{
	if (ft_isdigit(ptr) || (*ptr == '.' && ptr[1] != '*') || (*ptr == '-' &&
				ft_strchr((ptr + 1), '.')))
	{
		ft_uchecknum1(ptr, valg, k);
		if (*valg == 0 && ptr[0] != '-' && (ptr[0] == '.' || point != 0))
			return (1);
		if (*valg != 0 || (*valg == 0 && ft_strchr(ptr, '.') &&
					ft_uatoi(ptr) > ft_uatoi(ft_strchr(ptr, '.'))) ||
				(*valg == 0 && !ft_strchr(ptr, '.')))
		{
			if (!ft_strchr(ptr, 'u'))
				ft_putstr(ft_uitoa(*valg, ptr));
			else
				ft_uputnbr_fd(*valg, 1);
		}
		if (*k != 0)
			while ((*k)--)
				ft_putchar_fd(' ', 1);
	}
	if (*ptr == '-' && !ft_strchr((ptr + 1), '.'))
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(*valg, ptr));
		else
			ft_uputnbr_fd(*valg, 1);
		ft_uchecknum1(ptr, valg, k);
	}
	return (1);
}
