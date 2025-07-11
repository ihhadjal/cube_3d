/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles_n_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:59:43 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 23:53:49 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

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

t_color	*find_color(t_data *mlx, char c)
{
	int		i;
	int		j;
	char	**buffer;
	t_color	*color;

	j = 0;
	i = 0;
	color = malloc(sizeof(t_color));
	while (mlx->map->before_map[i][0] != c)
		i++;
	buffer = ft_split(&mlx->map->before_map[i++][1], ',');
	color->r = ft_atoi(buffer[0]);
	color->g = ft_atoi(buffer[1]);
	color->b = ft_atoi(buffer[2]);
	while (buffer[j])
	{
		free(buffer[j]);
		j++;
	}
	free(buffer);
	return (color);
}
