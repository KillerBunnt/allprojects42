#include "../minilibx/mlx.h"
#include "../includes/all.h"

int end_program(t_mlxtools *mlxtools)
{
    mlx_destroy_window(mlxtools->mlx, mlxtools->win);
    exit(0);
    return (0);
}

int main()
{
    t_mlxtools mlxtools;

    mlxtools.mlx = mlx_init(); // Initialize the MiniLibX
    mlxtools.win = mlx_new_window(mlxtools.mlx, 800, 600, "Hello World"); // Create a new window
    mlx_hook(mlxtools.win, 17, 0, end_program, &mlxtools);
    // Draw something (e.g., a pixel)
    mlx_pixel_put(mlxtools.mlx, mlxtools.win, 400, 300, 0xFFFFFF); // Put a white pixel at (400, 300)
    // mlx_destroy_window(mlxtools.mlx, mlxtools.win);
    
    mlx_loop(mlxtools.mlx); // Enter the event loop
    return 0;
}