/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:23:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/16 16:05:00 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_texture(t_texture *texture)
{
	if (!texture->north || !texture->south || !texture->west || !texture->east
		|| !texture->floor || !texture->ceiling)
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
	int y = 0;
	int check_nb_tex = 1;
	while (cub->line)
	{
		while (cub->line[y] != '\n')
		{
			while ((cub->line[y] >= 9 && cub->line[y] <= 13) || cub->line[y] == ' ')
				y++;
			if (cub->line[y] == 'N' || cub->line[y] == 'S' || cub->line[y] == 'W' || cub->line[y] == 'E' || cub->line[y] == 'F' || cub->line[y] == 'C')
			{
				check_nb_tex++;
				break ;
			}
			if (cub->line[y] == '1')
				return ;
			y++;
		}
		cub->texture->height++;
		free(cub->line);
		cub->line = get_next_line_map(fd);
		y = 0;
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


