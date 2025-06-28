/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/28 15:37:07 by ihhadjal         ###   ########.fr       */
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
	char	**before_map;
	char	**after_map;
	char	**rectangular_map;
	char	**dummy_map;
	char	**trim_map;
	char	*trim_str;
	int		biggest_len;
	int		i;
	int		j;
	int		current_len;
	int		start_x;
	int		start_y;
	int		height;
	int		length;
}			t_map;

int			parsing(int argc, char **argv, t_map *map);
int			check_file_name(char *argv);
char		**copy_the_map(char *argv);
void		check_fd(int fd);
int			count_lines(char *argv);
void		check_map_validity(char **map_copy);
void		print_map(char **map);
char		**skip_lines(char **map_copy, char *argv, t_map *map);
int			is_space(char *str);
void		after_copy_logic(t_map *map, int i, char *argv, char **map_copy);
void		check_characters(char *map_copy);
int	find_biggest_len(char **map);
char	**map_scan(char **map, char *argv);
char	**create_rectangular(char **map_copy, t_map *map);
void	free_map(char **map);
void	ft_error(char *str, char **map);
void	check_rectangular(char **rec_map);
void	check_instructions(char **map_copy);
void	check_paths(char **before_map);
#endif