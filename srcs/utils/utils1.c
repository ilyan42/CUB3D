/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:46:27 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 17:37:11 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_order_tex(t_cub *cub)
{
	cub->order_tex = malloc(sizeof(t_order_tex));
	if (!cub->order_tex)
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->order_tex->north = false;
	cub->order_tex->south = false;
	cub->order_tex->west = false;
	cub->order_tex->east = false;
	cub->order_tex->floor = false;
	cub->order_tex->ceiling = false;
	cub->order_tex->door = false;
}

int	check_cmp(char *line)
{
	if (strncmp(line, "NO", 2) == 0 || strncmp(line, "SO", 2) == 0
		|| strncmp(line, "WE", 2) == 0 || strncmp(line, "EA", 2) == 0
		|| strncmp(line, "F", 1) == 0 || strncmp(line, "C", 1) == 0
		|| strncmp(line, "DO", 2) == 0)
		return (1);
	return (0);
}

int	check_line(char *line, int check, t_cub *cub, int texture_found)
{
	int	x;

	if (check_cmp(line))
	{
		x = 0;
		while (line[x])
		{
			check = put_texture(line, &check, x, cub);
			x++;
		}
		texture_found = 1;
	}
	if (!texture_found)
		print_and_exit(WRONG_NUMBER_OR_ORDER_OF_TEXTURES, cub, 1);
	return (check);
}

int	isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

bool	has_only_spaces_before(const char *line, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}
