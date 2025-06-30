/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skiplines_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:22:31 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/30 16:24:57 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

char	**skip_lines(char **map_copy, char *argv, t_map *map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	map->before_map = malloc(sizeof(char *) * 7);
	while (map_copy[i])
	{
		map->trim_str = ft_strtrim(map_copy[i], " \t\n\v\f\r");
		if (map->trim_str[0] != '\0')
		{
			map->before_map[j] = map_copy[i];
			j++;
			c++;
		}
		if (c == 6)
			break ;
		i++;
		free(map->trim_str);
	}
	map->before_map[j] = NULL;
	after_copy_logic(map, i, argv, map_copy);
	return (map->after_map);
}

void	after_copy_logic(t_map *map, int i, char *argv, char **map_copy)
{
	int	j;

	map->after_map = malloc(sizeof(char *) * ((count_lines(argv) - 6) + 1));
	j = 0;
	i++;
	while (map_copy[i])
	{
		map->after_map[j] = map_copy[i];
		j++;
		i++;
	}
	map->after_map[j] = NULL;
}
