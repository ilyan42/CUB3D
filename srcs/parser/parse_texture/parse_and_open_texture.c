/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 18:07:38 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	put_texture(char *line, int check, int x, t_cub *cub)
{
	if (line[x] == 'N' && line[x + 1] == 'O')
		check += parse_north_texture(cub, line, x);
	else if (line[x] == 'S' && line[x + 1] == 'O')
		check += parse_south_texture(cub, line, x);
	else if (line[x] == 'W' && line[x + 1] == 'E')
		check += parse_west_texture(cub, line, x);
	else if (line[x] == 'E' && line[x + 1] == 'A')
		check += parse_east_texture(cub, line, x);
	else if (line[x] == 'F' && line[x + 1] == ' ')
		check += parse_floor_color(cub, line);
	else if (line[x] == 'C' && line[x + 1] == ' ')
		check += parse_ceiling_color(cub, line);
	return (check);
}

void	parsing_texture(t_cub *cub)
{
	int		y;
	int		x;
	int		check;
	char	*line;

	y = 0;
	x = 0;
	check = 0;
	while (cub->texture->texture[y])
	{
		line = cub->texture->texture[y];
		x = 0;
		while (line[x])
		{
			check = put_texture(line, check, x, cub);
			x++;
		}
		y++;
	}
	if (check != 6)
		print_and_exit(WRONG_NUMBER_OF_TEXTURES);
}

int	open_texture(t_cub *cub)
{
	int	fd;

	fd = open(cub->texture_file->north_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_NORTH_TEXTURE);
	close(fd);
	fd = open(cub->texture_file->south_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_SOUTH_TEXTURE);
	close(fd);
	fd = open(cub->texture_file->west_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_WEST_TEXTURE);
	close(fd);
	fd = open(cub->texture_file->east_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_EAST_TEXTURE);
	close(fd);
	return (1);
}

void	check_extention_texture(char *path)
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
	print_and_exit(WRONG_TEXTURE_EXTENTION);
}

void	texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (!cub->texture_file->north_path || !cub->texture_file->south_path
		|| !cub->texture_file->west_path || !cub->texture_file->east_path)
		print_and_exit(MISSING_TEXTURE);
	check_extention_texture(cub->texture_file->north_path);
	check_extention_texture(cub->texture_file->south_path);
	check_extention_texture(cub->texture_file->west_path);
	check_extention_texture(cub->texture_file->east_path);
	open_texture(cub);
}
