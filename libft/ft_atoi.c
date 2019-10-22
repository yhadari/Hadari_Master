/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:27 by yhadari           #+#    #+#             */
/*   Updated: 2019/10/21 14:43:01 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		longtest(unsigned long result, int j)
{
	if (j < 0 && (result - 1) > 4294967295)
		return (0);
	if (j > 0 && result > 4294967295)
		return (-1);
	return (result * j);
}

int				ft_atoi(const char *str)
{
	unsigned long	result;
	int				i;
	int				j;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (longtest(result, j));
}
