/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:54:42 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 18:22:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_position_valid(t_cub *cub, double new_x, double new_y)
{
	const double	min_dist = 0.1;
	int				map_x;
	int				map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (cub->map->map[map_y][map_x] == '1'
		|| cub->map->map[map_y][map_x] == 'D')
		return (0);
	if (cub->map->map[map_y][(int)(new_x + min_dist)] == '1'
		|| cub->map->map[map_y][(int)(new_x - min_dist)] == 'D')
		return (0);
	if (cub->map->map[map_y][(int)(new_x - min_dist)] == '1'
		|| cub->map->map[map_y][(int)(new_x + min_dist)] == 'D')
		return (0);
	if (cub->map->map[(int)(new_y + min_dist)][map_x] == '1'
		|| cub->map->map[(int)(new_y + min_dist)][map_x] == 'D')
		return (0);
	if (cub->map->map[(int)(new_y - min_dist)][map_x] == '1'
		|| cub->map->map[(int)(new_y - min_dist)][map_x] == 'D')
		return (0);
	return (1);
}

void	maj_plane_player(t_cub *cub)
{
	cub->player->plane_x = -cub->player->dir_y * (FOV * PI / 180);
	cub->player->plane_y = cub->player->dir_x * (FOV * PI / 180);
}

void	open_close_door(t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = (int)cub->player->pos_x;
	map_y = (int)cub->player->pos_y;
	if (cub->map->map[map_y][map_x + 1] == 'D')
		cub->map->map[map_y][map_x + 1] = '0';
	else if (cub->map->map[map_y][map_x - 1] == 'D')
		cub->map->map[map_y][map_x - 1] = '0';
	else if (cub->map->map[map_y + 1][map_x] == 'D')
		cub->map->map[map_y + 1][map_x] = '0';
	else if (cub->map->map[map_y - 1][map_x] == 'D')
		cub->map->map[map_y - 1][map_x] = '0';
}
