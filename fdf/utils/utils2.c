/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:49:05 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:49:06 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void	draw(int x, int y, t_mlxtools *mlx, int color)
{
	if (color < 0 || color > 0xFFFFFF)
		color = 0xFFFFFF;
	*(unsigned int *)(mlx->screenimgdata + (y * mlx->linesize
				+ x * mlx->bpp / 8)) = color;
}

int	rgbtodec(int color[3])
{
	return (color[0] * 65536 + color[1] * 256 + color[2]);
}
