/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:28:43 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/09 03:58:17 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	init_text(t_data *mlx)
{
	int		i;

	i = 0;
	mlx->texture = NULL;
	mlx->texture = malloc(sizeof(t_text) * 5);
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

	i = 0;
	mlx->ptr = mlx_init();
	mlx->num = 0;
	mlx->has_moved = false;
	init_text(mlx);
	mlx->ceiling = find_color(mlx, 'C');
	mlx->floor = find_color(mlx, 'F');
	while (mlx->texture[i].path)
	{
		mlx->texture[i].tex = mlx_xpm_file_to_image(mlx->ptr,
				mlx->texture[i].path, &mlx->texture[i].tw, &mlx->texture[i].th);
		if (!mlx->texture[i].tex)
			mlx_loop_end(mlx->ptr);
		mlx->texture[i].tex_addr = mlx_get_data_addr(mlx->texture[i].tex,
				&mlx->texture[i].bpp, &mlx->texture[i].line_length,
				&mlx->texture[i].endian);
		if (!mlx->texture[i].tex_addr)
			mlx_loop_end(mlx->ptr);
		i++;
	}
	mlx->cam_height = 900;
	mlx->cam_length = 900;
}

void	algo_init(t_data **data)
{
	(*data)->algo->deltadistx = 0;
	(*data)->algo->deltadisty = 0;
	(*data)->algo->drawend = 0;
	(*data)->algo->drawstart = 0;
	(*data)->algo->hit = 0;
	(*data)->algo->lineheight = 0;
	(*data)->algo->mapx = 0;
	(*data)->algo->mapy = 0;
	(*data)->algo->perpwalldist = 0;
	(*data)->algo->side = 0;
	(*data)->algo->sidedistx = 0;
	(*data)->algo->sidedisty = 0;
	(*data)->algo->stepx = 0;
	(*data)->algo->stepy = 0;
	(*data)->algo->wallx = 0;
	(*data)->algo->step = 0;
}

void	init_delta(t_data *data)
{
	if (data->ray->dirx != 0)
	{
		data->algo->deltadistx = fabs(1 / data->ray->dirx);
	}
	else
		data->algo->deltadistx = 1e30;
	if (data->ray->diry != 0)
		data->algo->deltadisty = fabs(1 / data->ray->diry);
	else
		data->algo->deltadisty = 1e30;
}

void	init_dist(t_data *data)
{
	if (data->ray->dirx < 0)
	{
		data->algo->stepx = -1;
		data->algo->sidedistx = (data->pos->posx - data->algo->mapx)
			* data->algo->deltadistx;
	}
	else
	{
		data->algo->stepx = 1;
		data->algo->sidedistx = (data->algo->mapx + 1.0 - data->pos->posx)
			* data->algo->deltadistx;
	}
	if (data->ray->diry < 0)
	{
		data->algo->stepy = -1;
		data->algo->sidedisty = (data->pos->posy - data->algo->mapy)
			* data->algo->deltadisty;
	}
	else
	{
		data->algo->stepy = 1;
		data->algo->sidedisty = (data->algo->mapy + 1.0 - data->pos->posy)
			* data->algo->deltadisty;
	}
}
