/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:52 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:53 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	get_big_small(t_readtools *var, t_map *map)
{
	while (var->yindex < map->mapwidth)
	{
		while (var->xindex < map->maplength)
		{
			if (map->map[var->yindex][var->xindex][0] > map->largest)
				map->largest = map->map[var->yindex][var->xindex][0];
			if (map->map[var->yindex][var->xindex][0] < map->smallest)
				map->smallest = map->map[var->yindex][var->xindex][0];
			var->xindex++;
		}
		var->xindex = 0;
		var->yindex++;
	}
}

void	put_first_line(t_readtools *var, t_map *map)
{
	var->xinterval = (map->map[0][map->maplength - 1][2] - map->map[0][0][2]
			) / (double)(map->maplength - 1);
	var->yinterval = (map->map[0][map->maplength - 1][3] - map->map[0][0][3]
			) / (double)(map->maplength - 1);
	var->xindex = 0;
	var->yindex = 0;
	var->x = (double)(map->map[0][0][2]);
	var->y = (double)(map->map[0][0][3]);
	while (var->xindex < map->maplength)
	{
		var->x += var->xinterval;
		var->y += var->yinterval;
		map->map[0][var->xindex][2] = (int)round(var->x);
		map->map[0][var->xindex][3] = (int)
			round(var->y) - map->map[0][var->xindex][0] * var->height;
		var->xindex++;
	}
}

void	put_sub_coords(t_readtools *var, t_map *map)
{
	while (var->xindex < map->maplength)
	{
		var->x = (double)(map->map[0][var->xindex][2]);
		var->y = (double)(map->map[0][var->xindex][3] + map->map[0]
			[var->xindex][0] * var->height);
		while (var->yindex < map->mapwidth)
		{
			var->x += var->xinterval;
			var->y += var->yinterval;
			map->map[var->yindex][var->xindex][2] = (int)round(var->x);
			map->map[var->yindex][var->xindex][3] = (int)round(var->y
					) - map->map[var->yindex][var->xindex][0] * var->height;
			var->yindex++;
		}
		var->yindex = 0;
		var->xindex++;
	}
}

void	put_coords(t_map *map)
{
	t_readtools	var;

	ft_bzero(&var, sizeof(t_readtools));
	get_big_small(&var, map);
	var.height = 5;
	while (map->map[0][0][3] - map->largest * var.height + map->originy < 25
		|| (map->map[map->mapwidth - 1][map->maplength - 1][3]
		) + map->smallest * var.height + map->originy > HEIGHT - 25)
		var.height = var.height - 0.1;
	put_first_line(&var, map);
	var.xinterval = (map->map[map->mapwidth - 1][0][2] - map->map[0][0][2]
			) / (double)(map->mapwidth - 1);
	var.yinterval = (map->map[map->mapwidth - 1][0][3] - map->map[0][0][3]
			) / (double)(map->mapwidth - 1);
	var.xindex = 0;
	var.yindex = 0;
	put_sub_coords(&var, map);
}
