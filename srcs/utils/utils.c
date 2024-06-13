/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:30:40 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 18:14:00 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	has_only_spaces(const char *start, const char *end)
{
	while (start < end)
	{
		if (*start != ' ' && *start != '\t')
			return (false);
		start++;
	}
	return (true);
}

int	is_valid_floor_color_char(char c)
{
	if (c == ' ' || c == ',' || (c >= '0' && c <= '9')
		|| c == '\n' || c == '\t')
		return (1);
	return (0);
}

void	check_first_line(t_cub *cub)
{
	int	x;

	x = 0;
	while (cub->map->map[0][x])
	{
		if (cub->map->map[0][x] != '1' && cub->map->map[0][x]
			!= '\n' && cub->map->map[0][x] != ' ')
			print_and_exit(MAP_IS_NOT_CLOSED, cub, 0);
		x++;
	}
}

void	check_last_line(t_cub *cub)
{
	int	x;
	int	y;

	x = 0;
	y = cub->map->size_y - 1;
	while (cub->map->map[y][x])
	{
		if (cub->map->map[y][x] != '1' && cub->map->map[y][x]
			!= '\n' && cub->map->map[y][x] != ' ')
			print_and_exit(MAP_IS_NOT_CLOSED, cub, 0);
		x++;
	}
}
