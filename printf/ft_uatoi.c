/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:40:16 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/17 20:18:50 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_uatoi(const char *str)
{
	long long	result;
	int			i;
	int			j;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '0' || (str[i] >= 9 && str[i] <= 13) ||
			str[i] == '-')
		i++;
	if ((str[i - 1] == '-' && (i - 1) >= 0) || str[i] == '+' || str[i] == '.')
	{
		if (str[i - 1] != '-')
			i++;
		else
			j = -1;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * j);
}
