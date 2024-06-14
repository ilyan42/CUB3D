/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:43:40 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	parsing_texture(t_cub *cub)
{
	int		y;
	int		check;
	char	*line;
	int		texture_found;

	y = 0;
	check = 0;
	init_order_tex(cub);
	while (cub->texture->texture[y])
	{
		line = cub->texture->texture[y];
		while (*line && isspace((unsigned char)*line))
			line++;
		if (*line == '\0')
		{
			y++;
			continue ;
		}
		texture_found = 0;
		check = check_line(line, check, cub, texture_found);
		y++;
	}
	if (check != 7)
		print_and_exit(WRONG_NUMBER_OR_ORDER_OF_TEXTURES, cub, 1);
}

int	open_texture(t_cub *cub)
{
	int	fd;

	fd = open(cub->texture_file->north_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_NORTH_TEXTURE, cub, 1);
	close(fd);
	fd = open(cub->texture_file->south_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_SOUTH_TEXTURE, cub, 1);
	close(fd);
	fd = open(cub->texture_file->west_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_WEST_TEXTURE, cub, 1);
	close(fd);
	fd = open(cub->texture_file->east_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_EAST_TEXTURE, cub, 1);
	close(fd);
	fd = open(cub->texture_file->door_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_DOOR_TEXTURE, cub, 1);
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
	print_and_exit(WRONG_TEXTURE_EXTENTION, cub, 0);
}

void	texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (!cub->texture_file->north_path || !cub->texture_file->south_path
		|| !cub->texture_file->west_path || !cub->texture_file->east_path
		|| !cub->texture_file->door_path)
		print_and_exit(MISSING_TEXTURE, cub, 0);
	check_extention_texture(cub->texture_file->north_path, cub);
	check_extention_texture(cub->texture_file->south_path, cub);
	check_extention_texture(cub->texture_file->west_path, cub);
	check_extention_texture(cub->texture_file->east_path, cub);
	check_extention_texture(cub->texture_file->door_path, cub);
	open_texture(cub);
	free_textures(cub);
}

void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->texture->height + 1)
	{
		free(cub->texture->texture[i]);
		i++;
	}
	free(cub->texture->texture);
}
