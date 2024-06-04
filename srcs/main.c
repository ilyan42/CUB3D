/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 11:43:50 by ilbendib         ###   ########.fr       */
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
	
	cub->texture_file = malloc(sizeof(t_texture_file));
	if (!cub->texture_file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
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
	cub->key->good = malloc(sizeof(t_good));
	if (!cub->key->good)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->key->good->good = _false;
	cub->key->good->not_good = _false;
}

t_texture new_sprite(t_cub *cub, int i)
{
    t_texture *texture = (t_texture *)malloc(sizeof(t_texture));
    if (!texture)
    {
        printf("Error: malloc failed for texture\n");
        exit(EXIT_FAILURE);
    }
    texture->reference = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, cub->texture_file->text[i], &texture->width, &texture->height);
    if (!texture->reference)
    {
        printf("Error: texture not found\n");
        free(texture);
        exit(EXIT_FAILURE);
    }

    texture->pixels = (unsigned char *)mlx_get_data_addr(texture->reference, &texture->bits_per_pixel, &texture->line_len, &texture->endian);
    t_texture result = *texture;
    free(texture);
    return result;
}

void init_sprite(t_cub *cub)
{
    int i = 0;
    while (i < 4)
    {
        cub->texture[i] = new_sprite(cub, i);
        i++;
    }
}

void initialize_textures(t_cub *cub)
{
	cub->texture_file->text = (char **)malloc(sizeof(char *) * 4);
	if (!cub->texture_file->text)
	{
		printf("Error: malloc failed for texture_file->text\n");
		exit(EXIT_FAILURE);
	}
	cub->texture_file->text[0] = cub->texture_file->north_path;
	cub->texture_file->text[1] = cub->texture_file->south_path;
	cub->texture_file->text[2] = cub->texture_file->west_path;
	cub->texture_file->text[3] = cub->texture_file->east_path;
}


void init_image(t_cub *cub)
{
	cub->image->img = mlx_new_image(cub->mlx->mlx_ptr, cub->res_x, cub->res_y);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image->bits_per_pixel, &cub->image->line_length, &cub->image->endian);
}

int update(void *param)
{
	t_cub *cub;
	
	cub = (t_cub *)param;
	raycasting(cub);
	return (0);
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
	// init_struct_cub(&cub);
	get_map_and_tex(av[1], &cub);
	map_is_valid(&cub);
	init_window(cub.mlx, &cub);
	init_image(&cub);
	texture_processing(&cub);
	initialize_textures(&cub);
	init_sprite(&cub);
	raycasting(&cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, update, &cub);
	mlx_hook(cub.mlx->win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx->win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.mlx->win, 17, 0, close_game, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
	return (0);
}


