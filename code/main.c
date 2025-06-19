/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/19 11:36:24 by ihhadjal         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	*mlx;
	t_map	map;

	if (parsing(argc, argv, &map) == 0)
	{
		mlx = malloc(sizeof(t_data));
		mlx->ptr = mlx_init();
		mlx->win = mlx_new_window(mlx->ptr, 920, 640, "Bomboclaat");
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
