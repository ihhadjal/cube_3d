/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:21:19 by ihhadjal          #+#    #+#             */
/*   Updated: 2025/06/18 14:36:29 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../resources/cube.h"

void	check_fd(int fd)
{
	if (fd == -1)
	{
		printf("map is not accessible\n");
		close(fd);
		exit(1);
	}
}

int	check_file_name(char *argv)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", 4))
	{
		printf("error: the extension must be .cub\n");
		exit(1);
	}
	return (0);
}

int	count_lines(char *argv)
{
	char *lines;
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	lines = get_next_line(fd);
	while (lines)
	{
		i++;
		free (lines);
		lines = get_next_line(fd);
	}
	close (fd);
	return (i);
}
