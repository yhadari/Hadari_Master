/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:45:30 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/13 19:49:21 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static	void	ft_revision1(int *i, int *j)
{
	if (get.map[*i][*j] == 'N' || get.map[*i][*j] == 'W' ||
		get.map[*i][*j] == 'E' || get.map[*i][*j] == 'S')
	{
		line.x = *j * tile + (tile/2);
		line.y = *i * tile + (tile/2);
	}
	if (get.map[(*i) + 1][*j] == ' ' || get.map[(*i) + 1][*j] == '\n' ||
			get.map[(*i) + 1][*j] == '\0')
		ft_error("map_error0");
	if (get.map[(*i) - 1][*j] == ' ' || get.map[(*i) - 1][*j] == '\n' ||
			get.map[(*i) - 1][*j] == '\0')
		ft_error("map_error0");
	if (get.map[*i][(*j) + 1] == ' ' || get.map[*i][(*j) + 1] == '\n' ||
			get.map[*i][(*j) + 1] == '\0')
		ft_error("map_error0");
	if (get.map[*i][(*j) - 1] == ' ' || get.map[*i][(*j) - 1] == '\n' ||
			get.map[*i][(*j) - 1] == '\0')
		ft_error("map_error0");
}

void    ft_revision()
{
	int i;
	int j;
	int save;

	i = 0;
	save = 0;
	while (i < get.hori)
	{
		j = 0;
		while (get.map[i][j] != '\0')
		{
			if (get.map[i][j] == 'N' || get.map[i][j] == 'S' ||
					get.map[i][j] == 'W' || get.map[i][j] == 'E')
			{
				if (get.map[i][j] == 'N')
                                        get.der = 1;
				if (get.map[i][j] == 'S')
                                        get.der = 2;
				if (get.map[i][j] == 'W')
                                        get.der = 3;
				if (get.map[i][j] == 'E')
                                        get.der = 4;
				save++;
			}
			if ((get.map[i][j] == '0' || get.map[i][j] == 'N' ||
				get.map[i][j] == 'W' || get.map[i][j] == 'E' ||
				get.map[i][j] == 'S' || get.map[i][j] == '2')
				&& i > 0 && i < (get.hori - 1))
				ft_revision1(&i, &j);
			j++;
		}
		i++;
	}
	if (save != 1)
		ft_error("map_error6");
}
