/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/01 19:27:44 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/cube.h"

int	free_all(t_data *mlx)
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
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
		if (data->map->map_copy[data->algo->mapY][data->algo->mapX] == '1')
			data->algo->hit = 1;
	}
	if (data->algo->side == 0)
		data->algo->perpWallDist = (data->algo->sideDistX - data->algo->deltaDistX);
	else
		data->algo->perpWallDist = (data->algo->sideDistY - data->algo->deltaDistY);
	data->algo->lineHeight = (int)(data->cam_height / data->algo->perpWallDist);
	data->algo->drawStart = data->cam_height / 2 - data->algo->lineHeight / 2;
	data->algo->drawEnd = data->algo->lineHeight / 2 + data->cam_height / 2;
	if (data->algo->drawStart < 0)
		data->algo->drawStart = 0;
	if (data->algo->drawEnd >= data->cam_height)
		data->algo->drawEnd = data->cam_height - 1;
}

int	assign_color(t_data *data, int mapx, int mapy, int side)
{
	int	color;

	color = assemble_rgb(data->rgb);
	if (data->map->map_copy[mapy][mapx] == '1')
		color = assemble_rgb(data->rgb);
	if (side == 1)
		color = color / 2;
	return (color);
}

void	launch_ray(t_data *data)
{
	data->ray->camera_x = 2 * data->pos->x / (double)data->cam_length;
	data->ray->dirx = data->pos->dirx + data->pos->planex * data->ray->camera_x;
	data->ray->diry = data->pos->diry + data->pos->planey * data->ray->camera_x;
}

void	render_map(t_data *data, int x)
{
	int	y;
	int	color;
	int ciel_color = 0x87CEEB;
	int sol_color = 0x444444;

	color = assign_color(data, data->algo->mapX,
		data->algo->mapY, data->algo->side);
	y = 0;
	while (y < data->cam_height)
	{
		if (y < data->algo->drawStart)
			my_mlx_pixel_put(data, x, y, ciel_color);
		else if (y >= data->algo->drawStart && y <= data->algo->drawEnd)
			my_mlx_pixel_put(data, x, y, color);
		else
			my_mlx_pixel_put(data, x, y, sol_color);
		y++;
	}
}

void	get_coordinates(t_data *mlx, double *x, double *y)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (mlx->map->map_copy[i])
	{
		j = 0;
		while (mlx->map->map_copy[i][j])
		{
			if (mlx->map->map_copy[i][j] == 'N'
				|| mlx->map->map_copy[i][j] == 'S'
				|| mlx->map->map_copy[i][j] == 'E'
				|| mlx->map->map_copy[i][j] == 'W')
			{
				*x = (double)j;
				*y = (double)i;
			}
			j++;
		}
		i++;
	}
}

void	algo_init(t_data **data)
{
	(*data)->algo->deltaDistX = 0;
	(*data)->algo->deltaDistY = 0;
	(*data)->algo->drawEnd = 0;
	(*data)->algo->drawStart = 0;
	(*data)->algo->hit = 0;
	(*data)->algo->lineHeight = 0;
	(*data)->algo->mapX = 0;
	(*data)->algo->mapY = 0;
	(*data)->algo->perpWallDist = 0;
	(*data)->algo->side = 0;
	(*data)->algo->sideDistX = 0;
	(*data)->algo->sideDistY = 0;
	(*data)->algo->stepX = 0;
	(*data)->algo->stepY = 0;
}

void	draw_fov(t_data *mlx)
{
	int	col;

	col = 0;
	mlx->pos = malloc(sizeof(t_pos));
	mlx->pos->time = 0;
	mlx->pos->old_time = 0;
	get_coordinates(mlx, &mlx->pos->posx, &mlx->pos->posy);
	mlx->pos->dirx = -1;
	mlx->pos->diry = 0;
	mlx->pos->planex = 0;
	mlx->pos->planey = 0.66;
	mlx->pos->x = 0;
	mlx->pos->y = 0;
	mlx->ray = malloc(sizeof(t_ray));
	mlx->algo = malloc(sizeof(t_dda));
	while (col < mlx->cam_length)
	{
		mlx->ray->camera_x = 2 * col / (double)mlx->cam_length;
		mlx->ray->dirx = mlx->pos->dirx + mlx->pos->planex * mlx->ray->camera_x;
		mlx->ray->diry = mlx->pos->diry + mlx->pos->planey * mlx->ray->camera_x;
		algo_init(&mlx);
		calculate_triangles(mlx);
		render_map(mlx, col);
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
		col++;
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
		mlx->img = mlx_new_image(mlx->ptr, mlx->cam_length, mlx->cam_height);
		mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
		init_colors(mlx);
		mlx->win = mlx_new_window(mlx->ptr, mlx->cam_height,
			mlx->cam_length, "Bomboclaat");
		draw_fov(mlx);
		if (!mlx->win)
		{
			ft_putstr_fd("Error: Failed to create window\n", 2);
			mlx_loop_end(mlx->ptr);
		}
		mlx_key_hook(mlx->win, on_keypress, mlx);
		mlx_hook(mlx->win, 17, 0, free_all, mlx);
		mlx_loop(mlx->ptr);
		free_all(mlx);
	}
	return (0);
}
