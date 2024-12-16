#include "../includes/all.h"

void draw(int x, int y, t_mlxtools *mlx, int color)
{
	if (color < 0 || color > 0xFFFFFF)
		color = 0xFFFFFF;
	*(unsigned int *)(mlx->screenimgdata + (y * mlx->linesize
		+ x * mlx->bpp / 8)) = color;
}