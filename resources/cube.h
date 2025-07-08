/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/08 17:01:10 by hasnawww         ###   ########.fr       */
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
	double	wallx;
	double	step;
}	t_dda;

typedef enum texnum
{
	NO,
	SO,
	WE,
	EA,
}	texnum;
typedef struct text
{
	char	*path;
	int		tw;
	int		th;
	int		texx;
	int		texy;
	double	texpos;
	int		*tex;
	char	*tex_addr;
	int		bpp;
	int		line_length;
	int		endian;
}		text;

typedef struct s_data
{
	texnum		num;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			cam_length;
	int			cam_height;
	// u_int32_t	**buffer;
	text		*texture;
	t_ray		*ray;
	t_pos		*pos;
	t_map		*map;
	t_color		*rgb;
	t_dda		*algo;
}			t_data;

#define rotspeed	0.015
#define movespeed	0.015

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


char		**copy_the_map(char *argv);
void		check_fd(int fd);
int			count_lines(char *argv);
void		check_map_validity(char **map_copy);
void		print_map(char **map);
char		**skip_lines(char **map_copy, char *argv, t_map *map);
int			is_space(char *str);
void		after_copy_logic(t_map *map, int i, char *argv, char **map_copy);
void		check_characters(char *map_copy);
int			find_biggest_len(char **map);
char		**map_scan(char **map, char *argv);
char		**create_rectangular(char **map_copy, t_map *map);
void		free_map(char **map);
void		ft_error(char *str, char **map);
void		check_rectangular(char **rec_map);
void		check_instructions(char **map_copy);
void		check_paths(char **before_map);
int			check_nums(char *str);
void		big_condition(char **rec_map, int i, int j);
void		free_maps(t_map *map);
void		check_doubles(char **map_copy);
void		error(int x, int y);
void		find_position(char **map_copy);
int			is_alpha(char *str);
int			check_xpm(char *str);
void		check_rgb(char *str);
void		check_c_f(char **split_str);
#endif