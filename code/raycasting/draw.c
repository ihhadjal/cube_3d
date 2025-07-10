/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:55:38 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 23:49:57 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	draw_fov(t_data *mlx)
{
	mlx->pos = malloc(sizeof(t_pos));
	mlx->pos->time = 0;
	mlx->pos->old_time = 0;
	get_coordinates(mlx, &mlx->pos->posx, &mlx->pos->posy);
	mlx->pos->posx += 0.1;
	mlx->pos->posy += 0.1;
	mlx->pos->planex = 0;
	mlx->pos->planey = 0;
	determine_angle(mlx);
	mlx->pos->x = 0;
	mlx->pos->y = 0;
	mlx->key_up = false;
	mlx->key_down = false;
	mlx->key_left = false;
	mlx->key_right = false;
	mlx->right = false;
	mlx->left = false;
	mlx->ray = malloc(sizeof(t_ray));
	mlx->algo = malloc(sizeof(t_dda));
	loop(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

void	drawing_condition(t_data *data, int *d, int y, int *color)
{
	*d = y * 256 - data->cam_height * 128 + data->algo->lineheight * 128;
	data->texture[data->num].texy = ((*d * data->texture[data->num].th)
			/ data->algo->lineheight) / 256;
	data->texture[data->num].texpos += data->algo->step;
	if (data->has_moved)
	{
		if (data->num < 0 || data->num >= 4)
			return ;
		if (data->texture[data->num].texx < 0
			|| data->texture[data->num].texx > data->texture[data->num].tw)
			return ;
		if (data->texture[data->num].texy < 0
			|| data->texture[data->num].texy > data->texture[data->num].th)
			return ;
	}
	*color = *(unsigned int *)(data->texture[data->num].tex_addr
			+ (data->texture[data->num].texy
				* data->texture[data->num].line_length
				+ data->texture[data->num].texx
				* (data->texture[data->num].bpp / 8)));
}

void	render_map(t_data *data, int x)
{
	int	y;
	int	color;
	int	ciel_color;
	int	sol_color;
	int	d;

	ciel_color = assemble_rgb(data->ceiling);
	sol_color = assemble_rgb(data->floor);
	y = 0;
	while (y < data->cam_height)
	{
		if (y < data->algo->drawstart)
			my_mlx_pixel_put(data, x, y, ciel_color);
		else if (y >= data->algo->drawstart && y <= data->algo->drawend)
		{
			drawing_condition(data, &d, y, &color);
			if (data->algo->side == 1)
				color = (color >> 1) & 8355711;
			my_mlx_pixel_put(data, x, y, color);
		}
		else
			my_mlx_pixel_put(data, x, y, sol_color);
		y++;
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
		dda(mlx);
		render_map(mlx, col);
		col++;
	}
}
