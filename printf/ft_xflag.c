/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 03:45:52 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/21 01:06:24 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strev(char *ptr)
{
	int		i;
	int		a;
	char	*p;

	i = 0;
	a = ft_strlen(ptr);
	p = malloc(a + 1);
	while (a > 0)
		p[i++] = ptr[--a];
	p[i] = '\0';
	return (p);
}

char	*ft_xflag(unsigned int n, int k)
{
	unsigned int	num;
	unsigned int	i;
	char			*ptr;
	char			*hx;

	if (k == 0)
		hx = "0123456789abcdef";
	if (k == 1)
		hx = "0123456789ABCDEF";
	i = 0;
	ptr = malloc(9);
	if (n == 0)
		ptr[i++] = hx[0];
	while (n != 0)
	{
		num = n % 16;
		ptr[i++] = hx[num];
		n = n / 16;
	}
	ptr[i] = '\0';
	return (ft_strev(ptr));
}
