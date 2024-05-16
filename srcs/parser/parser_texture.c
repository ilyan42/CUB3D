/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:23:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/16 13:16:39 by ilbendib         ###   ########.fr       */
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

void count_texture_height(t_cub *cub, int fd)
{
	cub->line = get_next_line_map(fd);
	cub->texture->height = 0;
	while (cub->line[0] == 'N' || cub->line[0] == 'S' || cub->line[0] == 'W' || cub->line[0] == 'E' || cub->line[0] == 'F' || cub->line[0] == 'C')
	{
		cub->texture->height++;
		free(cub->line);
		cub->line = get_next_line_map(fd);
	}
}


char **parse_texture_file(t_cub *cub, int fd)
{
	int i;

	i = 0;
	cub->line = get_next_line_map(fd);
	cub->texture->texture = malloc(sizeof(char *) * (cub->texture->height + 1));
	while ((cub->line && i < cub->texture->height))
	{
		cub->texture->texture[i] = ft_strdup(cub->line);
		free(cub->line);
		cub->line = get_next_line_map(fd);
		i++;
	}
	cub->texture->texture[i] = NULL;
	return (cub->texture->texture);
}


