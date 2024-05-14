/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:05 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/14 20:03:25 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void count_map_height(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line_map(fd);
	cub->map->height = 0;
	while (line)
	{
		cub->map->height++;
		free(line);
		line = get_next_line_map(fd);
	}
}

void allocate_and_fill_map(t_map *map, int fd)
{
	char *line;
	int i;

	i = 0;
	line = get_next_line_map(fd);
	// printf ("line = %s\n", line);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	while (line && i < map->height)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line_map(fd);
		// printf ("line = %s\n", line);
		i++;
	}
	map->map[i] = NULL;
}

void is_cub_file(char *map)
{
	char	*extensions_check;

	extensions_check = ft_strnstr(map, ".cub", ft_strlen(map));
	if (extensions_check == NULL || ft_strlen(extensions_check) != 4)
	{
		ft_printf("Error\nExtensions check\n");
		exit(EXIT_FAILURE);
	}
}

void	parsing_map(char *file, t_cub *cub)
{
	int fd;
	int i = -1;

	is_cub_file(file);
	fd = open(file, O_RDONLY);
	count_texture_height(cub->texture, fd);
	printf ("height = %d\n", cub->texture->height);
	count_map_height(cub, fd);
	printf ("height = %d\n", cub->map->height);
	close(fd);
	fd = open(file, O_RDONLY);
	parse_texture_file(cub, fd);
	allocate_and_fill_map(cub->map, fd);
	printf ("ici\n");
	while (cub->map->map[++i])
		printf ("map = %s\n", cub->map->map[i]);
	close(fd);
}