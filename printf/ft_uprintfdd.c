/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uprintfdd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:45:01 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/18 21:12:51 by yhadari          ###   ########.fr       */
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
	str = ft_uitoa(*valg);
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

void	ft_upoint1(long long *valg, long long *nb, long long *n)
{
	if (*valg == 0)
	{
		if (*n != 0)
		{
			if (*nb == 0)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
		}
		point++;
	}
}

int		ft_upoint(const char *ptr, long long *valg, long long *n, long long **k)
{
	long long	nb;
	long long	i;
	const char	*str;

	i = 0;
	**k = 0;
	str = ft_uitoa(*valg);
	nb = ft_uatoi(*ptr == '.' ? ptr + 1 : ptr);
	if (*n > nb && ft_uzero(valg, n, &i, &nb))
		return (1);
	ft_upoint1(valg, &nb, n);
	while (nb-- > ft_ustrlen(str))
		ft_putchar_fd('0', 1);
	nb = ft_uatoi(ptr);
	if (-*n > nb)
	{
		if (nb >= ft_ustrlen(str))
			**k = -*n - nb - i;
		if (nb < ft_ustrlen(str) && -*n > ft_ustrlen(str))
			**k = -*n - ft_ustrlen(str);
	}
	return (1);
}

int		ft_uprintfdd(const char *ptr, va_list *args)
{
	long long	valg;
	long long	k;

	if (!ft_strchr(ptr, '*'))
		valg = va_arg(*args, unsigned int);
	if (ft_strchr(ptr, '*'))
		valg = va_arg(*args, int);
	k = 0;
	if (ft_strchr(ptr, '*') && *(ft_strchr(ptr, '*') + 1) == 'u' &&
			ft_uatoi(ptr) != 0 && ft_strchr(ptr, '.'))
		return (ft_unjma10(ptr, &valg, args));
	if ((*ptr == '-' || *ptr == '0') && ptr[1] == '*' && ptr[2] == '.' &&
			ptr[3] == '*')
		return (ft_umzero(ptr, &valg, args, &k));
	if (*ptr == '*' || ptr[1] == '*' || (ft_isdigit(ptr) && ptr[2] == '*' &&
				ft_strchr(ptr, '.')))
		return (ft_unjma(ptr, &valg, args));
	if (*ptr == 'u')
		ft_uputnbr_fd(valg, 1);
	return (ft_uprintfdd1(ptr, &valg, &k));
}
