/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:57:22 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/22 00:20:03 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ulenum(unsigned int n)
{
	long long i;
	long long j;

	i = 0;
	j = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	i = i + j;
	return (i);
}

static	char	*writeptr(unsigned int n)
{
	char		*ptr;
	long long	i;
	long long	modulo;

	modulo = 0;
	i = ulenum(n);
	ptr = malloc((ulenum(n) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (n > 0)
	{
		modulo = n % 10;
		n = n / 10;
		ptr[i - 1] = modulo + 48;
		i--;
	}
	return (ptr);
}

char			*ft_uitoa(unsigned int n, const char *a)
{
	char		*ptr;
	long long	i;

	if (ft_strchr(a, 'x') || ft_strchr(a, 'X'))
		return (ft_xflag(n, (ft_strchr(a, 'x')) == NULL));
	i = 0;
	if (n == 0)
		return (ft_ustrdup("0"));
	ptr = writeptr(n);
	if (!ptr)
		return (NULL);
	if (i == 1)
		ptr[0] = '-';
	while (ptr[i] >= '0' && ptr[i] <= '9')
		i++;
	ptr[i] = '\0';
	return (ptr);
}
