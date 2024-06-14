/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:07:01 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:09:49 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_key(t_cub *cub)
{
	cub->key = malloc(sizeof(t_key));
	if (!cub->key)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->key->forward = _false;
	cub->key->backward = _false;
	cub->key->left = _false;
	cub->key->right = _false;
	cub->key->rotate_left = _false;
	cub->key->rotate_right = _false;
	cub->key->map = _false;
	cub->key->left_shift = _false;
	cub->key->escape = _false;
	cub->key->open_door = _false;
	cub->key->map_displayed = _false;
}

void	init_struct_key_good(t_cub *cub)
{
	cub->key->good = malloc(sizeof(t_good));
	if (!cub->key->good)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->key->good->good = _false;
	cub->key->good->not_good = _false;
}

void	init_struct_raycast(t_cub *cub)
{
	cub->raycast = malloc(sizeof(t_raycast));
	if (!cub->raycast)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->raycast->step = 0;
	cub->raycast->side = 0;
	cub->raycast->tex_x = 0;
	cub->raycast->tex_y = 0;
	cub->raycast->camera_x = 0;
	cub->raycast->ray_dir_x = 0;
	cub->raycast->ray_dir_y = 0;
	cub->raycast->map_x = 0;
	cub->raycast->map_y = 0;
	cub->raycast->side_dist_x = 0;
	cub->raycast->side_dist_y = 0;
}

void	init_struct_raycast_utils(t_cub *cub)
{
	cub->raycast->delta_dist_x = 0;
	cub->raycast->delta_dist_y = 0;
	cub->raycast->perp_wall_dist = 0;
	cub->raycast->line_height = 0;
	cub->raycast->draw_start = 0;
	cub->raycast->draw_end = 0;
	cub->raycast->tex_num = 0;
	cub->raycast->step_x = 0;
	cub->raycast->step_y = 0;
	cub->raycast->hit = 0;
	cub->raycast->side = 0;
	cub->raycast->tex_num = 0;
	cub->raycast->flag = 0;
	cub->raycast->res_x = 0;
	cub->raycast->res_y = 0;
}

void	init_struct_cub(t_cub *cub)
{
	cub->res_x = 1920;
	cub->res_y = 1080;
	cub->line = NULL;
	cub->mini_map = NULL;
	cub->order_tex = NULL;
	cub->texture_file = NULL;
	cub->mlx = NULL;
	cub->image = NULL;
	cub->player = NULL;
	cub->raycast = NULL;
	cub->key = NULL;
	cub->texture->texture = NULL;
	cub->map = NULL;
	cub->shoot = _false;
	init_struct_mlx(cub);
	init_struct_map(cub);
	init_struct_image(cub);
	init_struct_key(cub);
	init_struct_player(cub);
	init_struct_color(cub);
	init_struct_key_good(cub);
	init_struct_raycast(cub);
	init_struct_raycast_utils(cub);
}
