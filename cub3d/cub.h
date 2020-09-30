/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:09:23 by yhadari           #+#    #+#             */
/*   Updated: 2020/03/13 19:43:46 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define tile 40


typedef	struct		s_get
{
	int		win_colum;
	int		win_hori;
	int		colum;
	int		hori;
	int		der;
	int		*f;
	int		*c;
	char		**map;
}			t_get;

typedef struct		s_draw
{
	int		xx;
	int		yy;
	int		savex;
	int		savey;
}			t_draw;

typedef	struct		s_player
{
	float		movespeed;
	float		mx;
	float		my;
	int		walkder;
	int		turnder;
}			t_player;

typedef struct		s_line
{
	float		x;
	float		y;
}			t_line;

typedef struct		s_p
{
	int		index;
	float		x1;
	float		y1;
	float		angle;
	float		angle1;
	float		rotationspeed;
}			t_p;

void *mlx_ptr;
void *win_ptr;
void *image_ptr;

t_get get;
t_draw draw;
t_player player;
t_line line;
t_p p;

void	ft_error(char *str);
void	ft_check_r(char *save);
void	ft_check_f(char *save);
void	ft_check_c(char *save);
void	ft_checkmap(char *save);
void	ft_checkline(char *buf, int line, int x);
void	ft_revision();
int	ft_get(void);
void    ft_draw1(int xx, int yy, int tile_size);
int	ft_key();
int	ft_draw();
void    ft_put_pixel(int x, int y, int color);
void    ft_derec(int x, int y);
void	ft_dda(int x1, int y1, int x2, int y2);
void	ft_player(int x, int y);
int	ft_checkcolor();
int	ft_keypress(int key, void *param);
int	ft_keyrelease(int key, void *param);

#endif
