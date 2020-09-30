#include "cub.h"

void	ft_derec(int x, int y)
{
	p.rotationspeed = 3;
	player.movespeed = 3;
	if (get.der == 1 && p.index == 0)
	{
		p.angle = 270;
		p.angle1 = 90;
	}
	if (get.der == 2 && p.index == 0)
	{
		p.angle = 90;
		p.angle1 = 270;
	}
	if (get.der == 3 && p.index == 0)
	{
		p.angle = 180;
		p.angle1 = 180;
	}
	if (get.der == 4 && p.index == 0)
	{
		p.angle = 0;
		p.angle1 = 360;
	}
	if (p.index == 2)
	{
		p.angle = p.angle1;
		if (get.der == 1 || get.der == 2)
			p.angle = p.angle - 180;
	}
	p.x1 = line.x + tile*cos(p.angle * M_PI/180);
	p.y1 = line.y + tile*sin(p.angle * M_PI/180);
	ft_dda(line.x, line.y, p.x1, p.y1);
}
