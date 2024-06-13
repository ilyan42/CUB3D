/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:55:16 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 18:14:19 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	convert_color_hex(t_cub *cub)
{
	cub->color->color_floor = ((cub->color->f_r & 0xff) << 16)
		+ ((cub->color->f_g & 0xff) << 8) + (cub->color->f_b & 0xff);
	cub->color->color_ceiling = ((cub->color->c_r & 0xff) << 16)
		+ ((cub->color->c_g & 0xff) << 8) + (cub->color->c_b & 0xff);
}

int	check_nb_floor(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] >= '0' && str[i] <= '9' && str[i + 1] == ' ')
			|| (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '\t'))
			print_and_exit(INVALIDE_FLOOR_COLOR, cub, 1);
		i++;
	}
	return (1);
}

int	check_nb_ceilling(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] >= '0' && str[i] <= '9' && str[i + 1] == ' ')
			|| (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '\t'))
			print_and_exit(INVALIDE_CEILING_COLOR, cub, 1);
		i++;
	}
	return (1);
}

int	parse_floor_color(t_cub *cub, char *line)
{
	char	**tmp_line;
	char	*color_values;
	int		nb;

	nb = 0;
	color_values = strchr(line, ' ');
	validate_floor_color_values(color_values, cub);
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
		while (tmp_line[nb])
			nb += check_nb_floor(tmp_line[nb], cub);
	if (nb != 3)
		print_and_exit(INVALIDE_FLOOR_COLOR, cub, 1);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->f_r = ft_atoi(tmp_line[0]);
		cub->color->f_g = ft_atoi(tmp_line[1]);
		cub->color->f_b = ft_atoi(tmp_line[2]);
	}
	if (cub->color->f_r > 255 || cub->color->f_g > 255 || cub->color->f_b > 255)
		print_and_exit(INVALIDE_FLOOR_COLOR, cub, 1);
	convert_color_hex(cub);
	cub->order_tex->floor = true;
	free_split(tmp_line);
	return (1);
}

int	parse_ceiling_color(t_cub *cub, char *line)
{
	char	**tmp_line;
	char	*color_values;
	int		nb;

	nb = 0;
	color_values = strchr(line, ' ');
	validate_ceilling_color_values(color_values, cub);
	tmp_line = ft_split(color_values, ',');
	if (tmp_line)
		while (tmp_line[nb])
			nb += check_nb_ceilling(tmp_line[nb], cub);
	if (nb != 3)
		print_and_exit(INVALIDE_CEILING_COLOR, cub, 1);
	if (tmp_line[0] && tmp_line[1] && tmp_line[2])
	{
		cub->color->c_r = ft_atoi(tmp_line[0]);
		cub->color->c_g = ft_atoi(tmp_line[1]);
		cub->color->c_b = ft_atoi(tmp_line[2]);
	}
	if (cub->color->c_r > 255 || cub->color->c_b > 255 || cub->color->c_g > 255)
		print_and_exit(INVALIDE_CEILING_COLOR, cub, 1);
	convert_color_hex(cub);
	cub->order_tex->ceiling = true;
	free_split(tmp_line);
	return (1);
}
