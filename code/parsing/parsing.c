/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:06:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/19 11:34:47 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

int	parsing(int argc, char **argv, t_map *map)
{
	if (argc == 2 && check_file_name(argv[1]) == 0)
	{
		map->map_copy = copy_the_map(argv[1]);
		map->skip_map = skip_lines(map->map_copy, argv[1], map);
	}
	else
	{
		printf("error: map is needed\n");
		return (1);
	}
	return (0);
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

// void	check_caracters(char **map_copy)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (map_copy[i])
// 	{
// 		j = 0;
// 		while (map_copy[i][j])
// 		{
// 			if (map_copy[i][j] != '0' && map_copy[i][j] != '1'
// 				&& map_copy[i][j] != 'N' && map_copy[i][j] != 'S'
// 				&& map_copy[i][j] != 'E' && map_copy[i][j] != 'W')
// 			{
// 				printf("error: invalid character found\n");
// 				exit (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
