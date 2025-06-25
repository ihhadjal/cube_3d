/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/23 15:33:48 by hasnawww         ###   ########.fr       */
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
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	pos->time = 0;
	pos->old_time = 0;
	pos->posx = 22;
	pos->posy = 12;
	pos->dirx = -1;
	pos->diry = 0;
	pos->planex = 0;
	pos->planey = 0.66;
	pos->x = 0;
	ray = malloc(sizeof(t_ray));
	while (pos->x < mlx->cam_length)
	{
		ray->camera_x = 2 * pos->x / (double)mlx->cam_length;
		ray->dirx = pos->dirx + pos->planex * ray->camera_x;
		ray->diry = pos->diry + pos->planey * ray->camera_x;
	}
}

void	calculate_triangles(t_data *data)
{
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;

	hit = 0;
	if (data->ray->dirx != 0)
	{
		deltaDistX = sqrt(1 + (data->ray->diry * data->ray->diry) / (data->ray->dirx * data->ray->dirx)); 
	}
	if (data->ray->diry != 0)
	{
		deltaDistY = sqrt(1 + (data->ray->dirx * data->ray->dirx) / (data->ray->diry * data->ray->diry)); 
	}
	if (data->ray->dirx < 0)
	{
		stepX = -1;
		sideDistX = (data->pos->posx - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - data->pos->posx) * deltaDistX;
	}
	if (data->ray->diry < 0)
	{
		stepY = -1;
		sideDistY = (data->pos->posy - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - data->pos->posy) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		if (data->map->map_copy[mapX][mapY])
			hit = 1;
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
