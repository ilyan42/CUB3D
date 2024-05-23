/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:57:49 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/23 13:06:49 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int move_is_good(t_cub *cub, int x, int y)
// {
// 	if (cub->map->map[y][x] != '1')
// 		return (1);
// 	return (0);
// }

// void move_left(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x;
// 	y = cub->player->pos_y;
// 	if (move_is_good(cub, x - 1, y))
// 	{
// 		cub->map->map[y][x] = '0';
// 		cub->map->map[y][x - 1] = 'N';
// 		cub->player->pos_x = x - 1;
// 	}
// }

// void move_right(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x;
// 	y = cub->player->pos_y;
// 	if (move_is_good(cub, x + 1, y))
// 	{
// 		cub->map->map[y][x] = '0';
// 		cub->map->map[y][x + 1] = 'N';
// 		cub->player->pos_x = x + 1;
// 	}
// }

// void move_forward(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x;
// 	y = cub->player->pos_y;
// 	if (move_is_good(cub, x, y - 1))
// 	{
// 		cub->map->map[y][x] = '0';
// 		cub->map->map[y - 1][x] = 'N';
// 		cub->player->pos_y = y - 1;
// 	}
// }

// void move_backward(t_cub *cub)
// {
// 	int x;
// 	int y;

// 	x = cub->player->pos_x;
// 	y = cub->player->pos_y;
// 	if (move_is_good(cub, x, y + 1))
// 	{
// 		cub->map->map[y][x] = '0';
// 		cub->map->map[y + 1][x] = 'N';
// 		cub->player->pos_y = y + 1;
// 	}
// }

// int ft_handle_key_press(int keycode, void *param)
// {
// 	t_cub *cub;

// 	cub = (t_cub *)param;
// 	if (keycode == ESCAPE_KEY || keycode == 53)
// 	{
// 		close_game(cub->mlx);
// 	}
// 	if (keycode == LEFT)
// 		rotate_left(cub);
// 	if (keycode == RIGHT)
// 		rotate_right(cub);
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