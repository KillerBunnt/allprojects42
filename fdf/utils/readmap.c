#include "../includes/all.h"

void put_coords(t_map *map);
void put_corners(t_map *map);
void rotatex(t_map *map);

void draw_base(t_map *map)
{
	map->outerlength = 100 * map->maplength;
	map->outerwidth = 100 * map->mapwidth;
	if (!map)
		return ;
	map->originx = WIDTH / 2;
	map->originy = HEIGHT / 2;
	put_corners(map);
	rotatex(map);
	while (map->map[0][0][3] + map->originy < 50)
	{
		map->outerlength -= map->maplength;
		map->outerwidth -= map->mapwidth;
		put_corners(map);
		rotatex(map);
	}
	while (map->map[map->mapwidth - 1][0][2] + map->originx < 50)
	{
		map->outerlength -= map->maplength;
		map->outerwidth -= map->mapwidth;
		put_corners(map);
		rotatex(map);
	}
	while (map->map[0][map->maplength - 1][2] + map->originx > WIDTH - 50)
	{
		map->outerlength -= map->maplength;
		map->outerwidth -= map->mapwidth;
		put_corners(map);
		rotatex(map);
	}
	while (map->map[map->mapwidth- 1][map->maplength - 1][3] + map->originy > HEIGHT - 50)
	{
		map->outerlength -= map->maplength;
		map->outerwidth -= map->mapwidth;
		put_corners(map);
		rotatex(map);
	}
	put_coords(map);
	// ft_printf("(%d, %d)", map->map[0][0][2], map->map[0][0][3]);
	// ft_printf("(%d, %d)", map->map[map->mapwidth - 1][map->maplength - 1][2], map->map[map->mapwidth - 1][map->maplength - 1][3]);
	// ft_printf("(%d, %d)", map->map[0][map->maplength - 1][2], map->map[0][map->maplength - 1][3]);
	// ft_printf("(%d, %d)", map->map[map->mapwidth - 1][0][2], map->map[map->mapwidth - 1][0][3]);
}

void rotatex(t_map *map)
{
	double degree;
	int *pos;
	degree = 120 * PI / 360;
	map->map[0][0][3] = map->map[0][0][3] * sin(degree);
	pos = &map->map[map->mapwidth- 1][map->maplength - 1][3];
	*pos = *pos * sin(degree);
	pos = &map->map[0][map->maplength - 1][3];
	*pos = *pos * sin(degree);
	pos = &map->map[map->mapwidth - 1][0][3];
	*pos = *pos * sin(degree);
}

void put_corners(t_map *map)
{
	double degree;
	unsigned int length;
	unsigned int width;

	length = map->outerlength / 2;
	width = map->outerwidth / 2;
	degree = 90 * PI / 360;
	map->map[0][0][2] = (-(int)(length)) * cos(degree) 
		+ (int)(width) * sin(degree);
	map->map[0][0][3] = (-(int)(length)) * sin(degree) 
		- (int)(width) * cos(degree);
	map->map[map->mapwidth- 1][map->maplength - 1][2] = (length) 
		* cos(degree) - (width) * sin(degree);
	map->map[map->mapwidth - 1][map->maplength - 1][3] = (length) 
		* sin(degree) + (width) * cos(degree);
	map->map[0][map->maplength - 1][2] = ((length)) * cos(degree) 
		+ (int)(width) * sin(degree);
	map->map[0][map->maplength - 1][3] = ((length)) * sin(degree) 
		- (int)(width) * cos(degree);
	map->map[map->mapwidth - 1][0][2] = -(int)(length) 
		* cos(degree) - (width) * sin(degree);
	map->map[map->mapwidth - 1][0][3] = -(int)(length) 
		* sin(degree) + (width) * cos(degree);
}

void put_coords(t_map *map)
{
	double xinterval;
	double yinterval;
	double x;
	double y;
	unsigned int xindex;
	unsigned int yindex;
	double height;
	xindex = 0;
	yindex = 0;
	map->largest = 0;
	map->smallest = 0;
	while (yindex < map->mapwidth)
	{
		while (xindex < map->maplength)
		{
			if (map->map[yindex][xindex][0] > map->largest)
				map->largest = map->map[yindex][xindex][0];
			if (map->map[yindex][xindex][0] < map->smallest)
				map->smallest = map->map[yindex][xindex][0];
			xindex++;
		}
		xindex = 0;
		yindex++;
	}
	height = 3;
	while (map->map[0][0][3] - map->largest * height + map->originy < 25
		|| (map->map[map->mapwidth - 1][map->maplength - 1][3]) + map->smallest * height + map->originy > HEIGHT - 25)
		height = height - 0.1;
	xinterval = (map->map[0][map->maplength - 1][2] - map->map[0][0][2]) / (double)(map->maplength - 1);
	yinterval = (map->map[0][map->maplength - 1][3] - map->map[0][0][3]) / (double)(map->maplength - 1);
	xindex = 0;
	yindex = 0;
	x = (double)(map->map[0][0][2]);
	y = (double)(map->map[0][0][3]);
	while(++xindex < map->maplength)
	{
		x += xinterval;
		y += yinterval;
		map->map[0][xindex][2] = (int)round(x);
		map->map[0][xindex][3] = (int)round(y) - map->map[0][xindex][0] * height;
	}
	xinterval = (map->map[map->mapwidth - 1][0][2] - map->map[0][0][2]) / (double)(map->mapwidth - 1);
	yinterval = (map->map[map->mapwidth - 1][0][3] - map->map[0][0][3]) / (double)(map->mapwidth - 1);
	xindex = 0;
	yindex = 0;
	while(xindex < map->maplength)
	{
		x = (double)(map->map[0][xindex][2]);
		y = (double)(map->map[0][xindex][3] + map->map[0][xindex][0] * height);
		while (++yindex < map->mapwidth)
		{
			x += xinterval;
			y += yinterval;
			map->map[yindex][xindex][2] = (int)round(x);
			map->map[yindex][xindex][3] = (int)round(y) - map->map[yindex][xindex][0] * height;
		}
		yindex = 0;
		xindex++;
	}
}