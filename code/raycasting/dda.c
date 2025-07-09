/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:46:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/09 04:08:01 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	hit_loop(t_data *data)
{
	while (data->algo->hit == 0)
	{
		if (data->algo->sidedistx < data->algo->sidedisty)
		{
			data->algo->sidedistx += data->algo->deltadistx;
			data->algo->mapx += data->algo->stepx;
			data->algo->side = 0;
		}
		else
		{
			data->algo->sidedisty += data->algo->deltadisty;
			data->algo->mapy += data->algo->stepy;
			data->algo->side = 1;
		}
		if (data->map->map_copy[data->algo->mapy][data->algo->mapx] == '1')
			data->algo->hit = 1;
	}
}

void	assign_drawing_limits(t_data *data)
{
	if (data->algo->side == 0)
		data->algo->perpwalldist = (data->algo->sidedistx
				- data->algo->deltadistx);
	else
		data->algo->perpwalldist = (data->algo->sidedisty
				- data->algo->deltadisty);
	if (data->algo->perpwalldist < 0.0001)
		data->algo->perpwalldist = 0.0001;
	data->algo->lineheight = (int)(data->cam_height / data->algo->perpwalldist);
	data->algo->drawstart = data->cam_height / 2 - data->algo->lineheight / 2;
	data->algo->drawend = data->algo->lineheight / 2 + data->cam_height / 2;
	if (data->algo->drawstart < 0)
		data->algo->drawstart = 0;
	if (data->algo->drawend >= data->cam_height)
		data->algo->drawend = data->cam_height - 1;
}

void	texture_pixel(t_data *data)
{
	data->num = determine_texnum(data);
	if (data->algo->side == 0)
		data->algo->wallx = data->pos->posy + data->algo->perpwalldist
			* data->ray->diry;
	else
		data->algo->wallx = data->pos->posx + data->algo->perpwalldist
			* data->ray->dirx;
	data->algo->wallx -= floor((data->algo->wallx));
	if (data->algo->wallx < 0.0)
		data->algo->wallx = 0.0;
	if (data->algo->wallx > 1.0)
		data->algo->wallx = 1.0;
	data->texture[data->num].texx = (int)(data->algo->wallx
			* (double)data->texture[data->num].tw);
	if (data->algo->side == 0 && data->ray->dirx > 0)
		data->texture[data->num].texx = data->texture[data->num].tw
			- data->texture[data->num].texx - 1;
	if (data->algo->side == 1 && data->ray->diry < 0)
		data->texture[data->num].texx = data->texture[data->num].tw
			- data->texture[data->num].texx - 1;
	data->algo->step = 1.0 * data->texture[data->num].th
		/ data->algo->lineheight;
	data->texture[data->num].texpos = (data->algo->drawstart
			- data->cam_height / 2 + data->algo->lineheight / 2)
		* data->algo->step;
}

void	dda(t_data *data)
{
	data->algo->mapx = (int)data->pos->posx;
	data->algo->mapy = (int)data->pos->posy;
	init_delta(data);
	init_dist(data);
	hit_loop(data);
	assign_drawing_limits(data);
	texture_pixel(data);
}

void	launch_ray(t_data *data)
{
	data->ray->camera_x = 2 * data->pos->x / (double)data->cam_length;
	data->ray->dirx = data->pos->dirx + data->pos->planex * data->ray->camera_x;
	data->ray->diry = data->pos->diry + data->pos->planey * data->ray->camera_x;
}
