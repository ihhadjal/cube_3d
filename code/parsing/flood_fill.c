/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:27:28 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/21 13:01:36 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	find_starting_position(char **rec_map, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->start_x = -1;
	map->start_y = -1;
	while (rec_map[i])
	{
		j = 0;
		while (rec_map[i][j])
		{
			if (rec_map[i][j] == 'N' || rec_map[i][j] == 'S'
				|| rec_map[i][j] == 'W' || rec_map[i][j] == 'E')
			{
				map->start_x = j;
				map->start_y = i;
			}
			j++;
		}
		i++;
	}
	if (map->start_x == -1 || map->start_y == -1)
		ft_error("error: no starting point found\n", rec_map);
	calculate_height(rec_map, map);
	flood_fill(rec_map, map->start_x, map->start_y, map);
}
void	calculate_height(char **rec_map, t_map *map)
{
	int	i;

	i = 0;
	map->length = find_biggest_len(rec_map);
	while (rec_map[i])
	{
		map->height = i;
		i++;
	}
}
void	flood_fill(char **rec_map, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->length || y >= map->height
		|| ft_strchr("F V", rec_map[y][x]))
		return ;
	rec_map[y][x] = 'F';
	flood_fill(rec_map, x + 1, y, map);
	flood_fill(rec_map, x - 1, y, map);
	flood_fill(rec_map, x, y + 1, map);
	flood_fill(rec_map, x, y - 1, map);
}
