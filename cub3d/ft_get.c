/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:19:52 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/12 21:25:49 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error(char *str)
{
//	printf("%s\n", str);
	write(1, str, strlen(str));
	write(1, "\n", 1);
	exit(0);
}

static	void	ft_vu(char buf)
{
	if (buf != '0' && buf != '1' && buf != '2' && buf != 'N' && buf != 'S' &&
		buf != 'E' && buf != 'W' && buf != ' ')
		ft_error("map_error9");
}

static	void	ft_get2(char *buf)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	get.map = (char**)malloc(get.hori * sizeof(char*) + 1);
	while (*buf != '\0')
	{
		if ((*buf == '\n' && *(buf + 1) == '\n') ||
			(*buf == '\n' && *(buf + 1) == '\0'))
			break ;
		get.map[i] = (char*)malloc(get.colum + 1);
		j = 0;
		ft_checkline(buf, i, x);
		while (*buf != '\n')
		{
			ft_vu(*buf);
			if (*buf != '\n')
				get.map[i][j++] = *buf;
			buf++;
		}
		get.map[i][j] = '\0';
		i++;
		buf++;
	}
	get.map[i] = NULL;
	ft_revision();
}

static	void	ft_get1(char *save, char *buf)
{
	int x;

	x = 0;
	while (*save != '\n' || (*(save + 1) != '1' && *(save + 1) != ' '))
	{
		if (*save == '\n')
			save++;
		if (*save == 'R')
			ft_check_r(save);
		if (*save == 'F')
			ft_check_f(save);
		if (*save == 'C')
			ft_check_c(save);
		if (*save != '\n')
			save++;
	}
	save++;
	buf = save;
	ft_checkmap(save);
	ft_get2(buf);
}

int		ft_get(void)
{
	int		i;
	int		j;
	char	*save;
	char	*buf;

	buf = malloc(10000);
	if ((j = open("map.cub", O_RDWR)) == -1)
		ft_error("open_failed");
	if ((i = read(j, buf, 9999)) < 0)
		ft_error("read_failed");
	save = buf;
	save[i] = '\0';
	ft_get1(save, buf);
	return (0);
}
