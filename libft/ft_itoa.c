/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:44:58 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/26 04:09:48 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		lenum(int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n < 0)
	{
		n = n * -1;
		j++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	i = i + j;
	return (i);
}

static	char	*writeptr(int n, int *neg)
{
	char	*ptr;
	int		i;
	int		modulo;

	modulo = 0;
	i = lenum(n);
	if (n < 0)
	{
		*neg = 1;
		n = n * -1;
		ptr = malloc((lenum(n) + 2) * sizeof(char));
	}
	else
		ptr = malloc((lenum(n) + 1) * sizeof(char));
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

char			*ft_itoa(int n)
{
	char	*ptr;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = writeptr(n, &i);
	if (!ptr)
		return (NULL);
	if (i == 1)
		ptr[0] = '-';
	while (ptr[i] >= '0' && ptr[i] <= '9')
		i++;
	ptr[i] = '\0';
	return (ptr);
}
