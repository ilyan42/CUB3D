/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:46 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/23 18:21:30 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void cam_rotate_left(t_cub *cube)
// {
// 	float old_dir_x;
// 	float old_plane_x;

// 	old_dir_x = cube->player->dir_x;
// 	old_plane_x = cube->player->plane_x;
// 	cube->player->dir_x = cube->player->dir_x * cos(ROT_SPEED) - cube->player->dir_y * sin(ROT_SPEED);
// 	cube->player->dir_y = old_dir_x * sin(ROT_SPEED) + cube->player->dir_y * cos(ROT_SPEED);
// 	cube->player->plane_x = cube->player->plane_x * cos(ROT_SPEED) - cube->player->plane_y * sin(ROT_SPEED);
// 	cube->player->plane_y = old_plane_x * sin(ROT_SPEED) + cube->player->plane_y * cos(ROT_SPEED);
// }

// void cam_rotate_right(t_cub *cube)
// {
// 	float old_dir_x;
// 	float old_plane_x;

// 	old_dir_x = cube->player->dir_x;
// 	old_plane_x = cube->player->plane_x;
// 	cube->player->dir_x = cube->player->dir_x * cos(-ROT_SPEED) - cube->player->dir_y * sin(-ROT_SPEED);
// 	cube->player->dir_y = old_dir_x * sin(-ROT_SPEED) + cube->player->dir_y * cos(-ROT_SPEED);
// 	cube->player->plane_x = cube->player->plane_x * cos(-ROT_SPEED) - cube->player->plane_y * sin(-ROT_SPEED);
// 	cube->player->plane_y = old_plane_x * sin(-ROT_SPEED) + cube->player->plane_y * cos(-ROT_SPEED);
// }

// void	cam_rotate_left(t_cub *data)
// {
// 	data->player->angle -= ROTATE_SPEED;
// 	data->player->dir_x = cos(data->player->angle);
// 	data->player->dir_y = sin(data->player->angle);
// 	data->player->plane_x = cos(data->player->angle + M_PI);
// 	data->player->plane_x = sin(data->player->angle + M_PI);
// }

// void	cam_rotate_right(t_cub *data)
// {
// 	data->player->angle += ROTATE_SPEED;
// 	data->player->dir_x = cos(data->player->angle);
// 	data->player->dir_y = sin(data->player->angle);
// 	data->player->plane_x = cos(data->player->angle + M_PI);
// 	data->player->plane_y = sin(data->player->angle + M_PI);
// }




void	move_right(t_cub *cub)
{
	float	x;
	float	y;

	printf ("cub->player->pos_x = %f\n", cub->player->pos_x);
	printf ("cub->player->pos_y = %f\n", cub->player->pos_y);
	x = cub->player->pos_x + cub->player->plane_x * (MOVE_SPEED);
	y = cub->player->pos_y - cub->player->plane_x * (MOVE_SPEED);
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x += cub->player->plane_y * MOVE_SPEED;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y -= cub->player->plane_x * MOVE_SPEED;
}

void	move_left(t_cub *cub)
{
	float	x;
	float	y;

	x = cub->player->pos_x - cub->player->plane_y * (MOVE_SPEED);
	y = cub->player->pos_y + cub->player->plane_x * (MOVE_SPEED);
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x -= cub->player->plane_y * MOVE_SPEED;
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y += cub->player->plane_x * MOVE_SPEED;
}



void	move_forward(t_cub *cub)
{
	int x;
	int y;

	x = cub->player->pos_x - cub->player->plane_x * (MOVE_SPEED);
	y = cub->player->pos_y - cub->player->plane_y * (MOVE_SPEED);
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x -= cub->player->plane_x * (MOVE_SPEED);
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y -= cub->player->plane_y * (MOVE_SPEED);
}

void	move_backward(t_cub *cub)
{
	int x;
	int y;

	x = cub->player->pos_x + cub->player->plane_x * (MOVE_SPEED);
	y = cub->player->pos_y + cub->player->plane_y * (MOVE_SPEED);
	if (cub->map->map[(int)cub->player->pos_y][(int)x] != '1')
		cub->player->pos_x += cub->player->plane_x * (MOVE_SPEED);
	if (cub->map->map[(int)y][(int)cub->player->pos_x] != '1')
		cub->player->pos_y += cub->player->plane_y * (MOVE_SPEED);
}

int ft_handle_key_press(int keycode, void *param)
{
	t_cub *cub;

	cub = (t_cub *)param;
	if (keycode == ESCAPE_KEY || keycode == 53)
	{
		close_game(cub->mlx);
	}
	// if (keycode == LEFT)
	// 	cam_rotate_left(cub);
	// if (keycode == RIGHT)
	// 	cam_rotate_right(cub);
	if (keycode == W)
		move_forward(cub);
	if (keycode == S_QW)
		move_backward(cub);
	if (keycode == A)
		move_left(cub);
	if (keycode == D_QW)
		move_right(cub);
	// printf ("keycode = %d\n", keycode);
	return (1);
}


