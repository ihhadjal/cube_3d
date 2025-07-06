/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/05 18:03:22 by hasnawww         ###   ########.fr       */
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
# include <stdbool.h>

# define ESC 65307
# define D 100
# define A 97
# define W 119
# define S 115

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
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		cam_length;
	int		cam_height;
	t_ray	*ray;
	t_pos	*pos;
	t_map	*map;
	t_color	*rgb;
	t_dda	*algo;
}			t_data;

#define rotspeed	0.02
#define movespeed	0.02

int			parsing(int argc, char **argv, t_map *map);
int			check_file_name(char *argv);
char	**copy_the_map(char *argv);
void	check_fd(int fd);
int	count_lines(char *argv);
void	check_caracters(char **map_copy);
void	print_map(char **map);
void	drawinggg(t_data *mlx, int col, int j, int color, int code);
int		move_player(t_data **mlx);
void	ray_trace(t_data *data);
void	rotate(t_data **mlx, int keycode);
void	rend_map(t_data *mlx);
void	draw_fov(t_data *mlx);
void	loop(t_data *mlx);


#endif