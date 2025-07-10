/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:02:47 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/07/10 15:08:26 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	doubles_check(char **before_map)
{
	t_map	map;
	int		i;
	char	**split;

	map = (t_map){0};
	i = 0;
	while (before_map[i])
	{
		split = ft_split(before_map[i], ' ');
		if (!ft_strcmp(split[0], "NO"))
			map.no++;
		if (!ft_strcmp(split[0], "SO"))
			map.so++;
		if (!ft_strcmp(split[0], "EA"))
			map.ea++;
		if (!ft_strcmp(split[0], "WE"))
			map.we++;
		free_map(split);
		i++;
	}
	if (map.no > 1 || map.so > 1 || map.ea > 1 || map.we > 1)
	{
		ft_error("error: coordinates not found\n", before_map);
		exit(1);
	}
}

void	check2(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c > 1)
	{
		ft_error("error: player has two positions", map);
		exit(1);
	}
}

int	condition(int c, t_map *map)
{
	if (c == 6)
	{
		free(map->trim_str);
		return (1);
	}
	return (0);
}
