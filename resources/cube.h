/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/23 15:32:10 by hasnawww         ###   ########.fr       */
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
# include <math.h>

# define ESC 65307
typedef struct s_ray
{
	double	camera_x;
	double	dirx;
	double	diry;
}			t_ray;

typedef struct s_pos
{
	double	time;
	double	old_time;
	int		x;
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}			t_pos;

typedef struct s_map
{
	char	**map_copy;
	int		nord;
	int		south;
	int		east;
	int		west;
}			t_map;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	int		cam_length;
	int		cam_height;
	t_ray	*ray;
	t_pos	*pos;
	t_map	*map;
}			t_data;

int			parsing(int argc, char **argv, t_map *map);
int			check_file_name(char *argv);
char	**copy_the_map(char *argv);
void	check_fd(int fd);
int	count_lines(char *argv);
void	check_caracters(char **map_copy);
void	print_map(char **map);
#endif