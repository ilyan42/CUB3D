/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:26 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 18:12:53 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool	valide_position(t_cub *cub, int x, int y)
{
	if (x < 0 || y < 0 || x >= cub->map->size_x || y >= cub->map->size_y)
		return (false);
	return (x >= 0 && y >= 0 && x < cub->map->size_x && y < cub->map->size_y
		&& (cub->map->map[y][x] == '\n' || cub->map->map[y][x] == ' '
		|| cub->map->map[y][x] == '\0'));
}

bool	ft_check_around_wall(t_cub *cub, int x, int y)
{
	if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
		(valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' '))
		return (true);
	return (true);
}

bool	ft_check_around_floor(t_cub *cub, int x, int y)
{
	if ((valide_position(cub, x + 1, y))
		|| (valide_position(cub, x - 1, y))
		|| (valide_position(cub, x, y + 1))
		|| (valide_position(cub, x, y - 1)))
		return (false);
	if ((valide_position(cub, x + 1, y))
		|| (valide_position(cub, x - 1, y))
		|| (valide_position(cub, x, y + 1))
		|| (valide_position(cub, x, y - 1)))
		return (false);
	if ((valide_position(cub, x + 1, y))
		|| (valide_position(cub, x - 1, y))
		|| (valide_position(cub, x, y + 1))
		|| (valide_position(cub, x, y - 1)))
		return (false);
	return (true);
}
