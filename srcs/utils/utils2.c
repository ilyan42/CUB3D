/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:13:13 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 18:14:27 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	validate_floor_color_values(const char *color_values, t_cub *cub)
{
	int	i;

	i = 0;
	while (color_values[i])
	{
		if (!is_valid_floor_color_char(color_values[i]))
			print_and_exit(INVALIDE_FLOOR_COLOR, cub, 1);
		i++;
	}
}

void	validate_ceilling_color_values(const char *color_values, t_cub *cub)
{
	int	i;

	i = 0;
	while (color_values[i])
	{
		if (!is_valid_floor_color_char(color_values[i]))
			print_and_exit(INVALIDE_CEILING_COLOR, cub, 1);
		i++;
	}
}

void	free_split(char **tmp_line)
{
	int	i;

	i = 0;
	while (tmp_line[i])
	{
		free(tmp_line[i]);
		i++;
	}
	free (tmp_line);
}
