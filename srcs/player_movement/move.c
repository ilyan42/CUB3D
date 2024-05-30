/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:46 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/30 18:40:51 by ilbendib         ###   ########.fr       */
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




void	move_forward(t_cub *cub)
{
	float	x;
	float	y;

	x = cub->player->pos_x + cub->player->plane_x * cub->player->move_speed;
	y = cub->player->pos_y - cub->player->plane_x * cub->player->move_speed;
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x += cub->player->plane_y * cub->player->move_speed;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y -= cub->player->plane_x * cub->player->move_speed;
}

void	move_backward(t_cub *cub)
{
	float	x;
	float	y;

	x = cub->player->pos_x - cub->player->plane_y * cub->player->move_speed;
	y = cub->player->pos_y + cub->player->plane_x * cub->player->move_speed;
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x -= cub->player->plane_y * cub->player->move_speed;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y += cub->player->plane_x * cub->player->move_speed;
}



void	move_left(t_cub *cub)
{
	int x;
	int y;

	x = cub->player->pos_x - cub->player->plane_x * cub->player->move_speed;
	y = cub->player->pos_y - cub->player->plane_y * cub->player->move_speed;
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x -= cub->player->plane_x * cub->player->move_speed;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y -= cub->player->plane_y * cub->player->move_speed;
}

void	move_right(t_cub *cub)
{
	int x;
	int y;

	x = cub->player->pos_x + cub->player->plane_x * cub->player->move_speed;
	y = cub->player->pos_y + cub->player->plane_y * cub->player->move_speed;
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x += cub->player->plane_x * cub->player->move_speed;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y += cub->player->plane_y * cub->player->move_speed;
}

void maj_plane_player(t_cub *cub)
{
	cub->player->plane_x = -cub->player->dir_y * FOV_RAD;
	cub->player->plane_y = cub->player->dir_x * FOV_RAD;
}

int	key_press(int key, t_cub *data)
{
	if (key == LEFT)
		data->mini_map->key->rotate_left = _true;
	else if (key == RIGHT)
		data->mini_map->key->rotate_right = _true;
	else if (key == W)
		data->mini_map->key->forward = _true;
	else if (key == S_QW)
		data->mini_map->key->backward = _true;
	else if (key == A)
		data->mini_map->key->left = _true;
	else if (key == D_QW)
		data->mini_map->key->right = _true;
	else if (key == ESCAPE_KEY)
		close_game(data->mlx);
	else if (key == MAP)
		data->mini_map->key->map = _true;
	else if (key == LEFT_SHIFT)
		data->mini_map->key->left_shift = _true;
	return (0);
}

int	key_release(int key, t_cub *data)
{
	if (key == LEFT)
		data->mini_map->key->rotate_left = _false;
	else if (key == RIGHT)
		data->mini_map->key->rotate_right = _false;
	else if (key == W)
		data->mini_map->key->forward = _false;
	else if (key == S_QW)
		data->mini_map->key->backward = _false;
	else if (key == A)
		data->mini_map->key->left = _false;
	else if (key == D_QW)
		data->mini_map->key->right = _false;
	else if (key == MAP)
		data->mini_map->key->map = _false;
	else if (key == LEFT_SHIFT)
		data->mini_map->key->left_shift = _false;
	return (0);
}

int ft_handle_key_press(t_cub *cub)
{
	if (cub->mini_map->key->escape)
		close_game(cub->mlx);
	if (cub->mini_map->key->rotate_left)
		cam_rotate_left(cub);
	if (cub->mini_map->key->rotate_right)
		cam_rotate_right(cub);
	if (cub->mini_map->key->forward)
		move_forward(cub);
	if (cub->mini_map->key->left)
		move_left(cub);
	if (cub->mini_map->key->right)
		move_right(cub);
	if (cub->mini_map->key->backward)
		move_backward(cub);
	if (cub->mini_map->key->left_shift)
		cub->player->move_speed = 0.1;
	else
		cub->player->move_speed = 0.05;
	if (cub->mini_map->key->map)
		cub->mini_map->key->good->good = _true;
	maj_plane_player(cub);
	return (1);
}



