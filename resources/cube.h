/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/06/26 21:09:04 by ilhasnao         ###   ########.fr       */
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
	double	x;
	double	y;
	double	dirx;
	double	diry;
	double	posx;
	double	posy;
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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_dda
{
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}	t_dda;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	int		cam_length;
	int		cam_height;
	t_ray	*ray;
	t_pos	*pos;
	t_map	*map;
	t_color	*rgb;
	t_dda	*algo;
}			t_data;

int			parsing(int argc, char **argv, t_map *map);
int			check_file_name(char *argv);
char	**copy_the_map(char *argv);
void	check_fd(int fd);
int	count_lines(char *argv);
void	check_caracters(char **map_copy);
void	print_map(char **map);
#endif