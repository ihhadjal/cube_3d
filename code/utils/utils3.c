/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:18:41 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/07/09 19:32:57 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	check_paths(char **before_map)
{
	char	**split_str;
	int		i;

	i = 0;
	while (before_map[i])
	{
		split_str = ft_split(before_map[i], 32);
		if (!ft_strcmp(split_str[0], "NO") || !ft_strcmp(split_str[0], "SO")
			|| !ft_strcmp(split_str[0], "EA") || !ft_strcmp(split_str[0], "WE"))
		{
			if (open(split_str[1], O_RDONLY) == -1)
			{
				printf("error: path not found\n");
				free_map(split_str);
				exit(1);
			}
			if (check_xpm(split_str[1]) == 1)
			{
				printf("error: xpm only\n");
				exit(1);
			}
		}
		check_c_f(split_str);
		i++;
	}
}

void	check_instructions(char **before_map)
{
	int		i;
	int		c;
	char	**split_str;

	i = 0;
	c = 0;
	doubles_check(before_map);
	while (before_map[i])
	{
		split_str = ft_split(before_map[i], 32);
		if (!ft_strcmp(split_str[0], "NO") || !ft_strcmp(split_str[0], "SO")
			|| !ft_strcmp(split_str[0], "EA") || !ft_strcmp(split_str[0], "WE")
			|| !ft_strcmp(split_str[0], "F") || !ft_strcmp(split_str[0], "C"))
			c++;
		free_map(split_str);
		i++;
	}
	if (c != 6)
	{
		printf("error: wrong map instructions\n");
		exit(1);
	}
}

void	free_maps(t_map *map)
{
	if (map->map_copy)
		free_map(map->map_copy);
	if (map->skip_map)
		free_map(map->skip_map);
	if (map->before_map)
		free_map(map->before_map);
	if (map->after_map)
		free_map(map->after_map);
	if (map->rectangular_map)
		free_map(map->rectangular_map);
	if (map->dummy_map)
		free_map(map->dummy_map);
	if (map->trim_map)
		free_map(map->trim_map);
}

void	check_doubles(char **map_copy)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map_copy[i])
	{
		if (ft_strchr(map_copy[i], 'S') || ft_strchr(map_copy[i], 'E')
			|| ft_strchr(map_copy[i], 'N') || ft_strchr(map_copy[i], 'W'))
			c++;
		if (c > 1)
		{
			printf("error: player has two positions\n");
			exit(1);
		}
		i++;
	}
}

void	find_position(char **map_copy)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'N' || map_copy[i][j] == 'E'
				|| map_copy[i][j] == 'S' || map_copy[i][j] == 'W')
			{
				x = j;
				y = i;
			}
			j++;
		}
		i++;
	}
	error(x, y);
}
