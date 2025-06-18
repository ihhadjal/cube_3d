/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/18 16:32:46 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

int	main(void)
{
	t_data	*mlx;
	void	*background;

	mlx = malloc(sizeof(t_data));
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 920, 640, "Bomboclaat");
	if (!mlx->win)
	{
		ft_putstr_fd("Error: Failed to create window\n", 2);
		mlx_loop_end(mlx->ptr);
	}
	background = mlx_xpm_file_to_image()
	mlx_key_hook(mlx->win, on_keypress, mlx);
	mlx_hook(mlx->win, 17, 0, free_dem_hoes, mlx);
	mlx_loop(mlx->ptr);
	free_dem_hoes(mlx);
	return (0);
}
