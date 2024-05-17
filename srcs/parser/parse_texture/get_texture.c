/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:49:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/17 19:01:31 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void parse_north_texture(t_cub *cub, char *line, int x)
{
	char *path_start = strchr(&line[x], '.');
	char *path_end = strchr(&line[x], '\n');
	size_t path_len;

	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture->north = malloc(path_len + 1);
		if (cub->texture->north)
		{
			strncpy(cub->texture->north, path_start, path_len);
			cub->texture->north[path_len] = '\0';
		}
		else
		{
			printf("Error: Memory allocation failed for the north texture\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error: Invalid north texture format\n");
		exit(EXIT_FAILURE);
	}
}

void parse_south_texture(t_cub *cub, char *line, int x)
{
	char *path_start = strchr(&line[x], '.');
	char *path_end = strchr(&line[x], '\n');
	size_t path_len;

	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture->south = malloc(path_len + 1);
		if (cub->texture->south)
		{
			strncpy(cub->texture->south, path_start, path_len);
			cub->texture->south[path_len] = '\0';
		}
		else
		{
			printf("Error: Memory allocation failed for the south texture\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error: Invalid south texture format\n");
		exit(EXIT_FAILURE);
	}
}

void parse_west_texture(t_cub *cub, char *line, int x)
{
	char *path_start = strchr(&line[x], '.');
	char *path_end = strchr(&line[x], '\n');
	size_t path_len;

	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture->west = malloc(path_len + 1);
		if (cub->texture->west)
		{
			strncpy(cub->texture->west, path_start, path_len);
			cub->texture->west[path_len] = '\0';
		}
		else
		{
			printf("Error: Memory allocation failed for the west texture\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error: Invalid west texture format\n");
		exit(EXIT_FAILURE);
	}
}

void parse_east_texture(t_cub *cub, char *line, int x)
{
	char *path_start = strchr(&line[x], '.');
	char *path_end = strchr(&line[x], '\n');
	size_t path_len;

	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture->east = malloc(path_len + 1);
		if (cub->texture->east)
		{
			strncpy(cub->texture->east, path_start, path_len);
			cub->texture->east[path_len] = '\0';
		}
		else
		{
			printf("Error: Memory allocation failed for the east texture\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error: Invalid east texture format\n");
		exit(EXIT_FAILURE);
	}
}

void parse_floor_color(t_cub *cub, char *line)
{
	char **tmp_line;
	char *color_values;
	int nb;

	nb = 0;
	color_values = strchr(line, ' ');
	if (color_values) color_values++;
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
	{
		while (tmp_line[nb])
			nb++;
	}
	if (nb != 3)
		print_and_exit(INVALIDE_FLOOR_COLOR);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->F_r = ft_atoi(tmp_line[0]);
		cub->color->F_g = ft_atoi(tmp_line[1]);
		cub->color->F_b = ft_atoi(tmp_line[2]);
	}
}

void parse_ceiling_color(t_cub *cub, char *line)
{
	char **tmp_line;
	char *color_values;
	int nb;

	nb = 0;
	color_values = strchr(line, ' ');
	if (color_values) color_values++;
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
	{
		while (tmp_line[nb])
			nb++;
	}
	if (nb != 3)
		print_and_exit(INVALIDE_CEILING_COLOR);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->C_r = ft_atoi(tmp_line[0]);
		cub->color->C_g = ft_atoi(tmp_line[1]);
		cub->color->C_b = ft_atoi(tmp_line[2]);
	}
}
