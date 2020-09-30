#include "cub.h"

void	ft_render()
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, get.win_colum ,get.win_hori, "yassine");
	mlx_hook(win_ptr, 2, 1L<<0, ft_keypress, NULL);
	mlx_hook(win_ptr, 3, 1L<<1, ft_keyrelease, NULL);
	mlx_loop_hook(mlx_ptr, ft_draw, NULL);
	mlx_loop(mlx_ptr);
}

void	ft_put_pixel(int x, int y, int color)
{
	int *ptr;
	int i;
	int j;
	int k;

	if (x > 0 && y > 0 && x <= 1600 && y <= 900)
	{
		ptr = (int*)mlx_get_data_addr(image_ptr, &i, &j, &k);
		ptr[x + y * get.win_colum] = color;
	}
}

void	ft_player(int x, int y)
{
/*	float x1;
	float y1;
	float angle;

	angle = 0;

	while (angle < 360)
	{
		x1 = tile/9 * cos(angle * M_PI/180);
		y1 = tile/9 * sin(angle * M_PI/180);
		ft_put_pixel((x + x1), (y + y1), 0xffff00);
		angle += 1;
	}*/
	ft_put_pixel(x, y, 0xffff00);
}

void	ft_draw1(int xx, int yy, int tile_size)
{
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	color = 0xFFFF00;
	if (tile_size == 0)
	{
		tile_size = tile;
		color = 0x2E8B57;
	}
	while (y < tile_size)
	{
		while (x < tile_size)
		{
			ft_put_pixel(xx, yy, color);
			xx++;
			x++;
		}
		yy++;
		y++;
		xx = xx - tile_size;
		x = 0;
	}
}

int ft_draw()
{
	int i;
	int j;

	i = 0;
	j = 0;
	draw.xx = 0;
	draw.yy = 0;
	draw.savex = get.colum;
	draw.savey = get.hori;
	j = 0;
	image_ptr = mlx_new_image(mlx_ptr, get.win_colum ,get.win_hori);
	while (get.hori-- > 0)
	{
		while (get.colum-- > 0)
		{
			if (get.map[i][j++] == '1')
				ft_draw1(draw.xx, draw.yy, 0);
			draw.xx += tile;
		}
		i++;
		j = 0;
		draw.yy += tile;
		draw.xx = 0;
		get.colum = draw.savex;
	}
	get.hori = draw.savey;
	ft_key();
	ft_derec(line.x, line.y);
	ft_player(line.x, line.y);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, image_ptr);
	return (0);
}

int main(void)
{
	ft_get();
	ft_render();
	return (0);
}
