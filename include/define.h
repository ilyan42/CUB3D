/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:37:03 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 18:39:29 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ESCAPE_KEY 65307
# define SIZE 50

# define W 119
# define S_QW 115
# define A 97
# define D_QW 100
# define E 101

# define Z 13
# define Q 1
# define S 0
# define D 2

# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

# define M_PI 3.14159265358979323846
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NUM_TEXTURES 4 
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.03
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TILE_SIZE 64
# define FOV 66
# define ROT_SPEED 5
# define MAP_BLOCK_SIZE 64
# define PI 3.1415926535
# define MAP 109
# define LEFT_SHIFT 65505
# define WALL_CHAR '1'
# define MOVE_FORWARD_KEY W
# define MOVE_BACKWARD_KEY S
# define MOVE_LEFT_KEY A
# define MOVE_RIGHT_KEY D

# define MAP_IS_NOT_VALID "Error\n -> Map is not valid\n"
# define WRONG_ARGUMENTS_IN_MAP "Error\n -> Wrong arguments in map\n"
# define MAP_IS_NOT_CLOSED "Error\n -> Map is not closed\n"
# define NO_PLAYER "Error\n -> No player in map\n"
# define TOO_MANY_PLAYERS "Error\n -> Too many players in map\n"
# define OPEN_NORTH_TEXTURE "Error\n -> Open north texture\n"
# define OPEN_SOUTH_TEXTURE "Error\n -> Open south texture\n"
# define OPEN_WEST_TEXTURE "Error\n -> Open west texture\n"
# define OPEN_EAST_TEXTURE "Error\n -> Open east texture\n"
# define WRONG_NUMBER_OR_ORDER_OF_TEXTURES "Error \
	\n -> Wrong number or order of textures\n"
# define INVALIDE_FLOOR_COLOR "Error\n -> Invalid floor color\n"
# define INVALIDE_CEILING_COLOR "Error\n -> Invalid ceiling color\n"
# define WRONG_TEXTURE_EXTENTION "Error\n -> Wrong texture extention\n"
# define MALLOC_FAILED "Error\n -> Memory allocation failed\n"
# define INVALIDE_NORTH_TEXTURE "Error\n -> Invalid north texture format\n"
# define INVALIDE_SOUTH_TEXTURE "Error\n -> Invalid south texture format\n"
# define INVALIDE_WEST_TEXTURE "Error\n -> Invalid west texture format\n"
# define INVALIDE_EAST_TEXTURE "Error\n -> Invalid east texture format\n"
# define MISSING_TEXTURE "Error\n -> Missing texture\n"
# define INVALIDE_FILE_EXTENSION "Error\n -> Invalid file extension\n"
# define TO_MANY_PLAYERS_OR_NO_PLAYER "Error \
	\n -> To many players or no player\n"
# define WRONG_TEXTURE_FORMAT "Error\n -> Wrong texture format\n"
# define WRONG_CHARACTER_IN_MAP "Error\n -> Wrong character in map\n"
# define INVALIDE_DOOR_TEXTURE "Error\n -> Invalid door texture format\n"
# define OPEN_DOOR_TEXTURE "Error\n -> Open door texture\n"

#endif