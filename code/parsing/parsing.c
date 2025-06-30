/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:06:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/30 12:33:22 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

int	parsing(int argc, char **argv, t_map *map)
{
	if (argc == 2 && check_file_name(argv[1]) == 0)
	{
		map->map_copy = copy_the_map(argv[1]);
		map->skip_map = skip_lines(map->map_copy, argv[1], map);
		check_instructions(map->before_map);
		// print_map(map->before_map);
		check_paths(map->before_map);
		check_map_validity(map->skip_map);
		map->dummy_map = map_scan(map->skip_map, argv[1]);
		map->rectangular_map = create_rectangular(map->dummy_map, map);
		check_rectangular(map->rectangular_map);
	}
	else
	{
		printf("error: map path is needed\n");
		return (1);
	}
	return (0);
}

char	**create_rectangular(char **map_copy, t_map *map)
{
	char	*new_str;

	map->biggest_len = find_biggest_len(map_copy) + 1;
	map->i = 0;
	while (map_copy[map->i])
	{
		map->current_len = ft_strlen(map_copy[map->i]);
		new_str = malloc(sizeof(char) * (map->biggest_len + 1));
		map->j = 0;
		while (map->j < map->current_len)
		{
			if (map_copy[map->i][map->j] == ' '
				|| map_copy[map->i][map->j] == '\t')
				new_str[map->j] = 'V';
			else
				new_str[map->j] = map_copy[map->i][map->j];
			map->j++;
		}
		while (map->j < map->biggest_len)
			new_str[map->j++] = 'V';
		new_str[map->biggest_len] = '\0';
		free(map_copy[map->i]);
		map_copy[map->i] = new_str;
		map->i++;
	}
	return (map_copy);
}

char	**copy_the_map(char *argv)
{
	int		fd;
	char	**map_copy;
	char	*lines;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (count_lines(argv) + 1));
	fd = open(argv, O_RDONLY);
	check_fd(fd);
	lines = get_next_line(fd);
	while (lines)
	{
		if (lines[ft_strlen(lines) - 1] == '\n')
			lines[ft_strlen(lines) - 1] = '\0';
		map_copy[i++] = ft_strdup(lines);
		free(lines);
		lines = get_next_line(fd);
	}
	map_copy[i] = NULL;
	close(fd);
	return (map_copy);
}

void	check_map_validity(char **map_copy)
{
	int	i;

	i = 0;
	check_doubles(map_copy);
	find_position(map_copy);
	while (map_copy[i])
	{
		check_characters(map_copy[i]);
		i++;
	}
}

void	check_characters(char *map_copy)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (map_copy[i])
	{
		if (map_copy[i] == ' ')
			i++;
		else if ((map_copy[i] != '0' && map_copy[i] != '1')
			&& (map_copy[i] != 'N' && map_copy[i] != 'S') && (map_copy[i] != 'E'
				&& map_copy[i] != 'W') && (map_copy[i] != '\t'
				&& map_copy[i] != '\0'))
		{
			printf("error: invalid character found\n");
			exit(1);
		}
		i++;
	}
}
