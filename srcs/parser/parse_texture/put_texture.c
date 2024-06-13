/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:24:33 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/12 19:55:24 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	put_texture_no_so(char *line, int *check, int x, t_cub *cub)
{
	if (line[x] == 'N' && line[x + 1] == 'O')
		if (cub->order_tex->north)
			print_and_exit("MULTIPLE_TEXTURE1", cub, 0);
	if (line[x] == 'S' && line[x + 1] == 'O')
		if (cub->order_tex->south)
			print_and_exit("MULTIPLE_TEXTURE2", cub, 0);
	if (line[x] == 'N' && line[x + 1] == 'O' && *check == 0)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_north_texture(cub, line, x);
		else
			print_and_exit(INVALIDE_NORTH_TEXTURE, cub, 0);
	}
	else if (line[x] == 'S' && line[x + 1] == 'O' && *check == 1)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_south_texture(cub, line, x);
		else
			print_and_exit(INVALIDE_SOUTH_TEXTURE, cub, 0);
	}
	return (*check);
}

int	put_texture_we_ea(char *line, int *check, int x, t_cub *cub)
{
	if (line[x] == 'W' && line[x + 1] == 'E')
		if (cub->order_tex->west)
			print_and_exit("MULTIPLE_TEXTURE3", cub, 0);
	if (line[x] == 'E' && line[x + 1] == 'A')
		if (cub->order_tex->east)
			print_and_exit("MULTIPLE_TEXTURE4", cub, 0);
	if (line[x] == 'W' && line[x + 1] == 'E' && *check == 2)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_west_texture(cub, line, x);
		else
			print_and_exit(INVALIDE_WEST_TEXTURE, cub, 0);
	}
	else if (line[x] == 'E' && line[x + 1] == 'A' && *check == 3)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_east_texture(cub, line, x);
		else
			print_and_exit(INVALIDE_EAST_TEXTURE, cub, 0);
	}
	return (*check);
}

int	put_texture_c_f_d(char *line, int *check, int x, t_cub *cub)
{
	if (line[x] == 'F' && line[x + 1] == ' ')
		if (cub->order_tex->floor)
			print_and_exit("MULTIPLE_TEXTURE5", cub, 0);
	if (line[x] == 'C' && line[x + 1] == ' ')
		if (cub->order_tex->ceiling)
			print_and_exit("MULTIPLE_TEXTURE6", cub, 0);
	if (line[x] == 'F' && line[x + 1] == ' ' && *check == 4)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_floor_color(cub, line);
		else
			print_and_exit(INVALIDE_FLOOR_COLOR, cub, 0);
	}
	else if (line[x] == 'C' && line[x + 1] == ' ' && *check == 5)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_ceiling_color(cub, line);
		else
			print_and_exit(INVALIDE_CEILING_COLOR, cub, 0);
	}
	return (*check);
}

int	put_texture_door(char *line, int *check, int x, t_cub *cub)
{
	if (line[x] == 'D' && line[x + 1] == 'O')
		if (cub->order_tex->door)
			print_and_exit("MULTIPLE_TEXTURE7", cub, 0);
	if (line[x] == 'D' && line[x + 1] == 'O' && *check == 6)
	{
		if (has_only_spaces_before(line, x))
			*check += parse_door_texture(cub, line, x);
		else
			print_and_exit(INVALIDE_DOOR_TEXTURE, cub, 0);
	}
	return (*check);
}

int	put_texture(char *line, int *check, int x, t_cub *cub)
{
	int	result;

	result = put_texture_no_so(line, check, x, cub);
	if (result == *check)
		result = put_texture_we_ea(line, check, x, cub);
	if (result == *check)
		result = put_texture_c_f_d(line, check, x, cub);
	if (result == *check)
		result = put_texture_door(line, check, x, cub);
	return (result);
}
