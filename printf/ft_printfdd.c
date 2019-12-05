/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:29:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/05 22:01:20 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checknum1(const char *ptr, long *valg, int *k)
{
	int         i;
	int			nb;
	const char	*str;

	i = 0;
	nb = ft_atoi(ptr);
	str = ft_itoa(*valg);
	while (ptr[i] != 'd' && ptr[i++] != '\0')
		if (ptr[i] == '.' && ft_point(&ptr[i], valg, str, &nb, &k))
			return (0);
	i = 0;
	if ((ptr[i] == '.' && ft_atoi(ptr + 1) != 0) ||
			(ptr[i] == '-' && ptr[i + 1] == '.'))
		ft_point(&ptr[1], valg, str, &nb, &k);
	if ((ptr[i] > 47 && ptr[i] < 58) || ptr[i] == '-')
	{
		if (*valg == 0 && ptr[2] == '.')
			zero++;
		if (ptr[i] == '-')
			nb = -nb;
		if (ptr[i] == '0' && nb != 0)
			ft_pointzero(&ptr[i], valg, str, &nb);
		while (nb-- > ft_strlen(str))
			ft_putchar_fd(' ', 1);
		return (0);
	}
	if (ptr[i] == '.' && ft_atoi(ptr) == 0 && *valg == 0)
		zero++;
	return (0);
}

int		ft_pointzero(const char *ptr, long *valg, const char *str, int *nb)
{
	int i;

	i = 0;
	if (*valg < 0)
	{
		while (ptr[i] == '0')
		{
			i++;
			if (ptr[i] == '.')
				(*nb)++;
		}
		*valg = -*valg;
		ft_putchar_fd('-', 1);
	}
	while ((*nb)-- > ft_strlen(str))
		ft_putchar_fd('0', 1);
	return (1);
}

int		ft_point(const char *ptr, long *valg, const char *str, int *n, int **k)
{
	int nb;
	int i;

	if (*ptr == '.' && ft_atoi(ptr) == 0 && **k == 1)
	{
		if (*valg == 0)
			zero++;
	}
	i = 0;
	**k = 0;
	nb = ft_atoi(*ptr == '.' ? ptr + 1 : ptr);
	if (*n > nb && ft_zero(valg, str, n, &i, &nb))
		return (1);
	if (*valg < 0)
	{
		*valg = -*valg;
		ft_putchar_fd('-', 1);
		nb++;
		i = 1;
	}
	while (nb-- > ft_strlen(str))
		ft_putchar_fd('0', 1);
	nb = ft_atoi(ptr);
	if (-*n > nb)
	{
		if (nb >= ft_strlen(str))
			**k = -*n - nb - i;
		if (nb < ft_strlen(str) && -*n > ft_strlen(str))
			**k = -*n - ft_strlen(str);
	}
	return (1);
}

int		checkpoint(const char *p)
{
	if (!ft_strchr(p, '.'))
		return (0);
	return (1);
}

int 	ft_printfdd(const char *ptr, va_list *args)
{
	long valg;
	int k;

	valg = va_arg(*args, int);
	k = 0;
	if (*ptr == '*' || ptr[1] == '*')
		return (ft_njma(ptr, &valg, args));
	if (*ptr == 'd')
		ft_putnbr_fd(valg, 1);
	if (ft_isdigit(ptr) || (*ptr == '.' && ptr[1] != '*') || (*ptr == '-' && checkpoint(ptr + 1)))
	{
		ft_checknum1(ptr, &valg, &k);
		if (zero != 0)
			return (1);
		ft_putnbr_fd(valg, 1);
		if (k != 0)
			while (k--)
				ft_putchar_fd(' ', 1);
	}
	if (*ptr == '-' && !checkpoint(ptr + 1))
	{
		ft_putnbr_fd(valg, 1);
		ft_checknum1(ptr, &valg, &k);
	}
	return (1);
}
