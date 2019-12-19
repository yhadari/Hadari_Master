/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:28:56 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/18 18:10:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		lenum(unsigned int n)
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

static	void	revnum(unsigned int *n, unsigned int *ncopy, int *i)
{
	*ncopy = *n;
	*i = lenum(*n);
}

static int				ft_write(unsigned int n, int fd)
{
	ft_putchar_fd((n % 10) + 48, fd);
	return (1);
}

void			ft_uputnbr_fd(unsigned int n, int fd)
{
	int		i;
	unsigned int	j;
	unsigned int	ncopy;

	j = 9;
	if (n == 0)
	{
		write(fd, "0", 1);
		count++;
		return ;
	}
	revnum(&n, &ncopy, &i);
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
