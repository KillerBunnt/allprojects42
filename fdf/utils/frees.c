/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees  .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:48:31 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:48:32 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	freemap(t_map *map)
{
	unsigned int	len;

	len = map->maplength;
	while (1)
	{
		map->mapwidth--;
		while (1)
		{
			len--;
			free(map->map[map->mapwidth][len]);
			if (!len)
				break ;
		}
		free(map->map[map->mapwidth]);
		if (!map->mapwidth)
			break ;
		len = map->maplength;
	}
	free(map->map);
}
