/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:55:16 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 17:55:19 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	convert_color_hex(t_cub *cub)
{
	cub->color->color_floor = ((cub->color->F_r & 0xff) << 16)
		+ ((cub->color->F_g & 0xff) << 8) + (cub->color->F_b & 0xff);
	cub->color->color_ceiling = ((cub->color->C_r & 0xff) << 16)
		+ ((cub->color->C_g & 0xff) << 8) + (cub->color->C_b & 0xff);
}

int	parse_floor_color(t_cub *cub, char *line)
{
	char	**tmp_line;
	char	*color_values;
	int		nb;

	nb = 0;
	color_values = strchr(line, ' ');
	if (color_values)
		color_values++;
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
		while (tmp_line[nb])
			nb++;
	if (nb != 3)
		print_and_exit(INVALIDE_FLOOR_COLOR);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->F_r = ft_atoi(tmp_line[0]);
		cub->color->F_g = ft_atoi(tmp_line[1]);
		cub->color->F_b = ft_atoi(tmp_line[2]);
	}
	if (cub->color->C_r > 255 || cub->color->C_b > 255 || cub->color->C_g > 255)
		print_and_exit(INVALIDE_CEILING_COLOR);
	convert_color_hex(cub);
	return (1);
}

int	parse_ceiling_color(t_cub *cub, char *line)
{
	char	**tmp_line;
	char	*color_values;
	int		nb;

	nb = 0;
	color_values = strchr(line, ' ');
	if (color_values)
		color_values++;
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
		while (tmp_line[nb])
			nb++;
	if (nb != 3)
		print_and_exit(INVALIDE_CEILING_COLOR);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->C_r = ft_atoi(tmp_line[0]);
		cub->color->C_g = ft_atoi(tmp_line[1]);
		cub->color->C_b = ft_atoi(tmp_line[2]);
	}
	if (cub->color->C_r > 255 || cub->color->C_b > 255 || cub->color->C_g > 255)
		print_and_exit(INVALIDE_CEILING_COLOR);
	convert_color_hex(cub);
	return (1);
}