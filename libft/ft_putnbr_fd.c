/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:42:51 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/23 02:50:45 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	checknum(int n, int *fd)
{
	if (n == -2147483648)
	{
		write(*fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(*fd, "0", 1);
		return ;
	}
	if (n == 2147483647)
	{
		write(*fd, "2147483647", 10);
		return ;
	}
}

static	int		lenum(int n)
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

void			ft_putnbr_fd(int n, int fd)
{
	int i;
	int j;
	int ncopy;

	j = 9;
	ncopy = n;
	i = lenum(n);
	if (n == 0 || n == -2147483648 || n == 2147483647)
	{
		checknum(n, &fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (i > 0)
	{
		while (n > j)
			n = n / 10;
		j = (j * 10) + 9;
		i--;
		ft_putchar_fd((n % 10) + 48, fd);
		n = ncopy;
	}
}
