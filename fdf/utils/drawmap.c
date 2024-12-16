#include "../includes/all.h"

void draw_vertical(t_mlxtools *mlx, t_map *map, unsigned int x, unsigned int y);
void draw_horizontal(t_mlxtools *mlx, t_map *map, unsigned int x, unsigned int y);
int getcol(int inddif, int origdif, int colora, int colorb);

void draw_lines(t_mlxtools *mlx, t_map *map)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	assigncolor(map);
	// ft_printf("%d, %d|", map->maplength, map->mapwidth);
	while (y < map->mapwidth)
	{
		while (x < map->maplength)
		{
			// ft_printf("(%d, %d, %d)", map->map[y][x][2], map->map[y][x][3], map->map[y][x][0]);
			if (x + 1 < map->maplength)
				draw_horizontal(mlx, map, x, y);
			if (y + 1 < map->mapwidth)
				draw_vertical(mlx, map, x, y);
			redraw(mlx);
			x++;
		}
		x = 0;
		y++;
	}
}

void draw_horizontal(t_mlxtools *mlx, t_map *map, unsigned int x, unsigned int y)
{
	int xinterval;
	int yinterval;
	double m;
	// double c;
	int xpos;
	int ypos;
	int xdif;
	int color;
	
	xinterval = 1;
	if (map->map[y][x][2] > map->map[y][x + 1][2])
		xinterval -= 2;
	else if (map->map[y][x][2] == map->map[y][x + 1][2])
		xinterval = 0;
	yinterval = 1;
	if (map->map[y][x][3] > map->map[y][x + 1][3])
		yinterval -= 2;
	else if (map->map[y][x][3] == map->map[y][x + 1][3])
		yinterval = 0;
	xpos = map->map[y][x][2];
	ypos = map->map[y][x][3];
	m = (double)(ypos - map->map[y][x + 1][3]) / (xpos - map->map[y][x + 1][2]);
	// c = m * xpos - ypos;
	xdif = map->map[y][x + 1][2] - xpos;
	if (m <= 1 && m >= -1)
		while (xpos != map->map[y][x + 1][2])
		{
			color = getcol(map->map[y][x + 1][2] - xpos, xdif, map->map[y][x + 1][1], map->map[y][x][1]);
			draw(xpos + map->originx, ypos + map->originy, mlx, color);
			xpos += xinterval;
			if (ypos - map->map[y][x + 1][3] != (int)(m * (xpos - map->map[y][x + 1][2])))
				ypos += yinterval;
			if (ypos - map->map[y][x + 1][3] != (int)(m * (xpos - map->map[y][x + 1][2])))
				ypos -= yinterval;
		}
	else
		while (ypos != map->map[y][x + 1][3])
		{
			color = getcol(map->map[y][x + 1][2] - xpos, xdif, map->map[y][x + 1][1], map->map[y][x][1]);
			draw(xpos + map->originx, ypos + map->originy, mlx, color);
			ypos += yinterval;
			if (ypos - map->map[y][x + 1][3] != (int)(m * (xpos - map->map[y][x + 1][2])))
				xpos += xinterval;
			if (ypos - map->map[y][x + 1][3] != (int)(m * (xpos - map->map[y][x + 1][2])))
				xpos -= xinterval;
		}
	color = getcol(map->map[y][x + 1][2] - xpos, xdif, map->map[y][x + 1][1], map->map[y][x][1]);
	draw(xpos + map->originx, ypos + map->originy, mlx, color);
}

void draw_vertical(t_mlxtools *mlx, t_map *map, unsigned int x, unsigned int y)
{
	double m;
	int xinterval;
	int yinterval;
	int xpos;
	int ypos;
	int ydif;
	int color;

	xinterval = 1;
	if (map->map[y][x][2] - map->map[y + 1][x][2] > 0)
		xinterval -= 2;
	yinterval = 1;
	if (map->map[y][x][3] - map->map[y + 1][x][3] > 0)
		yinterval -= 2;
	m = (double)((int)map->map[y][x][3] - map->map[y + 1][x][3])
		/(double)((int)map->map[y][x][2] - map->map[y + 1][x][2]);
	xpos = map->map[y][x][2];
	ypos = map->map[y][x][3];
	ydif = map->map[y + 1][x][3] - ypos;
	if (m <= 1 && m >= -1)
		while (xpos != map->map[y + 1][x][2])
		{
			color = getcol(map->map[y + 1][x][3] - ypos, ydif, map->map[y + 1][x][1], map->map[y][x][1]);
			draw(xpos + map->originx, ypos + map->originy, mlx, color);
			xpos += xinterval;
			if (ypos - map->map[y + 1][x][3] != (int)(m * (xpos - map->map[y + 1][x][2])))
				ypos += yinterval;
			if (ypos - map->map[y + 1][x][3] != (int)(m * (xpos - map->map[y + 1][x][2])))
				ypos -= yinterval;
		}
	else
		while (ypos != map->map[y + 1][x][3])
		{
			color = getcol(map->map[y + 1][x][3] - ypos, ydif, map->map[y + 1][x][1], map->map[y][x][1]);
			draw(xpos + map->originx, ypos + map->originy, mlx, color);
			ypos += yinterval;
			if (ypos - map->map[y + 1][x][3] != (int)(m * (xpos - map->map[y + 1][x][2])))
				xpos += xinterval;
			if (ypos - map->map[y + 1][x][3] != (int)(m * (xpos - map->map[y + 1][x][2])))
				xpos -= xinterval;
		}
	color = getcol(map->map[y + 1][x][3] - ypos, ydif, map->map[y + 1][x][1], map->map[y][x][1]);
	draw(xpos + map->originx, ypos + map->originy, mlx, color);
}

int getcol(int inddif, int origdif, int colora, int colorb)
{
	double backcolratio;
	int rgba[3];
	int rgbb[3];
	int returncol[3];

	backcolratio = (double)inddif / origdif;
	rgba[0] = colora / 65536 % 256;
	rgba[1] = colora / 256 % 256;
	rgba[2] = colora % 256;
	rgbb[0] = colorb / 65536 % 256;
	rgbb[1] = colorb / 256 % 256;
	rgbb[2] = colorb % 256;

	returncol[0] = (1-backcolratio) * rgba[0] + backcolratio * rgbb[0];
	returncol[1] = (1-backcolratio) * rgba[1] + backcolratio * rgbb[1];
	returncol[2] = (1-backcolratio) * rgba[2] + backcolratio * rgbb[2];
	return (returncol[0] * 65536 + returncol[1] * 256 + returncol[2]);

}