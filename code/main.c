/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/08 17:57:32 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/cube.h"

int	free_all1(t_data *mlx)
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

int get_texture_pixel(text *tex, int x, int y)
{
	char *pixel = tex->tex_addr + (y * tex->line_length + x * (tex->bpp / 8));
	return *(unsigned int*)pixel;
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

int	on_keypress(int keycode, t_data *mlx)
{
	if (keycode == ESC)
		mlx_loop_end(mlx->ptr);
	if (keycode == D)
		mlx->key_right = true;
	if (keycode == A)
		mlx->key_left = true;
	if (keycode == W)
		mlx->key_up = true;
	if (keycode == S)
		mlx->key_down = true;
	return (0);
}

int	on_release(int keycode, t_data *mlx)
{
	if (keycode == D)
		mlx->key_right = false;
	if (keycode == A)
		mlx->key_left = false;
	if (keycode == W)
		mlx->key_up = false;
	if (keycode == S)
		mlx->key_down = false;
	return (0);
}

void	rotate(t_data **mlx, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == A)
	{
		olddirx = (*mlx)->pos->dirx;
		(*mlx)->pos->dirx = (*mlx)->pos->dirx * cos(-rotspeed) - (*mlx)->pos->diry * sin(-rotspeed);
		(*mlx)->pos->diry = olddirx * sin(-rotspeed) + (*mlx)->pos->diry * cos(-rotspeed);
		oldplanex = (*mlx)->pos->planex;
		(*mlx)->pos->planex = (*mlx)->pos->planex * cos(-rotspeed) - (*mlx)->pos->planey * sin(-rotspeed);
		(*mlx)->pos->planey = oldplanex * sin(-rotspeed) + (*mlx)->pos->planey * cos(-rotspeed);
	}
	else
	{
		olddirx = (*mlx)->pos->dirx;
		(*mlx)->pos->dirx = (*mlx)->pos->dirx * cos(rotspeed) - (*mlx)->pos->diry * sin(rotspeed);
		(*mlx)->pos->diry = olddirx * sin(rotspeed) + (*mlx)->pos->diry * cos(rotspeed);
		oldplanex = (*mlx)->pos->planex;
		(*mlx)->pos->planex = (*mlx)->pos->planex * cos(rotspeed) - (*mlx)->pos->planey * sin(rotspeed);
		(*mlx)->pos->planey = oldplanex * sin(rotspeed) + (*mlx)->pos->planey * cos(rotspeed);
	}
}

void	move_up_and_down(t_data **mlx, int keycode)
{
	int	mapX_plus;
	int	mapY_plus;
	int	mapX_down;
	int	mapY_down;

	mapX_plus = (int)((*mlx)->pos->posx + (*mlx)->pos->dirx * movespeed);
	mapY_plus = (int)((*mlx)->pos->posy + (*mlx)->pos->diry * movespeed);
	mapX_down = (int)((*mlx)->pos->posx - (*mlx)->pos->dirx * movespeed);
	mapY_down = (int)((*mlx)->pos->posy - (*mlx)->pos->diry * movespeed);
	if (keycode == W)
	{
		if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapX_plus] != '1')
			(*mlx)->pos->posx += (*mlx)->pos->dirx * movespeed;
		if ((*mlx)->map->map_copy[mapY_plus][(int)((*mlx)->pos->posx)] != '1')
			(*mlx)->pos->posy += (*mlx)->pos->diry * movespeed;
	}
	else
	{
		if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapX_down] != '1')
			(*mlx)->pos->posx -= (*mlx)->pos->dirx * movespeed;
		if ((*mlx)->map->map_copy[mapY_down][(int)((*mlx)->pos->posx)] != '1')
			(*mlx)->pos->posy -= (*mlx)->pos->diry * movespeed;
	}
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

int	determine_texnum(t_data *data)
{
	if (data->algo->side == 0)
	{
		if (data->ray->dirx < 0)
			return (NO);
		else
			return (SO);
	}
	else
	{
		if (data->ray->diry < 0)
			return (EA);
		else
			return (WE);
	}
}

void	calculate_triangles(t_data *data)
{
	data->algo->mapX = (int)data->pos->posx;
	data->algo->mapY = (int)data->pos->posy;
	if (data->ray->dirx != 0)
	{
		data->algo->deltaDistX = fabs(1 / data->ray->dirx);
	}
	else
		data->algo->deltaDistX = 1e30;
	if (data->ray->diry != 0)
		data->algo->deltaDistY = fabs(1 / data->ray->diry);
	else
		data->algo->deltaDistY = 1e30;
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
	{
		data->algo->perpWallDist = (data->algo->sideDistX - data->algo->deltaDistX);
		// if (data->algo->sideDistX == data->algo->deltaDistX)
		// 	data->algo->perpWallDist = 1;
	}
	else
	{
		data->algo->perpWallDist = (data->algo->sideDistY - data->algo->deltaDistY);
		// if (data->algo->sideDistY == data->algo->deltaDistY)
		// 	data->algo->perpWallDist = 1;
	}
	data->algo->lineHeight = (int)(data->cam_height / data->algo->perpWallDist);
	data->algo->drawStart = data->cam_height / 2 - data->algo->lineHeight / 2;
	data->algo->drawEnd = data->algo->lineHeight / 2 + data->cam_height / 2;
	if (data->algo->drawStart < 0)
		data->algo->drawStart = 0;
	if (data->algo->drawEnd >= data->cam_height)
		data->algo->drawEnd = data->cam_height - 1;
	data->num = determine_texnum(data);
	// printf("%d\n", data->num);
	// sleep(1);
	if (data->algo->side == 0)
		data->algo->wallx = data->pos->posy + data->algo->perpWallDist * data->ray->diry;
	else
		data->algo->wallx = data->pos->posx + data->algo->perpWallDist * data->ray->dirx;
	data->algo->wallx -= floor((data->algo->wallx));
	if (data->algo->wallx < 0.0)
		data->algo->wallx = 0.0;
	if (data->algo->wallx > 1.0)
		data->algo->wallx = 1.0;
	data->texture[data->num].texx = (int)(data->algo->wallx * (double)data->texture[data->num].tw);
	if (data->algo->side == 0 && data->ray->dirx > 0)
		data->texture[data->num].texx = data->texture[data->num].tw - data->texture[data->num].texx - 1;
	if (data->algo->side == 1 && data->ray->diry < 0)
		data->texture[data->num].texx = data->texture[data->num].tw - data->texture[data->num].texx - 1;
	data->algo->step = 1.0 * data->texture[data->num].th / data->algo->lineHeight;
	data->texture[data->num].texpos = (data->algo->drawStart - data->cam_height / 2 + data->algo->lineHeight / 2) * data->algo->step;
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
	int	ciel_color = 0x0024ff;
	int	sol_color = 0xFF00b6;
	int	d;
	// color = assign_color(data, data->algo->mapX,
	// 	data->algo->mapY, data->algo->side);
	y = 0;
	while (y < data->cam_height)
	{
		if (y < data->algo->drawStart)
			my_mlx_pixel_put(data, x, y, ciel_color);
		else if (y >= data->algo->drawStart && y <= data->algo->drawEnd)
		{
			d = y * 256 - data->cam_height * 128 + data->algo->lineHeight * 128;
			data->texture[data->num].texy = ((d * data->texture[data->num].th) / data->algo->lineHeight) / 256;
			data->texture[data->num].texpos += data->algo->step;
			if (data->num < 0 || data->num >= 4)
				return;
			if (data->texture[data->num].texx < 0 || data->texture[data->num].texx >= data->texture[data->num].tw)
				return;
			if (data->texture[data->num].texy < 0 || data->texture[data->num].texy >= data->texture[data->num].th)
				return;
			color = *(unsigned int *)(data->texture[data->num].tex_addr 
		+ (data->texture[data->num].texy
				* data->texture[data->num].line_length 
					+ data->texture[data->num].texx 
					* (data->texture[data->num].bpp / 8)));
			if (data->algo->side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(data, x, y, color);
		}
		else
			my_mlx_pixel_put(data, x, y, sol_color);
		y++;
	}
}

void	get_coordinates(t_data *mlx, double *x, double *y)
{
	int	i;
	int	j;

	i = 0;
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
	(*data)->algo->wallx = 0;
	(*data)->algo->step = 0;
}

void	drawinggg(t_data *mlx, int col, int j, int color, int code)
{
	int	i = 0;
	int o = 0;
	while (i < code)
	{
		o = 0;
		while(o < code)
		{
			my_mlx_pixel_put(mlx, col * 64 + o, j * 64 + i, color);
			o++;
		}
		i++;
	}
}

void rend_map(t_data *mlx)
{
	int i = 0;
	int j = 0;
	int color;
	int ciel_color = 0x87CEEB;
	int sol_color = 0xFF00b6;

	color = assemble_rgb(mlx->rgb);
	while (mlx->map->map_copy[i])
	{
		j = 0;
		while (mlx->map->map_copy[i][j])
		{
			if (mlx->map->map_copy[i][j] == '1')
				drawinggg(mlx, j, i, color, 64);
			else if (mlx->map->map_copy[i][j] == '0')
				drawinggg(mlx, j, i, sol_color, 64);
			else if (mlx->map->map_copy[i][j] == 'N')
				drawinggg(mlx, j, i, ciel_color, 64);
			j++;
		}
		i++;
	}
}

void	ray_trace(t_data *data)
{
	double	ray_x = data->pos->posx;
	double	ray_y = data->pos->posy;
	double	reference = movespeed;
	int		hit = 0;

	while (!hit)
	{
		int	mapX = (int)ray_x;
		int	mapY = (int)ray_y;
		if (data->map->map_copy[mapY][mapX] == '1')
			hit = 1;
		my_mlx_pixel_put(data, ray_x * 64, ray_y * 64, 0x00FF00);
		ray_x += data->ray->dirx * reference;
		ray_y += data->ray->diry * reference;
	}
}

void	loop(t_data *mlx)
{
	int	col;

	col = 0;
	while (col < mlx->cam_length)
	{
		mlx->ray->camera_x = 2 * col / (double)mlx->cam_length - 1;
		mlx->ray->dirx = mlx->pos->dirx + mlx->pos->planex * mlx->ray->camera_x;
		mlx->ray->diry = mlx->pos->diry + mlx->pos->planey * mlx->ray->camera_x;
		algo_init(&mlx);
		calculate_triangles(mlx);
		render_map(mlx, col);
		// ray_trace(mlx);
		col++;
	}
}

void	assign_angle(t_data *mlx, int i, int j)
{
	if (mlx->map->map_copy[i][j] == 'N')
	{
		mlx->pos->dirx = 0;
		mlx->pos->diry = -1;
		mlx->pos->planex = 0.66;
	}
	else if (mlx->map->map_copy[i][j] == 'S')
	{
		mlx->pos->dirx = 0;
		mlx->pos->diry = 1;
		mlx->pos->planex = 0.66;
	}
	else if (mlx->map->map_copy[i][j] == 'W')
	{
		mlx->pos->dirx = -1;
		mlx->pos->diry = 0;
		mlx->pos->planey = 0.66;
	}
	else if (mlx->map->map_copy[i][j] == 'E')
	{
		mlx->pos->dirx = 1;
		mlx->pos->diry = 0;
		mlx->pos->planey = 0.66;
	}
}

void	determine_angle(t_data *mlx)
{
	int	i;
	int	j;

	i = 8;
	j = 0;
	while (mlx->map->map_copy[i])
	{
		j = 0;
		while (mlx->map->map_copy[i][j])
		{
			assign_angle(mlx, i, j);
			j++;
		}
		i++;
	}
}

void	draw_fov(t_data *mlx)
{
	mlx->pos = malloc(sizeof(t_pos));
	mlx->pos->time = 0;
	mlx->pos->old_time = 0;
	get_coordinates(mlx, &mlx->pos->posx, &mlx->pos->posy);
	mlx->pos->planex = 0;
	mlx->pos->planey = 0;
	determine_angle(mlx);
	mlx->pos->x = 0;
	mlx->pos->y = 0;
	mlx->key_up = false;
	mlx->key_down = false;
	mlx->key_left = false;
	mlx->key_right = false;
	mlx->ray = malloc(sizeof(t_ray));
	mlx->algo = malloc(sizeof(t_dda));
	// rend_map(mlx);
	loop(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

int	move_player(t_data **mlx)
{
	if ((*mlx)->key_up)
		move_up_and_down(mlx, W);
	if ((*mlx)->key_right)
		rotate(mlx, D);
	if ((*mlx)->key_left)
		rotate(mlx, A);
	if ((*mlx)->key_down)
		move_up_and_down(mlx, S);
	// rend_map((*mlx));
	loop((*mlx));
	mlx_put_image_to_window((*mlx)->ptr, (*mlx)->win, (*mlx)->img, 0, 0);
	return (0);
}

void	init_text(t_data *mlx)
{
	int		i;

	i = 0;
	mlx->texture = malloc(sizeof(text) * 5);
	while (mlx->map->before_map[i] && i < 4)
	{
		mlx->texture[i].path = ft_strchr(mlx->map->before_map[i], '.');
		mlx->texture[i].th = 0;
		mlx->texture[i].tw = 0;
		mlx->texture[i].texx = 0;
		mlx->texture[i].texy = 0;
		mlx->texture[i].texpos = 0;
		i++;
	}
	mlx->texture[4].path = NULL;
}

void	my_mlx_init(t_data *mlx)
{
	int	i;
	// int	j;

	// j = 0;
	i = 0;
	mlx->ptr = mlx_init();
	mlx->num = 0;
	init_text(mlx);
	// mlx->buffer = malloc(mlx->cam_height + 1 * sizeof(u_int32_t*));
	// while (j < mlx->cam_height)
	// {
	// 	mlx->buffer[j] = malloc(mlx->cam_length * sizeof(u_int32_t));
	// }
	while (mlx->texture[i].path)
	{
		mlx->texture[i].tex = mlx_xpm_file_to_image(mlx->ptr, mlx->texture[i].path, 
			&mlx->texture[i].tw, &mlx->texture[i].th);
		if (!mlx->texture[i].tex)
		{
			printf("Erreur : texture mur introuvable\n");
			exit(1);
		}
		mlx->texture[i].tex_addr = mlx_get_data_addr(mlx->texture[i].tex, &mlx->texture[i].bpp,
			&mlx->texture[i].line_length, &mlx->texture[i].endian);
		if (!mlx->texture[i].tex_addr)
		{
			printf("Erreur : récupération adresse texture mur nord impossible\n");
			exit(1);
		}
		i++;
	}
	mlx->cam_height = 900;
	mlx->cam_length = 900;
}

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_map	map;

	if (parsing(argc, argv, &map) == 0)
	{
		mlx = malloc(sizeof(t_data));
		mlx->map = &map;
		my_mlx_init(mlx);
		mlx->img = mlx_new_image(mlx->ptr, mlx->cam_length, mlx->cam_height);
		mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_length, &mlx->endian);
		init_colors(mlx);
		mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length ,
			mlx->cam_height, "Bomboclaat");
		draw_fov(mlx);
		if (!mlx->win)
		{
			ft_putstr_fd("Error: Failed to create window\n", 2);
			mlx_loop_end(mlx->ptr);
		}
		mlx_hook(mlx->win, 2, 1L<<0, on_keypress, mlx);
		mlx_hook(mlx->win, 3, 1L<<1, on_release, mlx);
		mlx_loop_hook(mlx->ptr, move_player, &mlx);
		mlx_hook(mlx->win, 17, 0, free_all1, mlx);
		mlx_loop(mlx->ptr);
		free_all1(mlx);
		free_maps(&map);
	}
	return (0);
}
