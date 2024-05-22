/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:21:29 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/22 15:22:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player->dir_x;
	cub->player->dir_x = cub->player->dir_x * cos(ROTATE_SPEED) - cub->player->dir_y * sin(ROTATE_SPEED);
	cub->player->dir_y = old_dir_x * sin(ROTATE_SPEED) + cub->player->dir_y * cos(ROTATE_SPEED);
	old_plane_x = cub->player->plane_x;
	cub->player->plane_x = cub->player->plane_x * cos(ROTATE_SPEED) - cub->player->plane_y * sin(ROTATE_SPEED);
	cub->player->plane_y = old_plane_x * sin(ROTATE_SPEED) + cub->player->plane_y * cos(ROTATE_SPEED);
}

void	rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player->dir_x;
	cub->player->dir_x = cub->player->dir_x * cos(-ROTATE_SPEED) - cub->player->dir_y * sin(-ROTATE_SPEED);
	cub->player->dir_y = old_dir_x * sin(-ROTATE_SPEED) + cub->player->dir_y * cos(-ROTATE_SPEED);
	old_plane_x = cub->player->plane_x;
	cub->player->plane_x = cub->player->plane_x * cos(-ROTATE_SPEED) - cub->player->plane_y * sin(-ROTATE_SPEED);
	cub->player->plane_y = old_plane_x * sin(-ROTATE_SPEED) + cub->player->plane_y * cos(-ROTATE_SPEED);
}


