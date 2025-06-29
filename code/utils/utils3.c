/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:18:41 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/29 18:26:08 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	check_paths(char **before_map)
{
	char	**split_str;
	int		i;

	i = 0;
	while (before_map[i] && i < 4)
	{
		split_str = ft_split(before_map[i], 32);
		if (open(split_str[1], O_RDONLY) == -1)
		{
			printf("error: path not found\n");
			free_map(split_str);
			exit(1);
		}
		free_map(split_str);
		i++;
	}
	while (before_map[i])
	{
		split_str = ft_split(before_map[i], 32);
		if (check_nums(split_str[1]) == 1)
		{
			printf("error: RGB out of range\n");
			free_map(split_str);
			exit(1);
		}
		free_map(split_str);
		i++;
	}
}

void	check_instructions(char **map_copy)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	while (map_copy[i])
	{
		if (ft_strstr(map_copy[i], "NO") || ft_strstr(map_copy[i], "SO")
			|| ft_strstr(map_copy[i], "WE") || ft_strstr(map_copy[i], "EA")
			|| ft_strchr(map_copy[i], 'C') || ft_strchr(map_copy[i], 'F'))
			f++;
		i++;
	}
	if (f != 6)
	{
		printf("error: instructions are missing\n");
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