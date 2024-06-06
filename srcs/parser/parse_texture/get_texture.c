/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:49:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 11:32:37 by ilbendib         ###   ########.fr       */
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
	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture_file->north_path = malloc(path_len + 1);
		if (cub->texture_file->north_path)
		{
			strncpy(cub->texture_file->north_path, path_start, path_len);
			cub->texture_file->north_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED);
	}
	else
		print_and_exit(INVALIDE_NORTH_TEXTURE);
	return (1);
}

int	parse_south_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture_file->south_path = malloc(path_len + 1);
		if (cub->texture_file->south_path)
		{
			strncpy(cub->texture_file->south_path, path_start, path_len);
			cub->texture_file->south_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED);
	}
	else
		print_and_exit(INVALIDE_SOUTH_TEXTURE);
	return (1);
}

int	parse_west_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture_file->west_path = malloc(path_len + 1);
		if (cub->texture_file->west_path)
		{
			strncpy(cub->texture_file->west_path, path_start, path_len);
			cub->texture_file->west_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED);
	}
	else
		print_and_exit(INVALIDE_WEST_TEXTURE);
	return (1);
}

int	parse_east_texture(t_cub *cub, char *line, int x)
{
	char	*path_start;
	char	*path_end;
	size_t	path_len;

	path_start = strchr(&line[x], '.');
	path_end = strchr(&line[x], '\n');
	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture_file->east_path = malloc(path_len + 1);
		if (cub->texture_file->east_path)
		{
			strncpy(cub->texture_file->east_path, path_start, path_len);
			cub->texture_file->east_path[path_len] = '\0';
		}
		else
			print_and_exit(MALLOC_FAILED);
	}
	else
		print_and_exit(INVALIDE_EAST_TEXTURE);
	return (1);
}
