/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:47:49 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/09 17:08:54 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	ft_checkline1(char *buf, int i, int x)
{
	while (*buf != '\n')
	{
		while (i > x)
		{
			if (*buf != '1')
				ft_error("map_error3");
			i--;
			buf++;
		}
		buf++;
	}
}

void    ft_checkline(char *buf, int line, int x)
{
	int i;

	i = x;
	x = 0;
	while (*buf == ' ')
	{
		buf++;
		x++;
	}
	if (line == 0 || line == (get.hori - 1))
	{
		while (*buf != '\n')
		{
			if (*buf != '1' && *buf != ' ')
				ft_error("map_error1");
			buf++;
		}
	}
	else
		ft_checkline1(buf, i, x);
}
