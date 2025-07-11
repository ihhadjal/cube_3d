/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihhadjal <ihhadjal@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:20:58 by ilhasnao          #+#    #+#             */
/*   Updated: 2025/07/11 13:18:32 by ihhadjal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "libft/libft.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define D 100
# define A 97
# define W 119
# define S 115
# define LEFT 65361
# define RIGHT 65363
# define RS 0.02
# define MOVESPEED 0.02

typedef struct s_ray
{
	double		camera_x;
	double		dirx;
	double		diry;
}				t_ray;

typedef struct s_pos
{
	double		time;
	double		old_time;
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		posx;
	double		posy;
	double		planex;
	double		planey;
}				t_pos;

typedef struct s_map
{
	char		**map_copy;
	char		**skip_map;
	char		**before_map;
	char		**after_map;
	char		**rectangular_map;
	char		**dummy_map;
	char		**trim_map;
	char		*trim_str;
	int			biggest_len;
	int			i;
	int			j;
	int			current_len;
	int			start_x;
	int			start_y;
	int			height;
	int			length;
	int			no;
	int			so;
	int			ea;
	int			we;
}				t_map;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_dda
{
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	double		step;
}				t_dda;

typedef enum texnum
{
	NO,
	SO,
	WE,
	EA,
}				t_texnum;

typedef struct text
{
	char		*path;
	int			tw;
	int			th;
	int			texx;
	int			texy;
	double		texpos;
	int			*tex;
	char		*tex_addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_text;

typedef struct s_data
{
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		right;
	bool		left;
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			cam_length;
	int			cam_height;
	bool		has_moved;
	int			**buffer;
	t_text		*texture;
	t_texnum	num;
	t_ray		*ray;
	t_pos		*pos;
	t_map		*map;
	t_color		*ceiling;
	t_color		*floor;
	t_dda		*algo;
}				t_data;

//======================RAYCASTING===============================//
int				parsing(int argc, char **argv, t_map *map);
int				check_file_name(char *argv);
char			**copy_the_map(char *argv);
void			check_fd(int fd);
int				count_lines(char *argv);
int				check_caracters(char *map_copy);
void			print_map(char **map);
int				move_player(t_data **mlx);
void			ray_trace(t_data *data);
void			rend_map(t_data *mlx);
void			draw_fov(t_data *mlx);
void			loop(t_data *mlx);
void			init_texture(t_text *texture, t_data *mlx, char *str);
void			my_mlx_init(t_data *mlx);
void			algo_init(t_data **data);
int				on_keypress(int keycode, t_data *mlx);
int				on_release(int keycode, t_data *mlx);
void			rotate(t_data *mlx, int keycode);
int				move_player(t_data **mlx);
int				free_all1(t_data *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				assemble_rgb(t_color *c);
int				determine_texnum(t_data *data);
void			get_coordinates(t_data *mlx, double *x, double *y);
void			init_delta(t_data *data);
void			init_dist(t_data *data);
void			hit_loop(t_data *data);
void			assign_drawing_limits(t_data *data);
void			texture_pixel(t_data *data);
void			dda(t_data *data);
void			launch_ray(t_data *data);
void			draw_fov(t_data *mlx);
void			drawing_condition(t_data *data, int *d, int y, int *color);
void			render_map(t_data *data, int x);
void			loop(t_data *mlx);
void			determine_angle(t_data *mlx);
void			assign_angle(t_data *mlx, int i, int j);
t_color			*find_color(t_data *mlx, char c);
void			free_mlx(t_data *mlx);
void			assign_texture(t_data *mlx);
int				cal_h(char **map);
void			move_up(t_data **mlx);
void			move_down(t_data **mlx);
void			move_right(t_data **mlx);
void			move_left(t_data **mlx);

//======================PARSING==================================//
char			**copy_the_map(char *argv);
void			check_fd(int fd);
int				count_lines(char *argv);
void			check_map_validity(char **map_copy);
void			print_map(char **map);
char			**skip_lines(char **map_copy, char *argv, t_map *map);
int				is_space(char *str);
void			after_copy_logic(t_map *map, int i, char *argv,
					char **map_copy);
int				check_characters(char *map_copy);
int				find_biggest_len(char **map);
char			**map_scan(char **map, char *argv);
char			**create_rectangular(char **map_copy, t_map *map);
void			free_map(char **map);
void			ft_error(char *str, char **map);
void			check_rectangular(char **rec_map);
void			check_instructions(char **map_copy);
void			check_paths(char **before_map);
int				check_nums(char *str);
void			big_condition(char **rec_map, int i, int j);
void			free_maps(t_map *map);
void			check_doubles(char **map_copy);
void			error(int x, int y);
void			find_position(char **map_copy);
int				is_alpha(char *str);
int				check_xpm(char *str);
void			check_rgb(char *str);
void			check_c_f(char **split_str);
int				condition(int c, t_map *map);
void	doubles_check(char **before_map);
void	check2(char **map);
#endif