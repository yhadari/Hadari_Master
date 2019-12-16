/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:29:25 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 21:22:49 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_checknum1(const char *ptr, long *valg, int *k)
{
	int			i;
	int			nb;
	const char	*str;

	i = 0;
	nb = ft_atoi(ptr);
	str = ft_itoa(*valg);
	while (ptr[i] != 'd' && ptr[i++] != '\0')
		if (ptr[i] == '.' && ft_point(&ptr[i], valg, &nb, &k))
			return ;
	i = 0;
	if ((ptr[i] == '.' && ft_atoi(ptr + 1) != 0) ||
			(ptr[i] == '-' && ptr[i + 1] == '.'))
		ft_point(&ptr[1], valg, &nb, &k);
	if ((ptr[i] > 47 && ptr[i] < 58) || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			nb = -nb;
		if (ptr[i] == '0' && nb != 0)
			ft_pointzero(&ptr[i], valg, str, &nb);
		while (nb-- > ft_strlen(str))
			ft_putchar_fd(' ', 1);
	}
	*k = 0;
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

void	ft_point1(long *valg, int *nb, int *i, int *n)
{
	if (*valg < 0)
	{
		*valg = -*valg;
		ft_putchar_fd('-', 1);
		(*nb)++;
		*i = 1;
	}
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

int		ft_point(const char *ptr, long *valg, int *n, int **k)
{
	int			nb;
	int			i;
	const char	*str;

	i = 0;
	**k = 0;
	str = ft_itoa(*valg);
	nb = ft_atoi(*ptr == '.' ? ptr + 1 : ptr);
	if (*n > nb && ft_zero(valg, n, &i, &nb))
		return (1);
	ft_point1(valg, &nb, &i, n);
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

int		ft_printfdd(const char *ptr, va_list *args)
{
	long	valg;
	int		k;

	valg = va_arg(*args, int);
	k = 0;
	if (ft_strchr(ptr, '*') && *(ft_strchr(ptr, '*') + 1) == 'd' &&
			ft_atoi(ptr) != 0 && ft_strchr(ptr, '.'))
		return (ft_njma10(ptr, &valg, args));
	if ((*ptr == '-' || *ptr == '0') && ptr[1] == '*' && ptr[2] == '.' &&
			ptr[3] == '*')
		return (ft_mzero(ptr, &valg, args, &k));
	if (*ptr == '*' || ptr[1] == '*' || (ft_isdigit(ptr) && ptr[2] == '*' &&
				ft_strchr(ptr, '.')))
		return (ft_njma(ptr, &valg, args));
	if (*ptr == 'd')
		ft_putnbr_fd(valg, 1);
	return (ft_printfdd1(ptr, &valg, &k));
}
