/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:34:00 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 14:39:05 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	free_mlx(t_data *mlx)
{
	if (mlx->pos)
		free(mlx->pos);
	if (mlx->ray)
		free(mlx->ray);
	if (mlx->algo)
		free(mlx->algo);
	if (mlx->texture)
		free(mlx->texture);
	if (mlx->ceiling)
		free(mlx->ceiling);
	if (mlx->floor)
		free(mlx->floor);
}

int	free_all1(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->texture[i].path)
	{
		if (mlx->texture[i].tex)
			mlx_destroy_image(mlx->ptr, mlx->texture[i].tex);
		i++;
	}
	free_mlx(mlx);
	if (mlx->img)
		mlx_destroy_image(mlx->ptr, mlx->img);
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
