/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:26:24 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/10 23:26:13 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

int	on_keypress(int keycode, t_data *mlx)
{
	if (keycode == ESC)
		mlx_loop_end(mlx->ptr);
	if (keycode == D)
		mlx->key_right = true;
	if (keycode == A)
		mlx->key_left = true;
	if (keycode == W)
		mlx->key_up = true;
	if (keycode == S)
		mlx->key_down = true;
	if (keycode == RIGHT)
		mlx->right = true;
	if (keycode == LEFT)
		mlx->left = true;
	return (0);
}

int	on_release(int keycode, t_data *mlx)
{
	if (keycode == D)
		mlx->key_right = false;
	if (keycode == A)
		mlx->key_left = false;
	if (keycode == W)
		mlx->key_up = false;
	if (keycode == S)
		mlx->key_down = false;
	if (keycode == RIGHT)
		mlx->right = false;
	if (keycode == LEFT)
		mlx->left = false;
	return (0);
}

int	move_player(t_data **mlx)
{
	if ((*mlx)->key_up)
		move_up(mlx);
	if ((*mlx)->key_right)
		move_right(mlx);
	if ((*mlx)->key_left)
		move_left(mlx);
	if ((*mlx)->right)
		rotate(*mlx, RIGHT);
	if ((*mlx)->left)
		rotate(*mlx, LEFT);
	if ((*mlx)->key_down)
		move_down(mlx);
	(*mlx)->has_moved = true;
	loop((*mlx));
	mlx_put_image_to_window((*mlx)->ptr, (*mlx)->win, (*mlx)->img, 0, 0);
	return (0);
}
