/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:37 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:38 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

static void	draw_by_x(t_drawtools *var, t_map *map, t_mlxtools *mlx)
{
	while (var->pos[0] != map->map[var->y][var->x + 1][2])
	{
		if (abs(var->xdif) > abs(var->ydif))
		{
			var->color = getcol(map->map[var->y][var->x + 1][2] - var->pos[0],
					var->xdif, map->map[var->y][var->x + 1][1],
					map->map[var->y][var->x][1]);
		}
		else
		{
			var->color = getcol(map->map[var->y][var->x + 1][3] - var->pos[1],
					var->ydif, map->map[var->y][var->x + 1][1],
					map->map[var->y][var->x][1]);
		}
		draw(var->pos[0] + map->originx, var->pos[1] + map->originy,
			mlx, var->color);
		var->pos[0] += var->interval[0];
		if (var->pos[1] - map->map[var->y][var->x + 1][3] != (int)(var->m *
			(var->pos[0] - map->map[var->y][var->x + 1][2])))
			var->pos[1] += var->interval[1];
		if (var->pos[1] - map->map[var->y][var->x + 1][3] != (int)(var->m *
			(var->pos[0] - map->map[var->y][var->x + 1][2])))
			var->pos[1] -= var->interval[1];
	}
}

static void	draw_by_y(t_drawtools *var, t_map *map, t_mlxtools *mlx)
{
	while (var->pos[1] != map->map[var->y][var->x + 1][3])
	{
		if (abs(var->xdif) > abs(var->ydif))
		{
			var->color = getcol(map->map[var->y][var->x + 1][2] - var->pos[0],
					var->xdif, map->map[var->y][var->x + 1][1],
					map->map[var->y][var->x][1]);
		}
		else
		{
			var->color = getcol(map->map[var->y][var->x + 1][3] - var->pos[1],
					var->ydif, map->map[var->y][var->x + 1][1],
					map->map[var->y][var->x][1]);
		}
		draw(var->pos[0] + map->originx, var->pos[1] + map->originy,
			mlx, var->color);
		var->pos[1] += var->interval[1];
		if (var->pos[1] - map->map[var->y][var->x + 1][3] != (int)(var->m *
			(var->pos[0] - map->map[var->y][var->x + 1][2])))
			var->pos[0] += var->interval[0];
		if (var->pos[1] - map->map[var->y][var->x + 1][3] != (int)(var->m *
			(var->pos[0] - map->map[var->y][var->x + 1][2])))
			var->pos[0] -= var->interval[0];
	}
}

void	draw_horizontal(t_mlxtools *mlx, t_map *map,
			unsigned int x, unsigned int y)
{
	t_drawtools	var;

	initdrawvars(&var, map, x, y);
	if (map->map[y][x][2] > map->map[y][x + 1][2])
		var.interval[0] = -1;
	else if (map->map[y][x][2] == map->map[y][x + 1][2])
		var.interval[0] = 0;
	if (map->map[y][x][3] > map->map[y][x + 1][3])
		var.interval[1] = -1;
	else if (map->map[y][x][3] == map->map[y][x + 1][3])
		var.interval[1] = 0;
	var.m = (double)(var.pos[1] - map->map[y][x + 1][3]) / (
			var.pos[0] - map->map[y][x + 1][2]);
	var.xdif = map->map[y][x + 1][2] - var.pos[0];
	var.ydif = map->map[y][x + 1][3] - var.pos[1];
	if (var.m <= 1 && var.m >= -1)
		draw_by_x(&var, map, mlx);
	else
		draw_by_y(&var, map, mlx);
	var.color = getcol(map->map[y][x + 1][2] - var.pos[0], var.xdif,
			map->map[y][x + 1][1], map->map[y][x][1]);
	draw(var.pos[0] + map->originx, var.pos[1] + map->originy, mlx, var.color);
}
