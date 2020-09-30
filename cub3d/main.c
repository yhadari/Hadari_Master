/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:02:30 by yhadari           #+#    #+#             */
/*   Updated: 2020/02/11 23:07:22 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include "cub.h"

int main()
{
	void *mlx_ptr;
	void *win_ptr;
//	int x;
//	int y;
//	int z;
//	int a;
//	int b;

//	x = 100;
//	y = 100;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 550, 550, "y");
/*	while (y < 200)
	{
		while (x++ < 200)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffff);
		y++;
		x = 100;
	}
*///	x = 0;
//	y = 0;
//	while (y < 943)
//	{
//		while (x++ < 943)
//		{
//			a = 843;
//			b = 107;
//			z = pow(x - a, 2) + pow(y - b, 2);
//			if (z <= 200)
//				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffff);
//		}
//		y++;
//		x = 0;
//	}
	int x,y,r;
	int x1,y1;
      	float angle;

	x = 200;
	y = 200;
	r = 200;
	angle = 360;
	
	while (angle > 0)
         {
		 x1 = r * cos(angle * M_PI / 180);
		 y1 = r * sin(angle * M_PI / 180);
		 ft_dda2(x, y, (x+x1), (y+y1), mlx_ptr, win_ptr);
		// mlx_pixel_put(mlx_ptr, win_ptr, (x + x1), (y + y1), 0x00ffff);
		 angle -= 90;
	 }
	mlx_loop(mlx_ptr);
}
