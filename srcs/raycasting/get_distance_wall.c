/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanson <elanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:19 by elanson           #+#    #+#             */
/*   Updated: 2024/06/14 11:35:22 by elanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_raycast(t_cub *cub, t_raycast *raycast, int x)
{
	raycast->camera_x = 2 * x / (double)cub->res_x - 1;
	raycast->ray_dir_x = cub->player->dir_x + cub->player->plane_x
		* raycast->camera_x;
	raycast->ray_dir_y = cub->player->dir_y + cub->player->plane_y
		* raycast->camera_x;
	raycast->map_x = cub->player->pos_x;
	raycast->map_y = cub->player->pos_y;
	if (raycast->ray_dir_x != 0)
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	else
		raycast->delta_dist_x = INFINITY;
	if (raycast->ray_dir_y != 0)
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	else
		raycast->delta_dist_y = INFINITY;
	raycast->hit = 0;
}

void	get_step_and_side_dist(t_cub *cub, t_raycast *raycast)
{
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (cub->player->pos_x - raycast->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - cub->player->pos_x)
			* raycast->delta_dist_x;
	}
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (cub->player->pos_y - raycast->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - cub->player->pos_y)
			* raycast->delta_dist_y;
	}
}

void	perform_dda(t_cub *cub, t_raycast *raycast)
{
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (cub->map->map[raycast->map_y][raycast->map_x] == '1'
			|| cub->map->map[raycast->map_y][raycast->map_x] == 'D')
		{
			raycast->hit = 1;
		}
		else
		{
			raycast->hit = 0;
		}
	}
}

void	get_distance(t_cub *cub, t_raycast *raycast)
{
	if (raycast->side == 0)
		cub->raycast->distance = raycast->side_dist_x
			- raycast->delta_dist_x;
	else
		cub->raycast->distance = raycast->side_dist_y
			- raycast->delta_dist_y;
	cub->raycast->line_height = (int)(cub->res_y / cub->raycast->distance);
	cub->raycast->draw_start = (int)(-cub->raycast->line_height / 2)
		+ ((int)cub->res_y / 2);
}
