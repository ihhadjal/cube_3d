/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/19 20:23:31 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/cube.h"

int	free_dem_hoes(t_data *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	free(mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_data *mlx)
{
	if (keycode == ESC)
		mlx_loop_end(mlx->ptr);
	return (0);
}

void	draw_fov(t_data *mlx)
{
	t_ray	*ray;
	double	time;
	double	old_time;
	int		x;
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;

	time = 0;
	old_time = 0;
	posx = 22;
	posy = 12;
	dirx = -1;
	diry = 0;
	planex = 0;
	planey = 0.66;
	x = 0;
	ray = malloc(sizeof(t_ray));
	while (x < mlx->cam_length)
	{
		ray->camera_x = 2 * x / (double)mlx->cam_length;
		ray->dirx = dirx + planex * ray->camera_x;
		ray->diry = diry + planey * ray->camera_x;
	}
}

int	main(int argc, char **argv)
{
	t_data	*mlx;
	// t_map	map;
	void	*background;

	// if (parsing(argc, argv, &map) == 0)
	// {
	if (argc == 7 && argv[0][0])
	{
		printf("sfesf\n");
	}
		mlx = malloc(sizeof(t_data));
		mlx->cam_height = 1200;
		mlx->cam_length = 1200;
		mlx->ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->ptr, mlx->cam_height,
			mlx->cam_length, "Bomboclaat");
		if (!mlx->win)
		{
			ft_putstr_fd("Error: Failed to create window\n", 2);
			mlx_loop_end(mlx->ptr);
		}
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_dem_hoes, mlx);
		mlx_loop(mlx->ptr);
		free_dem_hoes(mlx);
	// }
	return (0);
}
