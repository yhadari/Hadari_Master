/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unjma3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:41:18 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/20 23:39:59 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_un2(const char *arr[2], long long *z, long long *valg, long long *j)
{
	*j = ft_uatoi(arr[0]) - ft_ustrlen(ft_uitoa(*valg, arr[1]));
	if (*j > 0)
		*z = -*z - ft_ustrlen(ft_uitoa(*valg, arr[1])) - *j;
	else
		*z = -*z - ft_ustrlen(ft_uitoa(*valg, arr[1]));
	if (*valg == 0 && *arr[0] == '*')
		(*z)--;
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	if (!ft_strchr(arr[1], 'u'))
		ft_putstr(ft_uitoa(*valg, arr[1]));
	else
		ft_uputnbr_fd(*valg, 1);
	while ((*z)-- > 0)
		ft_putchar_fd(' ', 1);
	return (1);
}

int		ft_un1(const char *arr[2], long long *z, long long *valg, long long *i)
{
	*i = ft_uatoi(arr[0]) - ft_ustrlen(ft_uitoa(*valg, arr[1]));
	if (*i > 0)
		*z = *z - ft_ustrlen(ft_uitoa(*valg, arr[1])) - *i;
	else
		*z = *z - ft_ustrlen(ft_uitoa(*valg, arr[1]));
	while ((*z)-- > 0)
		ft_putchar_fd(' ', 1);
	while ((*i)-- > 0)
		ft_putchar_fd('0', 1);
	if (!ft_strchr(arr[1], 'u'))
		ft_putstr(ft_uitoa(*valg, arr[1]));
	else
		ft_uputnbr_fd(*valg, 1);
	return (1);
}

int		ft_un3(const char *arr[2], long long *valg, long long *j)
{
	*j = ft_uatoi(arr[0]) - ft_ustrlen(ft_uitoa(*valg, arr[1]));
	while ((*j)-- > 0)
		ft_putchar_fd('0', 1);
	if (!ft_strchr(arr[1], 'u'))
		ft_putstr(ft_uitoa(*valg, arr[1]));
	else
		ft_uputnbr_fd(*valg, 1);
	return (1);
}

int		ft_un0(const char *arr[2], long long *j, long long *z)
{
	*j = *z - ft_uatoi(arr[0]);
	*z = *z - *j;
	while ((*j)-- > 0)
		ft_putchar_fd(' ', 1);
	while ((*z)-- > 0)
		ft_putchar_fd('0', 1);
	return (1);
}

int		ft_unjma3(char *a, const char *ptr, long long z, long long *valg)
{
	long long	i;
	long long	j;
	const char	*arr[2];

	i = 0;
	j = 0;
	arr[0] = a;
	arr[1] = ptr;
	if (*ptr == '-' && z > 0)
		z = -z;
	if (z > 0)
	{
		if (*valg == 0)
			return (ft_un0(arr, &j, &z));
		return (ft_un1(arr, &z, valg, &i));
	}
	if (z < 0)
		return (ft_un2(arr, &z, valg, &j));
	return (ft_un3(arr, valg, &j));
}
