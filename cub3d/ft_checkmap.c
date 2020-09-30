/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:20:00 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/06 15:58:15 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_checkmap(char *save)
{
	int y;
	int len;

	y = 0;
	len = 1;
	while (*save != '\0')
	{
		while (*save == ' ')
		{
			save++;
			len++;
		}
		if (*save == '\n')
		{
			if (len > get.colum)
				get.colum = len;
			len = 0;
			y++;
			if (*(save + 1) == '\n' || *(save + 1) == '\0')
				break;
		}
		save++;
		len++;
	}
	get.hori = y;
}
