#include "cub.h"

void	ft_dda(int x1, int y1, int x2, int y2)
{
	float dx;
	float dy;
	float steps;
	float incx;
	float incy;
	float i1;
	float j1;

	i1 = x1;
	j1 = y1;

	dx = x2 - x1;
	dy = y2 - y1;
	steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
	incx = dx / steps;
	incy = dy / steps;
	player.mx = incx;
	player.my = incy;

	while (steps > 0)
	{
		ft_put_pixel(x1, y1, 0x00FFFF);
		i1 += incx;
		j1 += incy;
		x1 = i1;
		y1 = j1;
		steps--;
	}
}
