/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:46 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/22 15:07:15 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	move_forward(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x + cub->player->dir_x * (MOVE_SPEED);
// 	y = cub->player->pos_y + cub->player->dir_y * (MOVE_SPEED);
// 	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
// 		cub->player->pos_x += cub->player->dir_x * (MOVE_SPEED);
// 	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
// 		cub->player->pos_y += cub->player->dir_y * (MOVE_SPEED);
// }

// void	move_backward(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x - cub->player->dir_x * (MOVE_SPEED);
// 	y = cub->player->pos_y - cub->player->dir_y * (MOVE_SPEED);
// 	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
// 		cub->player->pos_x -= cub->player->dir_x * (MOVE_SPEED);
// 	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
// 		cub->player->pos_y -= cub->player->dir_y * (MOVE_SPEED);
// }

// void	move_left(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x - cub->player->plane_x * (MOVE_SPEED);
// 	y = cub->player->pos_y - cub->player->plane_y * (MOVE_SPEED);
// 	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
// 		cub->player->pos_x -= cub->player->plane_x * (MOVE_SPEED);
// 	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
// 		cub->player->pos_y -= cub->player->plane_y * (MOVE_SPEED);
// }

// void	move_right(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x + cub->player->plane_x * (MOVE_SPEED);
// 	y = cub->player->pos_y + cub->player->plane_y * (MOVE_SPEED);
// 	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
// 		cub->player->pos_x += cub->player->plane_x * (MOVE_SPEED);
// 	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
// 		cub->player->pos_y += cub->player->plane_y * (MOVE_SPEED);
// }

// int ft_handle_key_press(int keycode, void *param)
// {
// 	t_cub *cub;

// 	cub = (t_cub *)param;
// 	if (keycode == ESCAPE_KEY || keycode == 53)
// 	{
// 		close_game(cub->mlx);
// 	}
// 	if (keycode == W)
// 		move_forward(cub);
// 	if (keycode == S_QW)
// 		move_backward(cub);
// 	if (keycode == A)
// 		move_left(cub);
// 	if (keycode == D_QW)
// 		move_right(cub);
// 	return (1);
// }