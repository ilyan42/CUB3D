/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:30:03 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/24 17:24:33 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../LIBFT/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>

# define ESCAPE_KEY 65307
# define SIZE 50

# define W 119
# define S_QW 115
# define A 97
# define D_QW 100

# define Z 13
# define Q 1
# define S 0
# define D 2

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
#define M_PI 3.14159265358979323846

# define MAP_IS_NOT_VALID "Error\n -> Map is not valid\n"
# define WRONG_ARGUMENTS_IN_MAP "Error\n -> Wrong arguments in map\n"
# define MAP_IS_NOT_CLOSED "Error\n -> Map is not closed\n"
# define NO_PLAYER "Error\n -> No player in map\n"
# define TOO_MANY_PLAYERS "Error\n -> Too many players in map\n"
# define OPEN_NORTH_TEXTURE "Error\n -> Open north texture\n"
# define OPEN_SOUTH_TEXTURE "Error\n -> Open south texture\n"
# define OPEN_WEST_TEXTURE "Error\n -> Open west texture\n"
# define OPEN_EAST_TEXTURE "Error\n -> Open east texture\n"
# define WRONG_NUMBER_OK_TEXTURES "Error\n -> Wrong number of textures\n"
# define INVALIDE_FLOOR_COLOR "Error\n -> Invalid floor color\n"
# define INVALIDE_CEILING_COLOR "Error\n -> Invalid ceiling color\n"
# define WRONG_TEXTURE_EXTENTION "Error\n -> Wrong texture extention\n"
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
#define NUM_TEXTURES 4 
#define MOVE_SPEED 0.1
#define ROTATE_SPEED 0.1
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define TILE_SIZE 64
#define FOV 66
#define ROT_SPEED 0.1
#define MAP_BLOCK_SIZE 64
#define PI 3.1415926535
#define FOV_RAD (FOV * PI / 180)



#define WALL_CHAR '1'

#define MOVE_FORWARD_KEY W
#define MOVE_BACKWARD_KEY S
#define MOVE_LEFT_KEY A
#define MOVE_RIGHT_KEY D




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
	int size_x;
	int size_y;
}			t_map;

typedef struct s_image
{
	void	*img;
	void	*NO_img;
	void	*SO_img;
	void	*WE_img;
	void	*EA_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char 	*path;
}			t_image;


typedef struct s_texture
{
	char	*north_path;
	char	*south_path;
	char	*west_path;
	char	*east_path;
	char	*floor;
	char	*ceiling;
	int 	height;
	char **texture;
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
	unsigned int	C_r;
	unsigned int	C_g;
	unsigned int	C_b;
	unsigned int	F_r;
	unsigned int	F_g;
	unsigned int	F_b;
	unsigned int  color_floor;
	unsigned int  color_ceiling;
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
	double distance;
	double ray_angle;
	double horiz_x;
	double horiz_y;
	double vertical_x;
	double vertical_y;
	int flag;
	int res_x;
	int res_y;
}			t_raycast;

typedef struct s_cub
{
	t_minilibx	*mlx;
	t_player	*player;
	t_map		*map;
	t_texture	*texture;
	t_image		*image;
	t_color		color[2];
	t_raycast	*raycast;
	char		*line;
	int res_x;
	int res_y;
}			t_cub;

int			check_texture(t_texture *texture);
char		**parse_texture_file(t_cub *cub, int fd);
void		count_map_height(t_cub *cub, int fd);
char		**allocate_and_fill_map(t_cub *cub, int fd);
void		is_cub_file(char *map);
void		get_map_and_tex(char *file, t_cub *cub);
void		count_texture_height(t_cub *cub, int fd);
void		parsing_texture(t_cub *cub);
void		texture_processing(t_cub *cub);

/************************************************/
/*					PARSING						*/
/************************************************/

void		parse_ceiling_texture(t_cub *cub, char *line, int x);
void		parsing_texture(t_cub *cub);
int			open_texture(t_cub *cub);
void		texture_processing(t_cub *cub);
void		parse_north_texture(t_cub *cub, char *line, int x);
void		parse_south_texture(t_cub *cub, char *line, int x);
void		parse_west_texture(t_cub *cub, char *line, int x);
void		parse_east_texture(t_cub *cub, char *line, int x);
void		parse_floor_texture(t_cub *cub, char *line, int x);
void parse_floor_color(t_cub *cub, char *line);
void parse_ceiling_color(t_cub *cub, char *line);


void map_is_valid(t_cub *cub);
void get_size_map(t_cub *cub);
void print_and_exit(char *msg);
void raycasting(t_cub *cub);
void load_image(t_cub *cub);

void display_map_pixel_color(t_cub *cub);
int ft_handle_key_press(int keycode, void *param);
int close_game(t_minilibx *game);
void move_player(t_cub *cub, int key);



void display_map_pixel_color(t_cub *cub);
void	rotate_left(t_cub *cub);
void	rotate_right(t_cub *cub);
void display_raycast_distance_wall(t_cub *cub);
void renderer_wall(t_cub *cub, t_raycast *raycast, int ray);
void raycasting(t_cub *cub);


void init_raycast(t_cub *cub, t_raycast *raycast, int x);
void get_step_and_side_dist(t_cub *cub, t_raycast *raycast);
void perform_dda(t_cub *cub, t_raycast *raycast);
void get_distance(t_cub *cub, t_raycast *raycast);

#endif