/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 18:18:48 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	put_texture(char *line, int *check, int x, t_cub *cub)
{
	if (line[x] == 'N' && line[x + 1] == 'O' && *check == 0)
		*check += parse_north_texture(cub, line, x);
	else if (line[x] == 'S' && line[x + 1] == 'O' && *check == 1)
		*check += parse_south_texture(cub, line, x);
	else if (line[x] == 'W' && line[x + 1] == 'E' && *check == 2)
		*check += parse_west_texture(cub, line, x);
	else if (line[x] == 'E' && line[x + 1] == 'A' && *check == 3)
		*check += parse_east_texture(cub, line, x);
	else if (line[x] == 'F' && line[x + 1] == ' ' && *check == 4)
		*check += parse_floor_color(cub, line);
	else if (line[x] == 'C' && line[x + 1] == ' ' && *check == 5)
		*check += parse_ceiling_color(cub, line);
	else if (line[x] == 'D' && line[x + 1] == 'O' && *check == 6)
		*check += parse_door_texture(cub, line, x);
	return (*check);
}

void	parsing_texture(t_cub *cub)
{
	int		y;
	int		x;
	int		check;
	char	*line;

	y = 0;
	check = 0;
	while (cub->texture->texture[y])
	{
		line = cub->texture->texture[y];
		x = 0;
		while (line[x])
		{
			check = put_texture(line, &check, x, cub);
			x++;
		}
		y++;
	}
	if (check != 7)
		print_and_exit(WRONG_NUMBER_OR_ORDER_OF_TEXTURES, cub);
}

int	open_texture(t_cub *cub)
{
	int	fd;

	fd = open(cub->texture_file->north_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_NORTH_TEXTURE, cub);
	close(fd);
	fd = open(cub->texture_file->south_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_SOUTH_TEXTURE, cub);
	close(fd);
	fd = open(cub->texture_file->west_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_WEST_TEXTURE, cub);
	close(fd);
	fd = open(cub->texture_file->east_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_EAST_TEXTURE, cub);
	close(fd);
	fd = open(cub->texture_file->door_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_DOOR_TEXTURE, cub);
	close(fd);
	return (1);
}

void	check_extention_texture(char *path, t_cub *cub)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
		{
			if (path[i + 1] == 'x' && path[i + 2] == 'p' && path[i + 3] == 'm')
				return ;
		}
		i++;
	}
	print_and_exit(WRONG_TEXTURE_EXTENTION, cub);
}

void	texture_processing(t_cub *cub)
{
	int	i;

	i = 0;
	parsing_texture(cub);
	if (!cub->texture_file->north_path || !cub->texture_file->south_path
		|| !cub->texture_file->west_path || !cub->texture_file->east_path
		|| !cub->texture_file->door_path)
		print_and_exit(MISSING_TEXTURE, cub);
	check_extention_texture(cub->texture_file->north_path, cub);
	check_extention_texture(cub->texture_file->south_path, cub);
	check_extention_texture(cub->texture_file->west_path, cub);
	check_extention_texture(cub->texture_file->east_path, cub);
	check_extention_texture(cub->texture_file->door_path, cub);
	open_texture(cub);
	while (cub->texture->texture[i])
	{
		free(cub->texture->texture[i]);
		i++;
	}
	free(cub->texture->texture);
}
