/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 18:58:41 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/30 13:16:52 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

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

char	**map_scan(char **map, char *argv)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = malloc(sizeof(char *) * (count_lines(argv) - 6) + 1);
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_error(char *str, char **map)
{
	printf("%s", str);
	if (map != NULL)
		free_map(map);
	exit(EXIT_FAILURE);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int		check_nums(char *str)
{
	int	i;
	char	**numbers;
	int		integer;
	
	numbers = ft_split(str, ',');
	i = 0;
	while (numbers[i])
	{
		integer = ft_atoi(numbers[i]);
		if (integer < 0 || integer > 255)
		{
			free_map(numbers);
			return (1);
		}
		i++;
	}
	free_map(numbers);
	return (0);
}
