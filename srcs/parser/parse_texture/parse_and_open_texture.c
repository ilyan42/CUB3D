/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/16 18:57:35 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void parse_ceiling_texture(t_cub *cub, char *line, int x)
{
	char *path_start = strchr(&line[x], '.');
	char *path_end = strchr(&line[x], '\n');
	size_t path_len;

	if (path_start && path_end)
	{
		path_len = path_end - path_start;
		cub->texture->ceiling = malloc(path_len + 1);
		if (cub->texture->ceiling)
		{
			strncpy(cub->texture->ceiling, path_start, path_len);
			cub->texture->ceiling[path_len] = '\0';
		}
		else
		{
			printf("Error: Memory allocation failed for the ceiling texture\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error: Invalid ceiling texture format\n");
		exit(EXIT_FAILURE);
	}
}


void parsing_texture(t_cub *cub)
{
	int y = 0;
	int x = 0;
	int check = 0;

	while (cub->texture->texture[y])
	{
		char *line = cub->texture->texture[y];
		x = 0;
		while (line[x])
		{
			if (line[x] == 'N' && line[x + 1] == 'O')
			{
				parse_north_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'S' && line[x + 1] == 'O')
			{
				parse_south_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'W' && line[x + 1] == 'E')
			{
				parse_west_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'E' && line[x + 1] == 'A')
			{
				parse_east_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'F')
			{
				parse_floor_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'C')
			{
				parse_ceiling_texture(cub, line, x);
				check++;
			}
			x++;
		}
		y++;
	}
	printf ("\n%s\n", cub->texture->north);
	printf ("%s\n", cub->texture->south);
	printf ("%s\n", cub->texture->west);
	printf ("%s\n", cub->texture->east);
	printf ("%s\n", cub->texture->floor);
	printf ("%s\n", cub->texture->ceiling);
	if (check != 6) {
		printf("Error: Wrong number of textures\n");
		exit(EXIT_FAILURE);
	}
}


int open_texture(t_cub *cub)
{
	int fd;
	
	fd = open(cub->texture->north, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n -> open north texture\n");
		return (0);
	}
	close(fd);
	fd = open(cub->texture->south, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n -> open south texture\n");
		return (0);
	}
	close(fd);
	fd = open(cub->texture->west, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n -> open west texture\n");
		return (0);
	}
	close(fd);
	fd = open(cub->texture->east, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n -> open east texture\n");
		return (0);
	}
	close(fd);
	return (1);
}


void texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (open_texture(cub) == 0)
		exit(EXIT_FAILURE);
}