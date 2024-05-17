/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:30:03 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/17 19:00:08 by ilbendib         ###   ########.fr       */
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
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int 	height;
	char **texture;
}			t_texture;

typedef struct s_color
{
	unsigned int	C_r;
	unsigned int	C_g;
	unsigned int	C_b;
	unsigned int	F_r;
	unsigned int	F_g;
	unsigned int	F_b;
}			t_color;

typedef struct s_cub
{
	t_minilibx	*mlx;
	t_map		*map;
	t_texture	*texture;
	t_image		*image;
	t_color		color[2];
	char		*line;
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

#endif