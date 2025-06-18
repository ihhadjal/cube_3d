/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:06:37 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/18 20:38:24 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

int	parsing(int argc, char **argv, t_map *map)
{
	if (argc == 2 && check_file_name(argv[1]) == 0)
	{
		map->map_copy = copy_the_map(argv[1]);
		map->map_copy = skip_lines(argv[1]);
		// int	i = 0;
		// while (map->map_copy[i])
		// {
		// 	printf("%s", map->map_copy[i]);
		// 	i++;
		// }
		print_map(map->map_copy);
		// check_caracters(map->map_copy);
	}
	else
	{
		printf("error: map is needed\n");
		return (1);
	}
	return (0);
}
char **skip_lines(char *argv)
{
	int	i;
	int	j;
	int	fd;
	char	*lines;
	char	**pert;
	
	pert = malloc(sizeof(char *) * 7);
	fd = open(argv, O_RDONLY);
	j = 0;
	i = 0;
	lines = get_next_line(fd);
	while (lines)
	{
		if (ft_strchr(lines, '\n') != 0)
		{
			pert[j] = lines;
			j++;
			i++;	
		}
		if (i == 7)
			break;
		lines = get_next_line(fd);
	}
	pert[j] = NULL;
	return (pert);
	close (fd);
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
