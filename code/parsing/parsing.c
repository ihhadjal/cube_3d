/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:06:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/20 18:55:01 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

int	parsing(int argc, char **argv, t_map *map)
{
	if (argc == 2 && check_file_name(argv[1]) == 0)
	{
		map->map_copy = copy_the_map(argv[1]);
		map->skip_map = skip_lines(map->map_copy, argv[1], map);
		map->dummy_map = map_scan(map->skip_map, argv[1]);
		map->rectangular_map = create_rectangular(map->dummy_map);
		// check_map_validity(map->skip_map);
		// print_map(map->skip_map);
	}
	else
	{
		printf("error: map is needed\n");
		return (1);
	}
	return (0);
}
char	**map_scan(char **map, char *argv)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char * ) * (count_lines(argv) - 6) + 1);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}
char	**create_rectangular(char **map_copy)
{
	int	biggest_len;
	int	i;
	int	j;
	int	current_len;
	char	*new_str;
	
	biggest_len = find_biggest_len(map_copy);
	i = 0;
	while (map_copy[i])
	{
		current_len = ft_strlen(map_copy[i]);
		if (current_len < biggest_len)
		{
			j = 0;
			new_str = malloc(sizeof(char ) * (biggest_len + 1));
			while (j < current_len)
			{
				new_str[j] = map_copy[i][j];
				j++;
			}
			while (j < biggest_len)
			{
				new_str[j] = 'V';
				j++;
			}
			new_str[biggest_len] = '\0';
			free(map_copy[i]);
			map_copy[i] = new_str;
		}
		i++;
	}
	return (map_copy);
}
int	find_biggest_len(char **map)
{
	int	i;
	int	len;
	int	biggest;
	
	i = 0;
	biggest = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > biggest)
			biggest = len;
		i++;
	}
	return (biggest);
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
	int		i;
	char	*trim_str;
	int		started;

	i = 0;
	started = 0;
	while (map_copy[i])
	{
		trim_str = ft_strtrim(map_copy[i], "\t\n\v\f\r");
		if (trim_str[0] != '\0')
			started = 1;
		else if (started == 1)
		{
			printf("error: empty line in map\n");
			exit(1);
		}
		// check_characters(map_copy[i]);
		i++;
	}
}

void	check_characters(char *map_copy)
{
	int i;

	i = 0;
	while (map_copy[i])
	{
		if ((map_copy[i] != '0' && map_copy[i] != '1') && (map_copy[i] != 'N'
				&& map_copy[i] != 'S') && (map_copy[i] != 'E'
				&& map_copy[i] != 'W') && (map_copy[i] != '\t' && map_copy[i] != '\0' && map_copy[i] != ' '))
		{
			printf("error: invalid character found\n");
			exit(1);
		}
		i++;
	}
}