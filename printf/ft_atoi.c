/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:49:27 by yhadari           #+#    #+#             */
/*   Updated: 2019/12/16 21:24:14 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_atoi(const char *str)
{
	int result;
	int	i;
	int	j;

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
