/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:46 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 16:57:31 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	move_forward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos_x + cub->player->dir_x * cub->player->move_speed;
	new_y = cub->player->pos_y + cub->player->dir_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void	move_backward(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos_x - cub->player->dir_x * cub->player->move_speed;
	new_y = cub->player->pos_y - cub->player->dir_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void	move_left(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos_x - cub->player->plane_x * cub->player->move_speed;
	new_y = cub->player->pos_y - cub->player->plane_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void	move_right(t_cub *cub)
{
	double	new_x;
	double	new_y;

	new_x = cub->player->pos_x + cub->player->plane_x * cub->player->move_speed;
	new_y = cub->player->pos_y + cub->player->plane_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}
