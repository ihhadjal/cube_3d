/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:25:54 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/11 00:10:44 by ilhasnao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	rotate(t_data *mlx, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == LEFT)
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

void	move_up(t_data **mlx)
{
	int	mapx_plus;
	int	mapy_plus;

	if (MOVESPEED < 0.5)
	{
		mapx_plus = (int)((*mlx)->pos->posx
				+ (*mlx)->pos->dirx * 15 * MOVESPEED);
		mapy_plus = (int)((*mlx)->pos->posy
				+ (*mlx)->pos->diry * 15 * MOVESPEED);
	}
	else
	{
		mapx_plus = (int)((*mlx)->pos->posx + (*mlx)->pos->dirx * MOVESPEED);
		mapy_plus = (int)((*mlx)->pos->posy + (*mlx)->pos->diry * MOVESPEED);
	}
	if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_plus] != '1')
		(*mlx)->pos->posx += (*mlx)->pos->dirx * MOVESPEED;
	if ((*mlx)->map->map_copy[mapy_plus][(int)((*mlx)->pos->posx)] != '1')
		(*mlx)->pos->posy += (*mlx)->pos->diry * MOVESPEED;
}

void	move_down(t_data **mlx)
{
	int	mapx_down;
	int	mapy_down;

	if (MOVESPEED < 0.5)
	{
		mapx_down = (int)((*mlx)->pos->posx
				- (*mlx)->pos->dirx * 15 * MOVESPEED);
		mapy_down = (int)((*mlx)->pos->posy
				- (*mlx)->pos->diry * 15 * MOVESPEED);
	}
	else
	{
		mapx_down = (int)((*mlx)->pos->posx - (*mlx)->pos->dirx * MOVESPEED);
		mapy_down = (int)((*mlx)->pos->posy - (*mlx)->pos->diry * MOVESPEED);
	}
	if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_down] != '1')
		(*mlx)->pos->posx -= (*mlx)->pos->dirx * MOVESPEED;
	if ((*mlx)->map->map_copy[mapy_down][(int)((*mlx)->pos->posx)] != '1')
		(*mlx)->pos->posy -= (*mlx)->pos->diry * MOVESPEED;
}

void	move_right(t_data **mlx)
{
	int	mapx_plus;
	int	mapy_plus;

	if (MOVESPEED < 0.5)
	{
		mapx_plus = (int)((*mlx)->pos->posx
				+ (*mlx)->pos->planex * 15 * MOVESPEED);
		mapy_plus = (int)((*mlx)->pos->posy
				+ (*mlx)->pos->planey * 15 * MOVESPEED);
	}
	else
	{
		mapx_plus = (int)((*mlx)->pos->posx + (*mlx)->pos->planex * MOVESPEED);
		mapy_plus = (int)((*mlx)->pos->posy + (*mlx)->pos->planey * MOVESPEED);
	}
	if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_plus] != '1')
		(*mlx)->pos->posx += (*mlx)->pos->planex * MOVESPEED;
	if ((*mlx)->map->map_copy[mapy_plus][(int)((*mlx)->pos->posx)] != '1')
		(*mlx)->pos->posy += (*mlx)->pos->planey * MOVESPEED;
}

void	move_left(t_data **mlx)
{
	int	mapx_down;
	int	mapy_down;

	if (MOVESPEED < 0.5)
	{
		mapx_down = (int)((*mlx)->pos->posx
				- (*mlx)->pos->planex * 15 * MOVESPEED);
		mapy_down = (int)((*mlx)->pos->posy
				- (*mlx)->pos->planey * 15 * MOVESPEED);
	}
	else
	{
		mapx_down = (int)((*mlx)->pos->posx - (*mlx)->pos->planex * MOVESPEED);
		mapy_down = (int)((*mlx)->pos->posy - (*mlx)->pos->planey * MOVESPEED);
	}
	if ((*mlx)->map->map_copy[(int)((*mlx)->pos->posy)][mapx_down] != '1')
		(*mlx)->pos->posx -= (*mlx)->pos->planex * MOVESPEED;
	if ((*mlx)->map->map_copy[mapy_down][(int)((*mlx)->pos->posx)] != '1')
		(*mlx)->pos->posy -= (*mlx)->pos->planey * MOVESPEED;
}
