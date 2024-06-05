/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:54:42 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/05 13:40:46 by ilbendib         ###   ########.fr       */
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
	if (cub->map->map[map_y][map_x] == '1')
		return (0);
	if (cub->map->map[map_y][(int)(new_x + min_dist)] == '1')
		return (0);
	if (cub->map->map[map_y][(int)(new_x - min_dist)] == '1')
		return (0);
	if (cub->map->map[(int)(new_y + min_dist)][map_x] == '1')
		return (0);
	if (cub->map->map[(int)(new_y - min_dist)][map_x] == '1')
		return (0);
	return (1);
}

void	maj_plane_player(t_cub *cub)
{
	cub->player->plane_x = -cub->player->dir_y * (FOV * PI / 180);
	cub->player->plane_y = cub->player->dir_x * (FOV * PI / 180);
}
