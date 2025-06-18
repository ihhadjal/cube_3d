/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/18 20:41:51 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307

typedef struct s_data
{
	void	*ptr;
	void	*win;
}			t_data;

typedef struct s_map
{
	char	**map_copy;
	char	**skip_map;
	char	**actual_map;
	int		nord;
	int		south;
	int		east;
	int		west;
}			t_map;

int			parsing(int argc, char **argv, t_map *map);
int			check_file_name(char *argv);
char	**copy_the_map(char *argv);
void	check_fd(int fd);
int	count_lines(char *argv);
void	check_caracters(char **map_copy);
void	print_map(char **map);
char **skip_lines(char *argv);
#endif