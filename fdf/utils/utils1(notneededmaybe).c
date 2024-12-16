#include "../includes/all.h"

void start_draw(t_mlxtools *mlxtools)
{
	int linex = 20;
	int liney = 20;
	int x;
	int y;
	double degree = 45;

	y = -liney / 2;
	x = -linex / 2;
	dotme(degree, x, y, mlxtools);
	y = liney / 2;
	dotme(degree, x, y, mlxtools);
	x = linex / 2;
	dotme(degree, x, y, mlxtools);
	y = -liney / 2;
	dotme(degree, x, y, mlxtools);
}
void draw_square(t_mlxtools *mlxtools)
{
	int linex = 20;
	int liney = 20;
	int x;
	*(unsigned int *)(mlxtools->screenimgdata + (HEIGHT
			* mlxtools->linesize + WIDTH * mlxtools->bpp / 8)) = 0xFFFFFF;

	x = HEIGHT / 2 - liney / 2 - 1;
	while (++x <= HEIGHT / 2 + liney / 2)
	{
		*(unsigned int *)(mlxtools->screenimgdata + (x 
			* mlxtools->linesize + (WIDTH / 2 - linex / 2) * mlxtools->bpp / 8)) = 0xFFFFFF;

		*(unsigned int *)(mlxtools->screenimgdata + (x 
			* mlxtools->linesize + (WIDTH / 2 + linex / 2) * mlxtools->bpp / 8)) = 0xFFFFFF;
	}
	x = WIDTH / 2 - linex / 2 - 1;

	while (++x < WIDTH / 2 + linex / 2)
	{
		*(unsigned int *)(mlxtools->screenimgdata + ((HEIGHT / 2 - liney / 2)
			* mlxtools->linesize + x * mlxtools->bpp / 8)) = 0xFFFFFF;

		*(unsigned int *)(mlxtools->screenimgdata + ((HEIGHT / 2 + liney / 2) 
			* mlxtools->linesize + x * mlxtools->bpp / 8)) = 0xFFFFFF;
	}
	while (++x < WIDTH)
		*(unsigned int *)(mlxtools->screenimgdata + (HEIGHT / 2 
			* mlxtools->linesize + x * mlxtools->bpp / 8)) = 0xFFFFFF;
}
void dotme(double degree, int x, int y, t_mlxtools *mlxtools)
{
	static int x2;
	static int y2;
	int newx;
	int newy;
	double m;
	newx = x * cos(degree) - y * sin(degree);
	newy = x * sin(degree) + y * cos(degree);
	*(unsigned int *)(mlxtools->screenimgdata + ((HEIGHT / 2 + newy) * mlxtools->linesize 
		+ (WIDTH / 2 + newx) * mlxtools->bpp / 8)) = 0xFFFFFF;
	if (x2 < 0 && y2 < 0)
	{
		x2 = newx;
		y2 = newy;
	}
	else
	{
		m = (double)(y2 - newy) / (double)(x2 - newx);
		if (m > 1)
		{
			y--;
			x--;
			if (y2 < newy)
				while (++y2 < newy)
					while ((++x2 - newx) * m == (y2 - newy))
						*(unsigned int *)(mlxtools->screenimgdata + ((HEIGHT / 2 + y2) * mlxtools->linesize 
							+ (WIDTH / 2 + x2) * mlxtools->bpp / 8)) = 0xFFFFFF;
		}
		x = -1;
		y = -1;
	}
}