/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:26:24 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/09 03:55:13 by ilhasnao         ###   ########.fr       */
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
	return (0);
}

void	rotate(t_data *mlx, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == A)
	{
		olddirx = mlx->pos->dirx;
		mlx->pos->dirx = mlx->pos->dirx * cos(-RS)
			- mlx->pos->diry * sin(-RS);
		mlx->pos->diry = olddirx * sin(-RS) + mlx->pos->diry * cos(-RS);
		oldplanex = mlx->pos->planex;
		mlx->pos->planex = mlx->pos->planex * cos(-RS)
			- mlx->pos->planey * sin(-RS);
		mlx->pos->planey = oldplanex * sin(-RS) + mlx->pos->planey * cos(-RS);
	}
	else
	{
		olddirx = mlx->pos->dirx;
		mlx->pos->dirx = mlx->pos->dirx * cos(RS) - mlx->pos->diry * sin(RS);
		mlx->pos->diry = olddirx * sin(RS) + mlx->pos->diry * cos(RS);
		oldplanex = mlx->pos->planex;
		mlx->pos->planex = mlx->pos->planex * cos(RS) - mlx->pos->planey
			* sin(RS);
		mlx->pos->planey = oldplanex * sin(RS) + mlx->pos->planey * cos(RS);
	}
}

void	move_up_and_down(t_data **mlx, int keycode)
{
	int	mapx_plus;
	int	mapy_plus;
	int	mapx_down;
	int	mapy_down;

	mapx_plus = (int)((*mlx)->pos->posx + (*mlx)->pos->dirx * MOVESPEED);
	mapy_plus = (int)((*mlx)->pos->posy + (*mlx)->pos->diry * MOVESPEED);
	mapx_down = (int)((*mlx)->pos->posx - (*mlx)->pos->dirx * MOVESPEED);
	mapy_down = (int)((*mlx)->pos->posy - (*mlx)->pos->diry * MOVESPEED);
	if (keycode == W)
	{
		if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_plus] != '1')
			(*mlx)->pos->posx += (*mlx)->pos->dirx * MOVESPEED;
		if ((*mlx)->map->map_copy[mapy_plus][(int)((*mlx)->pos->posx)] != '1')
			(*mlx)->pos->posy += (*mlx)->pos->diry * MOVESPEED;
	}
	else
	{
		if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_down] != '1')
			(*mlx)->pos->posx -= (*mlx)->pos->dirx * MOVESPEED;
		if ((*mlx)->map->map_copy[mapy_down][(int)((*mlx)->pos->posx)] != '1')
			(*mlx)->pos->posy -= (*mlx)->pos->diry * MOVESPEED;
	}
}

int	move_player(t_data **mlx)
{
	if ((*mlx)->key_up)
		move_up_and_down(mlx, W);
	if ((*mlx)->key_right)
		rotate(*mlx, D);
	if ((*mlx)->key_left)
		rotate(*mlx, A);
	if ((*mlx)->key_down)
		move_up_and_down(mlx, S);
	(*mlx)->has_moved = true;
	loop((*mlx));
	mlx_put_image_to_window((*mlx)->ptr, (*mlx)->win, (*mlx)->img, 0, 0);
	return (0);
}
