/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:53:20 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 15:53:22 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	int				***map;
	unsigned int	maplength;
	unsigned int	mapwidth;
	unsigned int	outerwidth;
	unsigned int	outerlength;
	int				originx;
	int				originy;
	int				largest;
	int				smallest;
}t_map;

typedef struct s_mlxtools
{
	void	*link;
	void	*win;
	void	*screenimg;
	char	*screenimgdata;
	int		bpp;
	int		linesize;
	int		multibyteorder;
	t_map	*map;
}t_mlxtools;

typedef struct s_drawtools
{
	double			m;
	int				interval[2];
	int				pos[2];
	int				ydif;
	int				xdif;
	int				color;
	unsigned int	x;
	unsigned int	y;
}t_drawtools;

typedef struct s_readtools
{
	double			xinterval;
	double			yinterval;
	double			x;
	double			y;
	unsigned int	xindex;
	unsigned int	yindex;
	double			height;
}t_readtools;
#endif
