#include "cub.h"

int	ft_keypress(int key, void *param)
{
//	player.walkder = 0;
//	player.turnder = 0;
	if (key == 65307)
		exit(0);
	if (key == 119)
		player.walkder = 1;
	if (key == 115)
		player.walkder = -1;
	if (key == 100)
		player.turnder = 1;
	if (key == 97)
		player.turnder = -1;
	return (0);
}

int	ft_keyrelease(int key, void *param)
{
	if (key == 119)
		player.walkder = 0;
	if (key == 115)
		player.walkder = 0;
	if (key == 100)
		player.turnder = 0;
	if (key == 97)
		player.turnder = 0;
	return (0);
}
