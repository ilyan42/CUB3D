/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:23:09 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:11:18 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_nb_texture(t_cub *cub, int y)
{
	if (cub->line[y] == 'N' || cub->line[y] == 'S' || cub->line[y] == 'W'
		|| cub->line[y] == 'E' || cub->line[y] == 'F'
		|| cub->line[y] == 'C' || cub->line[y] == 'D')
		return (1);
	return (0);
}

int	is_in_space(char *line, int y)
{
	while ((line[y] >= 9 && line[y] <= 13) || line[y] == ' ')
		y++;
	return (y);
}

void	count_texture_height(t_cub *cub, int fd)
{
	int	y;
	int	check_nb_tex;

	y = 1;
	check_nb_tex = 1;
	cub->line = get_next_line_map(fd);
	while (cub->line)
	{
		while (cub->line[y] != '\n')
		{
			y = is_in_space(cub->line, y);
			if (check_nb_texture(cub, y))
			{
				check_nb_tex++;
				break ;
			}
			if (cub->line[y] == '1')
				return (free(cub->line));
			y++;
		}
		cub->texture->height++;
		free(cub->line);
		cub->line = get_next_line_map(fd);
		y = 0;
	}
}

char	**parse_texture_file(t_cub *cub, int fd)
{
	int	i;

	i = 0;
	cub->line = get_next_line_map(fd);
	cub->texture->texture = malloc(sizeof(char *) * (cub->texture->height + 1));
	if (!cub->texture->texture)
		print_and_exit(MALLOC_FAILED, cub, 2);
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
