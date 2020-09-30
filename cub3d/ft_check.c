/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:20:13 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/06 21:10:21 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_check_r(char *save)
{
	get.win_colum = atoi(save + 1);
	save++;
	while (*save == ' ')
		save++;
	while (*save != ' ')
		save++;
	get.win_hori = atoi(save);
	if (get.win_hori <= 0 || get.win_colum <= 0)
		ft_error("resolution error");
	if (get.win_hori > 900 || get.win_colum > 1600)
	{
		get.win_hori = 900;
		get.win_colum = 1600;
	}
}

void	ft_check_f(char *save)
{
	int x;
	int y;

	x = 0;
	y = 0;
	get.f = malloc(3 * sizeof(int));
	save++;
	while (*save == ' ')
		save++;
	while (*save != '\n')
	{
		get.f[x++] = atoi(save);
		if (get.f[x - 1] > 255 || get.f[x - 1] < 0)
			ft_error("color_error");
		while (*save != ',' && *save != '\n')
			save++;
		if (*save == ',')
			y++;
		if (*save != '\n')
			save++;
	}
	if (y != 2)
		ft_error("color_error");
}

void	ft_check_c(char *save)
{
	int x;
	int y;

	x = 0;
	y = 0;
	get.c = malloc(3 * sizeof(int));
	save++;
	while (*save == ' ')
		save++;
	while (*save != '\n')
	{
		get.c[x++] = atoi(save);
		if (get.c[x - 1] > 255 || get.c[x - 1] < 0)
			ft_error("color_error");
		while (*save != ',' && *save != '\n')
			save++;
		if (*save == ',')
			y++;
		if (*save != '\n')
			save++;
	}
	if (y != 2)
		ft_error("color_error");
}
