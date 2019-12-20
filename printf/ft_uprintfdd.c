/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintfdd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:45:01 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/19 22:23:59 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_uchecknum1(const char *ptr, long long *valg, long long *k)
{
	int			i;
	long long	nb;
	const char	*str;

	i = 0;
	nb = ft_uatoi(ptr);
	str = ft_uitoa(*valg, ptr);
	while (ptr[i] != 'u' && ptr[i++] != '\0')
		if (ptr[i] == '.' && ft_upoint(&ptr[i], valg, &nb, &k))
			return ;
	i = 0;
	if ((ptr[i] == '.' && ft_uatoi(ptr + 1) != 0) ||
			(ptr[i] == '-' && ptr[i + 1] == '.'))
		ft_upoint(&ptr[1], valg, &nb, &k);
	if ((ptr[i] > 47 && ptr[i] < 58) || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			nb = -nb;
		if (ptr[i] == '0' && nb != 0)
			ft_upointzero(str, &nb);
		while (nb-- > ft_strlen(str))
			ft_putchar_fd(' ', 1);
	}
	*k = 0;
}

int		ft_upointzero(const char *str, long long *nb)
{
	while ((*nb)-- > ft_ustrlen(str))
		ft_putchar_fd('0', 1);
	return (1);
}

void	ft_upoint1(long long *valg, long long nb, long long *n)
{
	if (*valg == 0)
	{
		if (*n != 0)
		{
			if (nb == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
		}
		point++;
	}
}

int		ft_upoint(const char *ptr, long long *valg, long long *n, long long **k)
{
	long long	arr[2];
	const char	*str;

	arr[0] = 0;
	**k = 0;
	str = ft_uitoa(*valg, ptr);
	arr[1] = ft_uatoi(*ptr == '.' ? ptr + 1 : ptr);
	if (*n > arr[1] && ft_uzero(valg, n, arr, ptr))
		return (1);
	ft_upoint1(valg, arr[1], n);
	while (arr[1]-- > ft_ustrlen(str))
		ft_putchar_fd('0', 1);
	arr[1] = ft_uatoi(ptr);
	if (-*n > arr[1])
	{
		if (arr[1] >= ft_ustrlen(str))
			**k = -*n - arr[1] - arr[0];
		if (arr[1] < ft_ustrlen(str) && -*n > ft_ustrlen(str))
			**k = -*n - ft_ustrlen(str);
	}
	return (1);
}

int		ft_uprintfdd(const char *ptr, va_list *args)
{
	long long	valg;
	long long	k;
	char		*a;

	a = "xX";
	if (!ft_strchr(ptr, '*'))
		valg = va_arg(*args, unsigned int);
	if (ft_strchr(ptr, '*'))
		valg = va_arg(*args, int);
	k = 0;
	if (ft_strchr(ptr, '*') && (*(ft_strchr(ptr, '*') + 1) == 'u' ||
		ft_strchr(a, *(ft_strchr(ptr, '*') + 1))) &&
		ft_uatoi(ptr) != 0 && ft_strchr(ptr, '.'))
		return (ft_unjma10(ptr, &valg, args));
	if ((*ptr == '-' || *ptr == '0') && ptr[1] == '*' && ptr[2] == '.' &&
			ptr[3] == '*')
		return (ft_umzero(ptr, &valg, args, &k));
	if (*ptr == '*' || ptr[1] == '*' || (ft_isdigit(ptr) && ptr[2] == '*' &&
				ft_strchr(ptr, '.')))
		return (ft_unjma(ptr, &valg, args));
	if (*ptr == 'u' || *ptr == 'x' || *ptr == 'X')
	{
		if (!ft_strchr(ptr, 'u'))
			ft_putstr(ft_uitoa(valg, ptr));
		else
			ft_uputnbr_fd(valg, 1);
	}
	return (ft_uprintfdd1(ptr, &valg, &k));
}
