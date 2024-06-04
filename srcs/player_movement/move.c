/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:46 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 14:51:25 by ilbendib         ###   ########.fr       */
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

int is_position_valid(t_cub *cub, double new_x, double new_y)
{
	const double MIN_DIST = 0.1;  // Distance minimale (10 pixels)

	int map_x = (int)new_x;
	int map_y = (int)new_y;

	// Vérifier les quatre coins autour de la nouvelle position pour la collision
	if (cub->map->map[map_y][map_x] == '1')
		return (0);
	if (cub->map->map[map_y][(int)(new_x + MIN_DIST)] == '1')
		return (0);
	if (cub->map->map[map_y][(int)(new_x - MIN_DIST)] == '1')
		return (0);
	if (cub->map->map[(int)(new_y + MIN_DIST)][map_x] == '1')
		return (0);
	if (cub->map->map[(int)(new_y - MIN_DIST)][map_x] == '1')
		return (0);
	return (1);
}

void move_forward(t_cub *cub)
{
	double new_x = cub->player->pos_x + cub->player->dir_x * cub->player->move_speed;
	double new_y = cub->player->pos_y + cub->player->dir_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void move_backward(t_cub *cub)
{
	double new_x = cub->player->pos_x - cub->player->dir_x * cub->player->move_speed;
	double new_y = cub->player->pos_y - cub->player->dir_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void move_left(t_cub *cub)
{
	double new_x = cub->player->pos_x - cub->player->plane_x * cub->player->move_speed;
	double new_y = cub->player->pos_y - cub->player->plane_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void move_right(t_cub *cub)
{
	double new_x = cub->player->pos_x + cub->player->plane_x * cub->player->move_speed;
	double new_y = cub->player->pos_y + cub->player->plane_y * cub->player->move_speed;
	if (is_position_valid(cub, new_x, cub->player->pos_y))
		cub->player->pos_x = new_x;
	if (is_position_valid(cub, cub->player->pos_x, new_y))
		cub->player->pos_y = new_y;
}

void maj_plane_player(t_cub *cub)
{
	cub->player->plane_x = -cub->player->dir_y * FOV_RAD;
	cub->player->plane_y = cub->player->dir_x * FOV_RAD;
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
		close_game(data->mlx);
	else if (key == MAP)
		data->key->map = _true;
	else if (key == LEFT_SHIFT)
		data->key->left_shift = _true;
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
	return (0);
}

int ft_handle_key_press(t_cub *cub)
{
	if (cub->key->escape)
		close_game(cub->mlx);
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
	maj_plane_player(cub);
	return (1);
}



