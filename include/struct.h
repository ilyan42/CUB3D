/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:35:52 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 19:55:30 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum t_boolean
{
	_false = 0,
	_true = 1
}	t_boolean;

enum e_texture
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3,
	F,
	C
};

typedef struct s_minilibx
{
	void	*mlx_ptr;
	void	*win;
}			t_minilibx;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		size_x;
	int		size_y;
}			t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path;
}			t_image;

typedef struct s_texture_file
{
	char	**text;
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor;
	char	*ceiling;
}		t_texture_file;

typedef struct s_texture
{
	int				height;
	int				width;
	char			**texture;
	void			*reference;
	unsigned char	*pixels;
	int				x;
	int				y;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}			t_texture;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	angle;
	double	move_speed;
	double	rot_speed;
	float	fov_angle;
	float	fov_rad;
}			t_player;

typedef struct s_color
{
	unsigned int	c_r;
	unsigned int	c_g;
	unsigned int	c_b;
	unsigned int	f_r;
	unsigned int	f_g;
	unsigned int	f_b;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
}			t_color;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
	double	distance;
	double	ray_angle;
	double	horiz_x;
	double	horiz_y;
	double	vertical_x;
	double	vertical_y;
	int		flag;
	int		res_x;
	int		res_y;
	int		true_pos_x;
	int		true_pos_y;
}			t_raycast;

typedef struct s_good
{
	bool	good;
	bool	not_good;
}		t_good;

typedef struct s_key
{
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
	int		escape;
	int		map;
	int		left_shift;
	t_good	*good;
}			t_key;

typedef struct s_mini_map
{
	int		map_block_size;
	int		player_size;
	int		player_color;
	int		start_x;
	int		start_y;
	int		i;
	int		j;
	int		srceen_x;
	int		screen_y;
	int		player_center_x;
	int		player_center_y;
}			t_mini_map;

typedef struct s_pixel_column
{
	int		tex_x;
	int		tex_y;
	int		y_start;
	int		y_end;
	int		height;
	int		color;
}	t_pixel_column;

typedef struct s_cub
{
	t_minilibx		*mlx;
	t_player		*player;
	t_map			*map;
	t_texture		texture[4];
	t_image			*image;
	t_color			color[2];
	t_raycast		*raycast;
	t_mini_map		*mini_map;
	t_texture_file	*texture_file;
	t_key			*key;
	char			*line;
	int				res_x;
	int				res_y;
	int				d;
}			t_cub;

#endif