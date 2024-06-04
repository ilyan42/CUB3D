/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:26 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 18:50:45 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	valide_position(t_cub *cub, int x, int y)
{
	return (x >= 0 && y >= 0 && x < cub->map->size_x && y < cub->map->size_y);
}

bool	ft_check_around_floor(t_cub *cub, int x, int y)
{
	if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == '\n') ||
		(valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == '\n') ||
		(valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == '\n') ||
		(valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == '\n'))
		return (false);
	if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
		(valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' ') ||
		(valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == ' ') ||
		(valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == ' '))
		return (false);
	if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == '\0') ||
		(valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == '\0') ||
		(valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == '\0') ||
		(valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == '\0'))
		return (false);
	return (true);
}

bool	ft_check_around_wall(t_cub *cub, int x, int y)
{
	if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
		(valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' ') ||
		(valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == ' ') ||
		(valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == ' '))
		return (true);
	return (true);
}
