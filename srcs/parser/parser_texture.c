/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:23:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/14 20:03:46 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_texture(t_texture *texture)
{
	if (!texture->north || !texture->south || !texture->west || !texture->east
		|| !texture->sprite)
	{
		printf("Error: texture not found\n");
		return (0);
	}
	return (1);
}

void count_texture_height(t_texture *texture, int fd)
{
	char *line;

	line = get_next_line_map(fd);
	texture->height = 0;
	while (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E' || line[0] == 'F' || line[0] == 'C')
	{
		texture->height++;
		free(line);
		line = get_next_line_map(fd);
	}
}


void parse_texture_file(t_cub *cub, int fd)
{
	char	*line;
	int i;

	i = 0;
	line = get_next_line_map(fd);
	// printf("line = %s\n", line);
	cub->map->map = malloc(sizeof(char *) * (cub->texture->height + 1));
	while ((line && i < cub->texture->height))
	{
		cub->map->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line_map(fd);
		// printf ("line = %s\n", line);
		i++;
	}
	cub->map->map[i] = NULL;
}


