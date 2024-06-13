/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:50:04 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/12 16:36:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_weapon_utils(t_cub *cub)
{
	cub->gun_[2]->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			"texture/3.xpm", &cub->gun_[2]->width, &cub->gun_[2]->height);
	cub->gun_[2]->addr = mlx_get_data_addr(cub->gun_[2]->img, &cub->gun_[2]
			-> bits_per_pixel, &cub->gun_[2]->line_length,
			&cub->gun_[2]->endian);
	cub->gun_[3] = malloc(sizeof(t_image));
	if (!cub->gun_[3])
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->gun_[3]->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			"texture/4.xpm", &cub->gun_[3]->width, &cub->gun_[3]->height);
	cub->gun_[3]->addr = mlx_get_data_addr(cub->gun_[3]->img, &cub->gun_[3]
			-> bits_per_pixel, &cub->gun_[3]->line_length,
			&cub->gun_[3]->endian);
	cub->gun_[4] = malloc(sizeof(t_image));
	if (!cub->gun_[4])
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->gun_[4]->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			"texture/5.xpm", &cub->gun_[4]->width, &cub->gun_[4]->height);
	cub->gun_[4]->addr = mlx_get_data_addr(cub->gun_[4]->img, &cub->gun_[4]
			-> bits_per_pixel, &cub->gun_[4]->line_length,
			&cub->gun_[4]->endian);
}
