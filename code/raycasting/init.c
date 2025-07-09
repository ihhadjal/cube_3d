/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:28:43 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/09 18:37:38 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	init_texture(t_text *texture, t_data *mlx, char *str)
{
	int	i;

	i = 0;
	while (mlx->map->before_map[i])
	{
		if (!ft_strncmp(mlx->map->before_map[i], str, 2))
			break ;
		i++;
	}
	texture->path = ft_strchr(mlx->map->before_map[i], '.');
	texture->th = 0;
	texture->tw = 0;
	texture->texx = 0;
	texture->texy = 0;
	texture->texpos = 0;
}

void	my_mlx_init(t_data *mlx)
{
	mlx->ptr = mlx_init();
	mlx->num = 0;
	mlx->has_moved = false;
	mlx->ceiling = find_color(mlx, 'C');
	mlx->floor = find_color(mlx, 'F');
	mlx->texture = malloc(sizeof(t_text) * 5);
	init_texture(&mlx->texture[0], mlx, "NO");
	init_texture(&mlx->texture[2], mlx, "WE");
	init_texture(&mlx->texture[3], mlx, "EA");
	init_texture(&mlx->texture[1], mlx, "SO");
	mlx->texture[4].path = NULL;
	assign_texture(mlx);
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
