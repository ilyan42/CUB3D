/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:07:01 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 19:55:30 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_mlx(t_minilibx *mlx)
{
	mlx = malloc(sizeof(t_minilibx));
	if (!mlx)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	mlx->mlx_ptr = NULL;
	mlx->win = NULL;
}

void	init_struct_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	map->map = NULL;
	map->size_x = 0;
	map->size_y = 0;
	map->height = 0;
	map->width = 0;
}

void	init_struct_image(t_image *image)
{
	image = malloc(sizeof(t_image));
	if (!image)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	image->img = NULL;
	image->addr = NULL;
	image->bits_per_pixel = 0;
	image->line_length = 0;
	image->endian = 0;
	image->width = 0;
	image->height = 0;
	image->path = NULL;
}

void	init_struct_texture_file(t_texture_file *texture_file)
{
	texture_file = malloc(sizeof(t_texture_file));
	if (!texture_file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	// texture_file->text = NULL;
	// texture_file->north_path = NULL;
	// texture_file->south_path = NULL;
	// texture_file->west_path = NULL;
	// texture_file->east_path = NULL;
	// texture_file->floor = NULL;
	// texture_file->ceiling = NULL;
}

void	init_struct_player(t_player *player)
{
	player = malloc(sizeof(t_player));
	if (!player)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	player->angle = 0;
	player->move_speed = 0.05;
	player->rot_speed = 0;
	player->fov_angle = 0;
	player->fov_rad = (FOV * M_PI) / 180;
}

void	init_struct_raycast(t_raycast *raycast)
{
	raycast = malloc(sizeof(t_raycast));
	if (!raycast)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	raycast->ray_angle = 0;
	raycast->distance = 0;
	raycast->tex_pos = 0;
	raycast->step = 0;
	raycast->side = 0;
	raycast->tex_x = 0;
	raycast->tex_y = 0;
	raycast->camera_x = 0;
	raycast->ray_dir_x = 0;
	raycast->ray_dir_y = 0;
	raycast->map_x = 0;
	raycast->map_y = 0;
	raycast->side_dist_x = 0;
	raycast->side_dist_y = 0;
	raycast->delta_dist_x = 0;
	raycast->delta_dist_y = 0;
	raycast->perp_wall_dist = 0;
	raycast->line_height = 0;
	raycast->draw_start = 0;
	raycast->draw_end = 0;
	raycast->tex_num = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->hit = 0;
	raycast->side = 0;
	raycast->tex_num = 0;
}

void	init_struct_color(t_color *color)
{
	color->c_b = 0;
	color->c_g = 0;
	color->c_r = 0;
	color->f_b = 0;
	color->f_g = 0;
	color->f_r = 0;
	color->color_ceiling = 0;
	color->color_floor = 0;
}

void	init_struct_key(t_key *key)
{
	key = malloc(sizeof(t_key));
	if (!key)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	key->forward = _false;
	key->backward = _false;
	key->left = _false;
	key->right = _false;
	key->rotate_left = _false;
	key->rotate_right = _false;
	key->map = _false;
	key->left_shift = _false;
	key->good = malloc(sizeof(t_good));
	if (!key->good)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	key->good->good = _false;
	key->good->not_good = _false;
}

void	init_struct_cub(t_cub *cub)
{
	printf ("init_struct_cub\n");
	cub->res_x = 1920;
	cub->res_y = 1080;
	printf ("init_struct_cub\n");
	init_struct_mlx(cub->mlx);
	printf ("init_struct_mlx\n");
	init_struct_map(cub->map);
	printf ("init_struct_map\n");
	init_struct_image(cub->image);
	printf ("init_struct_image\n");
	init_struct_texture_file(cub->texture_file);
	printf ("init_struct_texture_file\n");
	init_struct_player(cub->player);
	printf ("init_struct_player\n");
	init_struct_raycast(cub->raycast);
	printf ("init_struct_raycast\n");
	init_struct_color(cub->color);
	printf ("init_struct_color\n");
	init_struct_key(cub->key);
	printf ("init_struct_key\n");
	cub->line = NULL;
}