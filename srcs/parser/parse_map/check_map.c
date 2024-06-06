/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:15:56 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 18:16:23 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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
				&& cub->map->map[y][x] != 'E' && cub->map->map[y][x] != 'W'
				&& cub->map->map[y][x] != 'D')
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
