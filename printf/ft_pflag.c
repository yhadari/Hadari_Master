/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:55:15 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/21 17:19:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_pflag(const char *ptr, va_list *args)
{
	size_t	valg;
	int		arr[2];
	char	*p;

	arr[0] = 0;
	arr[1] = 0;
	valg = va_arg(*args, size_t);
	p = ft_xflag(valg, 2);
	if (*ptr == '*' || ft_cstrchr(ptr, '*'))
	{
		arr[0] = (int)valg;
		valg = va_arg(*args, size_t);
		p = ft_xflag(valg, 2);
		if (valg == 0 && ft_cstrchr(ptr, '.'))
			arr[1]++;
	}
	if (*ptr == 'p' || *ptr == '.')
		return (ft_pflag1(ptr, p, valg));
	if (ft_cisdigit(ptr) || arr[0] > 0)
		return (ft_pflag2(ptr, p, valg, arr));
	if (*ptr == '-' || arr[0] <= 0)
		return (ft_pflag3(ptr, p, valg, arr));
	return (1);
}

int		ft_pflag1(const char *ptr, char *p, size_t valg)
{
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (valg != 0 || *ptr != '.')
		ft_putstr(p);
	return (1);
}

int		ft_pflag2(const char *ptr, char *p, size_t valg, int arr[2])
{
	if (valg == 0 && arr[0] == 0 && ft_cstrchr(ptr, '.'))
		arr[1]++;
	if (arr[0] > 0)
		arr[1] += arr[0] - ft_strlen(p) - 2;
	else
		arr[1] += ft_atoi(ptr) - ft_strlen(p) - 2;
	while (arr[1]-- > 0)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (valg != 0 || !ft_cstrchr(ptr, '.'))
		ft_putstr(p);
	return (1);
}

int		ft_pflag3(const char *ptr, char *p, size_t valg, int arr[2])
{
	if (valg == 0 && arr[0] == 0 && ft_cstrchr(ptr, '.'))
		arr[1]++;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	if (arr[0] < 0)
		arr[1] += -arr[0] - ft_strlen(p) - 2;
	else if (arr[0] > 0)
	{
		arr[0] = -arr[0];
		arr[1] += -arr[0] - ft_strlen(p) - 2;
	}
	else
		arr[1] += -ft_atoi(ptr) - ft_strlen(p) - 2;
	if (valg != 0 || !ft_cstrchr(ptr, '.'))
		ft_putstr(p);
	while (arr[1]-- > 0)
		ft_putchar_fd(' ', 1);
	return (1);
}
