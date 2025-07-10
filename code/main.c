/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:02 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 16:26:10 by hasnawww         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/cube.h"

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
		mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
				&mlx->line_length, &mlx->endian);
		mlx->win = mlx_new_window(mlx->ptr, mlx->cam_length,
				mlx->cam_height, "Bomboclaat");
		draw_fov(mlx);
		printf("height = %d\n", mlx->map->height);
		if (!mlx->win)
			mlx_loop_end(mlx->ptr);
		mlx_hook(mlx->win, 2, 1L << 0, on_keypress, mlx);
		mlx_hook(mlx->win, 3, 1L << 1, on_release, mlx);
		mlx_loop_hook(mlx->ptr, move_player, &mlx);
		mlx_hook(mlx->win, 17, 0, free_all1, mlx);
		mlx_loop(mlx->ptr);
		free_all1(mlx);
	}
	return (0);
}
