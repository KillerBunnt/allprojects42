/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdexmund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:00:48 by tdexmund          #+#    #+#             */
/*   Updated: 2024/12/24 13:00:50 by tdexmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/all.h"

int	end_program(t_mlxtools *mlx)
{
	if (mlx->win)
	{
		mlx_destroy_image(mlx->link, mlx->screenimg);
		mlx_destroy_window(mlx->link, mlx->win);
		mlx_destroy_display(mlx->link);
	}
	freemap(mlx->map);
	free(mlx->link);
	exit(0);
	return (0);
}

int	redraw(t_mlxtools *mlxtools)
{
	mlx_put_image_to_window(mlxtools->link, mlxtools->win,
		mlxtools->screenimg, 0, 0);
	return (0);
}

int	key_handler(int keypressed, t_mlxtools *mlx)
{
	if (keypressed == 65307)
		end_program(mlx);
	return (0);
}

void	mlxinit(t_mlxtools *mlx, t_map *map)
{
	mlx->link = mlx_init();
	mlx->win = mlx_new_window(mlx->link, WIDTH, HEIGHT, "FDF");
	mlx_hook(mlx->win, 17, 0, end_program, mlx);
	mlx_hook(mlx->win, 25, 1L << 18, redraw, mlx);
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx->map = map;
}

int	main(int argcount, char **args)
{
	t_mlxtools	mlxtools;
	t_map		map;

	if (argcount != 2)
	{
		ft_printf("WRONG FORMAT\n format: ./fdf map");
		return (0);
	}
	ft_bzero(&mlxtools, sizeof(t_mlxtools));
	ft_bzero(&map, sizeof(t_map));
	if (loadmap(&map, args[1]))
		end_program(&mlxtools);
	else
	{
		mlxinit(&mlxtools, &map);
		mlxtools.screenimg = mlx_new_image(mlxtools.link, WIDTH, HEIGHT);
		mlxtools.screenimgdata = mlx_get_data_addr(mlxtools.screenimg,
				&mlxtools.bpp, &mlxtools.linesize, &mlxtools.multibyteorder);
		draw_base(&map);
		draw_lines(&mlxtools, &map);
		redraw(&mlxtools);
		ft_printf("Draw complete\n");
	}
	mlx_loop(mlxtools.link);
	return (0);
}
