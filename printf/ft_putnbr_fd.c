/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:42:51 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 04:47:06 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		checknum(long n, int *fd)
{
	if (n == 2147483648)
	{
		write(*fd, "2147483648", 10);
		g_count += 10;
		return (1);
	}
	if (n == -2147483648)
	{
		write(*fd, "-2147483648", 11);
		g_count += 11;
		return (1);
	}
	if (n == 0)
	{
		write(*fd, "0", 1);
		g_count++;
		return (1);
	}
	if (n == 2147483647)
	{
		write(*fd, "2147483647", 10);
		g_count += 10;
		return (1);
	}
	return (1);
}

static	int		ulenum(long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	revnum(long *n, long *ncopy, int *i)
{
	if (*n > 0)
		*ncopy = *n;
	*i = ulenum(*n);
	if (*n < 0)
	{
		*ncopy = -*n;
		*i = ulenum(-*n);
	}
}

static	int		ft_write(int n, int fd)
{
	ft_putchar_fd((n % 10) + 48, fd);
	return (1);
}

void			ft_putnbr_fd(long n, int fd)
{
	int		i;
	int		j;
	long	ncopy;

	j = 9;
	if ((n == 0 || n == -2147483648 || n == 2147483647 || n == 2147483648) &&
			checknum(n, &fd))
		return ;
	revnum(&n, &ncopy, &i);
	if (n < 0)
	{
		write(fd, "-", 1);
		g_count++;
		n = -n;
	}
	while (i-- > 0)
	{
		if (i == 0 && ft_write(n, fd))
			return ;
		while (n > j)
			n = n / 10;
		j = (j * 10) + 9;
		ft_putchar_fd((n % 10) + 48, fd);
		n = ncopy;
	}
}
