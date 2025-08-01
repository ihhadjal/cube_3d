/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:31:17 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 23:54:29 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	assemble_rgb(t_color *c)
{
	return (c->r << 16 | c->g << 8 | c->b);
}

int	determine_texnum(t_data *data)
{
	if (data->algo->side == 0)
	{
		if (data->ray->dirx < 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (data->ray->diry < 0)
			return (SO);
		else
			return (NO);
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

void	assign_texture(t_data *mlx)
{
	int	i;

	i = 0;
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
}
