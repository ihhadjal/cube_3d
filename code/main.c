/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/26 21:24:09 by ilhasnao         ###   ########.fr       */
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

void	init_colors(t_data *data)
{
	data->rgb = malloc(sizeof(t_color));
	data->rgb->r = 255;
	data->rgb->g = 0;
	data->rgb->b = 0;
}

int assemble_rgb(t_color *c)
{
	return (c->r << 16 | c->g << 8 | c->b);
}

void	calculate_triangles(t_data *data)
{
	data->algo->hit = 0;
	data->algo->mapX = (int)data->pos->posx;
	data->algo->mapY = (int)data->pos->posy;
	if (data->ray->dirx != 0)
	{
		data->algo->deltaDistX = sqrt(1 + (data->ray->diry * data->ray->diry) / (data->ray->dirx * data->ray->dirx)); 
	}
	if (data->ray->diry != 0)
	{
		data->algo->deltaDistY = sqrt(1 + (data->ray->dirx * data->ray->dirx) / (data->ray->diry * data->ray->diry)); 
	}
	if (data->ray->dirx < 0)
	{
		data->algo->stepX = -1;
		data->algo->sideDistX = (data->pos->posx - data->algo->mapX) * data->algo->deltaDistX;
	}
	else
	{
		data->algo->stepX = 1;
		data->algo->sideDistX = (data->algo->mapX + 1.0 - data->pos->posx) * data->algo->deltaDistX;
	}
	if (data->ray->diry < 0)
	{
		data->algo->stepY = -1;
		data->algo->sideDistY = (data->pos->posy - data->algo->mapY) * data->algo->deltaDistY;
	}
	else
	{
		data->algo->stepY = 1;
		data->algo->sideDistY = (data->algo->mapY + 1.0 - data->pos->posy) * data->algo->deltaDistY;
	}
	while (data->algo->hit == 0)
	{
		if (data->algo->sideDistX < data->algo->sideDistY)
		{
			data->algo->sideDistX += data->algo->deltaDistX;
			data->algo->mapX += data->algo->stepX;
			data->algo->side = 0;
		}
		else
		{
			data->algo->sideDistY += data->algo->deltaDistY;
			data->algo->mapY += data->algo->stepY;
			data->algo->side = 1;
		}
		if (data->map->map_copy[data->algo->mapX][data->algo->mapY])
			data->algo->hit = 1;
	}
	if (data->algo->side == 0)
		data->algo->perpWallDist = (data->algo->sideDistX - data->algo->deltaDistX);
	else
		data->algo->perpWallDist = (data->algo->sideDistY - data->algo->deltaDistY);
	data->algo->lineHeight = (int)(data->cam_height / data->algo->perpWallDist);
	data->algo->drawStart = data->cam_height / 2 - data->algo->lineHeight / 2;
	if (data->algo->drawStart < 0)
		data->algo->drawStart = 0;
	if (data->algo->drawEnd >= data->cam_height)
		data->algo->drawEnd = data->cam_height - 1;
}

void	assign_color(t_data *data, int mapx, int mapy, int side)
{
	int	color;

	if (data->map->map_copy[mapx][mapy] == 1)
		color = data->rgb->r;
	if (side == 1)
		color = color / 2;
}

void	launch_ray(t_data *data)
{
	data->ray->camera_x = 2 * data->pos->x / (double)data->cam_length;
	data->ray->dirx = data->pos->dirx + data->pos->planex * data->ray->camera_x;
	data->ray->diry = data->pos->diry + data->pos->planey * data->ray->camera_x;
}

void	render_map(t_data *data)
{
	int	y;
	int	color;

	color = assemble_rgb(data->rgb);
	y = 0;
	while (y < data->cam_height)
	{
		if (y < data->algo->drawStart)
			mlx_pixel_put(data->ptr, data->win, data->pos->x, y, 0x87CEEB);
		else if (y >= data->algo->drawStart && y <= data->algo->drawEnd)
			mlx_pixel_put(data->ptr, data->win, data->pos->x, y, data->rgb->b);
		else
			mlx_pixel_put(data->ptr, data->win, data->pos->x, y, 0x228B22);
		y++;
		//CA RENTRE DANS AUCUNE DES DEUX PREMIERES CONDITIONS
	}
}
void	draw_fov(t_data *mlx)
{
	mlx->pos = malloc(sizeof(t_pos));
	mlx->pos->time = 0;
	mlx->pos->old_time = 0;
	mlx->pos->posx = 12;
	mlx->pos->posy = 12;
	mlx->pos->dirx = -1;
	mlx->pos->diry = 0;
	mlx->pos->planex = 0;
	mlx->pos->planey = 0.66;
	mlx->pos->x = 0;
	mlx->pos->y = 0;
	mlx->ray = malloc(sizeof(t_ray));
	mlx->algo = malloc(sizeof(t_dda));
	while (mlx->pos->x < mlx->cam_length)
	{
		launch_ray(mlx);
		calculate_triangles(mlx);
		render_map(mlx);
		mlx->pos->x++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_map	map;

	if (parsing(argc, argv, &map) == 0)
	{
		mlx = malloc(sizeof(t_data));
		mlx->map = &map;
		mlx->cam_height = 1200;
		mlx->cam_length = 1200;
		mlx->ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->ptr, mlx->cam_height,
			mlx->cam_length, "Bomboclaat");
		init_colors(mlx);
		draw_fov(mlx);
		if (!mlx->win)
		{
			ft_putstr_fd("Error: Failed to create window\n", 2);
			mlx_loop_end(mlx->ptr);
		}
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_dem_hoes, mlx);
		mlx_loop(mlx->ptr);
		free_dem_hoes(mlx);
	}
	return (0);
}
