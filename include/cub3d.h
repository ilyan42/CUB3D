/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:30:03 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/14 20:03:35 by ilbendib         ###   ########.fr       */
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
}			t_map;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int 	height;
}			t_texture;

typedef struct s_cub
{
	t_minilibx	*mlx;
	t_map		*map;
	t_texture	*texture;
	char		*line;
}			t_cub;

int	check_texture(t_texture *texture);
void parse_texture_file(t_cub *cub, int fd);
void count_map_height(t_cub *cub, int fd);
void allocate_and_fill_map(t_map *map, int fd);
void is_cub_file(char *map);
void	parsing_map(char *file, t_cub *cub);
void count_texture_height(t_texture *texture, int fd);

#endif