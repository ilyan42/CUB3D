/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/30 18:35:51 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int close_game(t_minilibx *game)
{
	(void)game;
	printf("\nProgramme terminé.\n");
	exit(EXIT_SUCCESS);
	return (0);
}


void 	init_window(t_minilibx *window, t_cub *cub)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
	{
		printf("Error: environement not set\n");
		return (exit(0), (void)0);
	}
	window->win = mlx_new_window(window->mlx_ptr, cub->res_x, cub->res_y, "cub3d");
}

void init_all_struct(t_cub *cub)
{
	cub->res_x = 1920;
	cub->res_y = 1080;
	cub->mlx = malloc(sizeof(t_minilibx));
	if (!cub->mlx)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->mlx->mlx_ptr = NULL;
	cub->mlx->win = NULL;
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->map->map = NULL;
	cub->map->size_x = 0;
	cub->map->size_y = 0;
	cub->map->height = 0;
	cub->map->width = 0;
	cub->image = malloc(sizeof(t_image));
	if (!cub->image)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->image->img = NULL;
	cub->image->NO_img = NULL;
	cub->image->SO_img = NULL;
	cub->image->WE_img = NULL;
	cub->image->EA_img = NULL;
	cub->image->addr = NULL;
	cub->image->bits_per_pixel = 0;
	cub->image->line_length = 0;
	cub->image->endian = 0;
	cub->image->width = 0;
	cub->image->height = 0;
	cub->image->path = NULL;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->texture->north_path = NULL;
	cub->texture->south_path = NULL;
	cub->texture->west_path = NULL;
	cub->texture->east_path = NULL;
	cub->texture->floor = NULL;
	cub->texture->ceiling = NULL;
	cub->texture->height = 0;
	cub->texture->texture = NULL;
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->player->pos_x = 0;
	cub->player->pos_y = 0;
	cub->player->dir_x = 0;
	cub->player->dir_y = 0;
	cub->player->plane_x = 0;
	cub->player->plane_y = 0;
	cub->player->angle = 0;
	cub->player->move_speed = 0.05;
	cub->player->rot_speed = 0;
	cub->player->fov_angle = 0;
	cub->player->fov_rad = (FOV * M_PI) / 180;
	cub->raycast = malloc(sizeof(t_raycast));
	if (!cub->raycast)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->raycast->ray_angle = 0;
	cub->raycast->distance = 0;
	cub->raycast->tex_pos = 0;
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
	cub->color->C_b = 0;
	cub->color->C_g = 0;
	cub->color->C_r = 0;
	cub->color->F_b = 0;
	cub->color->F_g = 0;
	cub->color->F_r = 0;
	cub->color->color_ceiling = 0;
	cub->color->color_floor = 0;
	cub->mini_map->key = malloc(sizeof(t_key));
	if (!cub->mini_map->key)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->mini_map->key->forward = _false;
	cub->mini_map->key->backward = _false;
	cub->mini_map->key->left = _false;
	cub->mini_map->key->right = _false;
	cub->mini_map->key->rotate_left = _false;
	cub->mini_map->key->rotate_right = _false;
	cub->mini_map->key->map = _false;
	cub->mini_map->key->left_shift = _false;
	cub->mini_map->key->good = malloc(sizeof(t_key));
	if (!cub->mini_map->key->good)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->mini_map->key->good->good = _false;
	cub->mini_map->key->good->not_good = _false;
}



int update(void *param)
{
	t_cub *cub;
	
	cub = (t_cub *)param;
	raycasting(cub);
	if (cub->mini_map->key->good->good)
	{
		mlx_clear_window(cub->mlx->mlx_ptr, cub->mlx->win);
		display_map_pixel_color(cub);
	}
	cub->mini_map->key->good->good = _false;
	return (0);
}

void init_struct_raycast(t_raycast *raycast)
{
	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
	{
		fprintf(stderr, "Erreur d'allocation mémoire pour raycast\n");
		exit(EXIT_FAILURE);
	}
	raycast->ray_angle = 0.0;
	raycast->distance = 1.0;
	raycast->tex_pos = 0.0;
	raycast->step = 0.0;
	raycast->side = 0;
	raycast->tex_x = 0;
	raycast->tex_y = 0;
}

int main(int ac, char **av)
{
	t_cub cub;

	if (ac < 2)
	{
		printf("Error: map file not found\n");
		return (0);
	}
	init_all_struct(&cub);
	get_map_and_tex(av[1], &cub);
	texture_processing(&cub);
	map_is_valid(&cub);
	init_window(cub.mlx, &cub);
	load_image(&cub);
	raycasting(&cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, update, &cub);
	mlx_hook(cub.mlx->win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx->win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.mlx->win, 17, 0, close_game, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
	return (0);
}


