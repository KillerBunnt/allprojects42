#ifndef ALL_H
# define ALL_H

# define WIDTH 1000
# define HEIGHT 750
# define PI 3.1415
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <sys/types.h>
# include "../libftprintf/ft_printf.h"
# include "../libftprintf/libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "./mlxstructs.h"

void draw(int x, int y, t_mlxtools *mlx, int color);
int redraw(t_mlxtools *mlxtools);
int loadmap(t_map *map, char *mapstr);
void draw_base(t_map *map);
void draw_lines(t_mlxtools *mlx, t_map *map);
void assigncolor(t_map *map);

#endif