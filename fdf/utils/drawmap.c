/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:31 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:32 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	draw_lines(t_mlxtools *mlx, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	assigncolor(map);
	while (y < map->mapwidth)
	{
		while (x < map->maplength)
		{
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

void	initdrawvars(t_drawtools *var, t_map *map,
			unsigned int x, unsigned int y)
{
	var->x = x;
	var->y = y;
	var->interval[0] = 1;
	var->interval[1] = 1;
	var->pos[0] = map->map[y][x][2];
	var->pos[1] = map->map[y][x][3];
}

int	getcol(int inddif, int origdif, int colora, int colorb)
{
	double	backcolratio;
	int		rgba[3];
	int		rgbb[3];
	int		returncol[3];

	backcolratio = (double)inddif / origdif;
	rgba[0] = colora / 65536 % 256;
	rgba[1] = colora / 256 % 256;
	rgba[2] = colora % 256;
	rgbb[0] = colorb / 65536 % 256;
	rgbb[1] = colorb / 256 % 256;
	rgbb[2] = colorb % 256;
	returncol[0] = (1 - backcolratio) * rgba[0] + backcolratio * rgbb[0];
	returncol[1] = (1 - backcolratio) * rgba[1] + backcolratio * rgbb[1];
	returncol[2] = (1 - backcolratio) * rgba[2] + backcolratio * rgbb[2];
	return (returncol[0] * 65536 + returncol[1] * 256 + returncol[2]);
}
