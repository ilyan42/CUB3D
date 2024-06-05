/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:22:30 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/05 12:30:39 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_mlx(t_cub *cub)
{
	cub->mlx = malloc(sizeof(t_minilibx));
	if (!cub->mlx)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->mlx->mlx_ptr = NULL;
	cub->mlx->win = NULL;
}

void	init_struct_map(t_cub *cub)
{
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
}

void	init_struct_image(t_cub *cub)
{
	cub->texture_file = malloc(sizeof(t_texture_file));
	if (!cub->texture_file)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->image = malloc(sizeof(t_image));
	if (!cub->image)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	cub->image->img = NULL;
	cub->image->addr = NULL;
	cub->image->bits_per_pixel = 0;
	cub->image->line_length = 0;
	cub->image->endian = 0;
	cub->image->width = 0;
	cub->image->height = 0;
	cub->image->path = NULL;
}

void	init_struct_player(t_cub *cub)
{
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
}

void	init_struct_color(t_cub *cub)
{
	cub->color->c_b = 0;
	cub->color->c_g = 0;
	cub->color->c_r = 0;
	cub->color->f_b = 0;
	cub->color->f_g = 0;
	cub->color->f_r = 0;
	cub->color->color_ceiling = 0;
	cub->color->color_floor = 0;
}
