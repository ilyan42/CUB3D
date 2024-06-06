/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:05 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 11:32:21 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	count_map_height(t_cub *cub, int fd)
{
	cub->line = get_next_line_map(fd);
	cub->map->height = 1;
	while (cub->line)
	{
		cub->map->height++;
		free(cub->line);
		cub->line = get_next_line_map(fd);
	}
}

char	**allocate_and_fill_map(t_cub *cub, int fd)
{
	int	i;

	i = 1;
	cub->map->map = malloc(sizeof(char *) * (cub->map->height + 1));
	if (!cub->map->map)
		print_and_exit(MALLOC_FAILED);
	cub->map->map[0] = cub->line;
	cub->line = get_next_line_map(fd);
	while (cub->line && i <= cub->map->height)
	{
		cub->map->map[i] = ft_strdup(cub->line);
		free(cub->line);
		cub->line = get_next_line_map(fd);
		i++;
	}
	cub->map->map[i] = NULL;
	if (cub->line)
		free(cub->line);
	return (cub->map->map);
}

void	is_cub_file(char *map)
{
	char	*extensions_check;

	extensions_check = ft_strnstr(map, ".cub", ft_strlen(map));
	if (extensions_check == NULL || ft_strlen(extensions_check) != 4)
		print_and_exit(INVALIDE_FILE_EXTENSION);
}

void	get_map_and_tex(char *file, t_cub *cub)
{
	int	fd;

	cub->line = NULL;
	is_cub_file(file);
	fd = open(file, O_RDONLY);
	cub->texture->height = 0;
	count_texture_height(cub, fd);
	count_map_height(cub, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	cub->texture->texture = parse_texture_file(cub, fd);
	cub->map->map = allocate_and_fill_map(cub, fd);
	close(fd);
}
