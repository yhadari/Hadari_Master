#include "cub.h"

int	ft_key()
{
	if (player.walkder == 1)
	{
		if(ft_checkcolor())
		{
			line.x += player.mx*player.movespeed;
			line.y += player.my*player.movespeed;
		}
	}
	if (player.turnder == -1)
	{
		p.index = 2;
		p.angle1 -= p.rotationspeed;
	}
	if (player.walkder == -1)
	{
		if (ft_checkcolor())
		{
			line.x -= player.mx*player.movespeed;
			line.y -= player.my*player.movespeed;
		}
	}
	if (player.turnder == 1)
	{
		p.index = 1;
		p.angle += p.rotationspeed;
		p.angle1 += p.rotationspeed;
	}
	return (0);
}
