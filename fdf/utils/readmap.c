/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:58 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:59 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	put_coords(t_map *map);
void	put_corners(t_map *map);
void	rotatex(t_map *map);

static void	tweak_base(t_map *map)
{
	map->outerlength -= map->maplength;
	map->outerwidth -= map->mapwidth;
	put_corners(map);
	rotatex(map);
}

void	draw_base(t_map *map)
{
	ft_printf("Success!!!\nDrawing map...\n");
	map->outerlength = 100 * map->maplength;
	map->outerwidth = 100 * map->mapwidth;
	if (!map)
		return ;
	map->originx = WIDTH / 2;
	map->originy = HEIGHT / 2;
	put_corners(map);
	rotatex(map);
	while (map->map[0][0][3] + map->originy < 50)
		tweak_base(map);
	while (map->map[map->mapwidth - 1][0][2] + map->originx < 50)
		tweak_base(map);
	while (map->map[0][map->maplength - 1][2] + map->originx > WIDTH - 50)
		tweak_base(map);
	while (map->map[map->mapwidth - 1][map->maplength - 1]
		[3] + map->originy > HEIGHT - 50)
		tweak_base(map);
	put_coords(map);
}

void	rotatex(t_map *map)
{
	double	degree;
	int		*pos;

	degree = 120 * PI / 360;
	map->map[0][0][3] = map->map[0][0][3] * sin(degree);
	pos = &map->map[map->mapwidth - 1][map->maplength - 1][3];
	*pos = *pos * sin(degree);
	pos = &map->map[0][map->maplength - 1][3];
	*pos = *pos * sin(degree);
	pos = &map->map[map->mapwidth - 1][0][3];
	*pos = *pos * sin(degree);
}

void	put_corners(t_map *map)
{
	double			degree;
	unsigned int	length;
	unsigned int	width;

	length = map->outerlength / 2;
	width = map->outerwidth / 2;
	degree = 90 * PI / 360;
	map->map[0][0][2] = (-(int)(length)) * cos(degree)
		+ (int)(width) *sin(degree);
	map->map[0][0][3] = (-(int)(length)) * sin(degree)
		- (int)(width) *cos(degree);
	map->map[map->mapwidth - 1][map->maplength - 1][2] = (length)
		* cos(degree) - (width) * sin(degree);
	map->map[map->mapwidth - 1][map->maplength - 1][3] = (length)
		* sin(degree) + (width) * cos(degree);
	map->map[0][map->maplength - 1][2] = ((length)) * cos(degree)
		+ (int)(width) *sin(degree);
	map->map[0][map->maplength - 1][3] = ((length)) * sin(degree)
		- (int)(width) *cos(degree);
	map->map[map->mapwidth - 1][0][2] = -(int)(length)
		*cos(degree) - (width) * sin(degree);
	map->map[map->mapwidth - 1][0][3] = -(int)(length)
		*sin(degree) + (width) * cos(degree);
}
