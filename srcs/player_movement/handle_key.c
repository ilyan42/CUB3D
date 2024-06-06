/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:53:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 17:58:09 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cam_rotate_left(t_cub *data)
{
	data->player->angle -= ROTATE_SPEED;
	data->player->dir_x = cos(data->player->angle);
	data->player->dir_y = sin(data->player->angle);
	data->player->plane_x = cos(data->player->angle + M_PI);
	data->player->plane_x = sin(data->player->angle + M_PI);
}

void	cam_rotate_right(t_cub *data)
{
	data->player->angle += ROTATE_SPEED;
	data->player->dir_x = cos(data->player->angle);
	data->player->dir_y = sin(data->player->angle);
	data->player->plane_x = cos(data->player->angle + M_PI);
	data->player->plane_y = sin(data->player->angle + M_PI);
}

int	key_press(int key, t_cub *data)
{
	if (key == LEFT)
		data->key->rotate_left = _true;
	else if (key == RIGHT)
		data->key->rotate_right = _true;
	else if (key == W)
		data->key->forward = _true;
	else if (key == S_QW)
		data->key->backward = _true;
	else if (key == A)
		data->key->left = _true;
	else if (key == D_QW)
		data->key->right = _true;
	else if (key == ESCAPE_KEY)
		close_game(data);
	else if (key == MAP)
	{
		data->key->map = _true;
		data->key->map_displayed = !data->key->map_displayed;
	}
	else if (key == LEFT_SHIFT)
		data->key->left_shift = _true;
	else if (key == E)
		data->key->open_door = _true;
	return (0);
}

int	key_release(int key, t_cub *data)
{
	if (key == LEFT)
		data->key->rotate_left = _false;
	else if (key == RIGHT)
		data->key->rotate_right = _false;
	else if (key == W)
		data->key->forward = _false;
	else if (key == S_QW)
		data->key->backward = _false;
	else if (key == A)
		data->key->left = _false;
	else if (key == D_QW)
		data->key->right = _false;
	else if (key == MAP)
		data->key->map = _false;
	else if (key == LEFT_SHIFT)
		data->key->left_shift = _false;
	else if (key == E)
		data->key->open_door = _false;
	return (0);
}

int	ft_handle_key_press(t_cub *cub)
{
	if (cub->key->rotate_left)
		cam_rotate_left(cub);
	if (cub->key->rotate_right)
		cam_rotate_right(cub);
	if (cub->key->forward)
		move_forward(cub);
	if (cub->key->left)
		move_left(cub);
	if (cub->key->right)
		move_right(cub);
	if (cub->key->backward)
		move_backward(cub);
	if (cub->key->left_shift)
		cub->player->move_speed = 0.1;
	else
		cub->player->move_speed = 0.05;
	if (cub->key->map)
		cub->key->good->good = _true;
	if (cub->key->open_door)
		open_close_door(cub);
	if (cub->key->escape)
		close_game(cub);
	maj_plane_player(cub);
	return (1);
}
