/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:49:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 17:39:29 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	parse_north_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end && has_only_spaces(&line[x + 2], path_start))
	{
		path_len = path_end - path_start;
		cub->texture_file->north_path = malloc(path_len + 1);
		if (cub->texture_file->north_path)
		{
			strncpy(cub->texture_file->north_path, path_start, path_len);
			cub->texture_file->north_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED, cub, 0);
	}
	else
		print_and_exit(INVALIDE_NORTH_TEXTURE, cub, 0);
	cub->order_tex->north = true;
	return (1);
}

int	parse_south_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end && has_only_spaces(&line[x + 2], path_start))
	{
		path_len = path_end - path_start;
		cub->texture_file->south_path = malloc(path_len + 1);
		if (cub->texture_file->south_path)
		{
			strncpy(cub->texture_file->south_path, path_start, path_len);
			cub->texture_file->south_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED, cub, 0);
	}
	else
		print_and_exit(INVALIDE_SOUTH_TEXTURE, cub, 0);
	cub->order_tex->south = true;
	return (1);
}

int	parse_west_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end && has_only_spaces(&line[x + 2], path_start))
	{
		path_len = path_end - path_start;
		cub->texture_file->west_path = malloc(path_len + 1);
		if (cub->texture_file->west_path)
		{
			strncpy(cub->texture_file->west_path, path_start, path_len);
			cub->texture_file->west_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED, cub, 0);
	}
	else
		print_and_exit(INVALIDE_WEST_TEXTURE, cub, 0);
	cub->order_tex->west = true;
	return (1);
}

int	parse_east_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end && has_only_spaces(&line[x + 2], path_start))
	{
		path_len = path_end - path_start;
		cub->texture_file->east_path = malloc(path_len + 1);
		if (cub->texture_file->east_path)
		{
			strncpy(cub->texture_file->east_path, path_start, path_len);
			cub->texture_file->east_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED, cub, 0);
	}
	else
		print_and_exit(INVALIDE_EAST_TEXTURE, cub, 0);
	cub->order_tex->east = true;
	return (1);
}

int	parse_door_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end && has_only_spaces(&line[x + 2], path_start))
	{
		path_len = path_end - path_start;
		cub->texture_file->door_path = malloc(path_len + 1);
		if (cub->texture_file->door_path)
		{
			strncpy(cub->texture_file->door_path, path_start, path_len);
			cub->texture_file->door_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED, cub, 0);
	}
	else
		print_and_exit(INVALIDE_DOOR_TEXTURE, cub, 0);
	cub->order_tex->door = true;
	return (1);
}
