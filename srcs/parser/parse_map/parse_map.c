/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:24 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 14:57:17 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	get_size_map(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	cub->map->size_x = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
			x++;
		if (x > cub->map->size_x)
			cub->map->size_x = x;
		y++;
	}
	cub->map->size_y = y;
}

void	init_player(t_cub *cub, int x, int y)
{
	if (cub->map->map[y][x] == 'N')
		cub->player->angle = -M_PI_2;
	else if (cub->map->map[y][x] == 'S')
		cub->player->angle = M_PI_2;
	else if (cub->map->map[y][x] == 'E')
		cub->player->angle = 0.0;
	else if (cub->map->map[y][x] == 'W')
		cub->player->angle = M_PI;
	cub->player->pos_x = x;
	cub->player->pos_y = y;
	cub->player->dir_x = cos(cub->player->angle);
	cub->player->dir_y = sin(cub->player->angle);
	cub->player->plane_x = cos(cub->player->angle + M_PI_2);
	cub->player->plane_y = sin(cub->player->angle + M_PI_2);
	cub->map->map[y][x] = '0';
}

void	get_player_position(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S'
				|| cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
			{
				init_player(cub, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_to_many_player(t_cub *cub)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S'
				|| cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
		print_and_exit(TO_MANY_PLAYERS_OR_NO_PLAYER, cub);
}

void	check_character_in_map(t_cub *cub)
{
	int	x;
	int	y;
	int	check;

	y = 0;
	check = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] != '0' && cub->map->map[y][x] != '1'
				&& cub->map->map[y][x] != 'N' && cub->map->map[y][x] != ' '
				&& cub->map->map[y][x] != '\n' && cub->map->map[y][x] != 'S'
				&& cub->map->map[y][x] != 'E' && cub->map->map[y][x] != 'W')
				check++;
			x++;
		}
		y++;
	}
	if (check != 0)
		print_and_exit(WRONG_CHARACTER_IN_MAP, cub);
}

void	check_first_colone(t_cub *cub)
{
	int	y;

	y = 0;
	while (cub->map->map[y])
	{
		if (cub->map->map[y][0] != '1')
			print_and_exit("hdhdhd", cub);
		y++;
	}
}

void	check_map(t_cub *cub)
{
	get_size_map(cub);
	check_first_colone(cub);
	check_to_many_player(cub);
	check_character_in_map(cub);
}

void	map_is_valid(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	check_map(cub);
	while (cub->map->map[y])
	{
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == '0')
			{
				if (ft_check_around_floor(cub, x, y) == false)
					print_and_exit("bababa", cub);
			}
			else if (cub->map->map[y][x] == '1')
				if (ft_check_around_wall(cub, x, y) == false)
					print_and_exit("kdkdk", cub);
			x++;
		}
		x = 0;
		y++;
	}
	get_player_position(cub);
}
