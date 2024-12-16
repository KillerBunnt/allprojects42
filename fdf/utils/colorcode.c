#include "../includes/all.h"

int highcolor(int alt, int largest);
int lowcolor(int alt, int lowest);
int rgbtodec(int color[3]);

int colorinit(t_map *map)
{
	map->colors = ft_calloc(11, sizeof(int));
	if (!map->colors)
		return (1);
	
	map->colors[0] = 0xFFFFFF;
	map->colors[1] = 0xD3D3D3;
	map->colors[2] = 0xA52A2A;
	map->colors[3] = 0x006400;
	map->colors[4] = 0x90EE90;
	map->colors[5] = 0xFFFF00;
	map->colors[6] = 0xADD8E6;
	map->colors[7] = 0x0000CD;
	map->colors[8] = 0x00008B;
	map->colors[9] = 0x000033;
	return (0);
}

void assigncolor(t_map *map)
{
	int big;
	int small;
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	big = map->largest;
	small = map->smallest;
	
	while (y < map->mapwidth)
	{
		while (x < map->maplength)
		{
			if (map->map[y][x][1] == -1)
			{
				if (map->map[y][x][0] > 0)
					map->map[y][x][1] = highcolor(map->map[y][x][0], big);
				else if (map->map[y][x][0] < 0)
					map->map[y][x][1] = lowcolor(map->map[y][x][0], small);
				else
					map->map[y][x][1] = rgbtodec((int[]){199,199,0});
			}
			x++;
		}
		y++;
		x = 0;
	}
}

int highcolor(int alt, int largest)//green
{
	int color[3];
	unsigned int chosen;
	color[0] = 0;// 0 64 0
	color[1] = 0;
	color[2] = 0;
	chosen = 155 / largest * alt + 99;
	color[1] = chosen;
	return (rgbtodec(color));
}

int lowcolor(int alt, int lowest)//red
{
	int color[3];
	unsigned int chosen;
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	chosen = 155 / lowest * alt + 99;
	color[0] = chosen;
	return (rgbtodec(color));
}

int rgbtodec(int color[3])
{
	return (color[0] * 65536 + color[1] * 256 + color[2]);
}