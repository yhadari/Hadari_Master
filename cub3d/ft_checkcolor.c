#include "cub.h"

int	ft_checkcolor()
{
	int i;
	int j;

	if (player.walkder == 1)
	{
		i = (line.x + player.mx*player.movespeed)/tile;
		j = (line.y + player.my*player.movespeed)/tile;
	}
	if (player.walkder == -1)
	{
		i = (line.x - player.mx*player.movespeed)/tile;
		j = (line.y - player.my*player.movespeed)/tile;
	}
	if (get.map[j][i] == '1')
		return (0);
	return (1);
}
