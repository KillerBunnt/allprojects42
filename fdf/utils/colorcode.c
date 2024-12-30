/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorcode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:16 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:18 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

int	highcolor(int alt, int largest);
int	lowcolor(int alt, int lowest);

void	get_color_type(unsigned int x, unsigned int y, t_map *map)
{
	if (map->map[y][x][0] > 0)
		map->map[y][x][1] = highcolor(map->map[y][x][0], map->largest);
	else if (map->map[y][x][0] < 0)
		map->map[y][x][1] = lowcolor(map->map[y][x][0], map->smallest);
	else
		map->map[y][x][1] = rgbtodec((int []){199, 199, 0});
}

void	assigncolor(t_map *map)
{
	int				big;
	int				small;
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	big = map->largest;
	small = map->smallest;
	while (y < map->mapwidth)
	{
		while (x < map->maplength)
		{
			if (map->map[y][x][1] == -1)
				get_color_type(x, y, map);
			x++;
		}
		y++;
		x = 0;
	}
}

int	highcolor(int alt, int largest)
{
	int				color[3];
	unsigned int	chosen;

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	chosen = 155 / largest * alt + 99;
	color[1] = chosen;
	return (rgbtodec(color));
}

int	lowcolor(int alt, int lowest)
{
	int				color[3];
	unsigned int	chosen;

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	chosen = 155 / lowest * alt + 99;
	color[0] = chosen;
	return (rgbtodec(color));
}
