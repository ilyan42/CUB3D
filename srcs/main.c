/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/21 19:14:49 by ilbendib         ###   ########.fr       */
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

int	ft_handle_key_press(int keycode, void *param)
{
	t_minilibx *game;
	
	game = (t_minilibx *)param;
	if (keycode == ESCAPE_KEY || keycode == 53)
	{
		close_game(game);
	}
	return (1);
}

void 	init_window(t_minilibx *window)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
	{
		printf("Error: environement not set\n");
		return (exit(0), (void)0);
	}
	window->win = mlx_new_window(window->mlx_ptr, 1920, 1080, "cub3d");
}

void init_struct_cub(t_cub *cub)
{
	cub->mlx = malloc(sizeof(t_minilibx));
	if (!cub->mlx)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	cub->map = malloc(sizeof(t_map));
	if (!cub->map)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	cub->map->map = NULL;
	cub->map->width = 0;
	// cub->map->height = 0;
	cub->texture = malloc(sizeof(t_texture));
	if (!cub->texture)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	cub->color->C_b = 0;
	cub->color->C_g = 0;
	cub->color->C_r = 0;
	cub->color->F_b = 0;
	cub->color->F_g = 0;
	cub->color->F_r = 0;
	cub->color->color_ceiling = 0;
	cub->color->color_floor = 0;
	cub->player = malloc(sizeof(t_player));
	if (!cub->player)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
	cub->player->pos_x = 0;
	cub->player->pos_y = 0;
	cub->player->dir_x = 0;
	cub->player->dir_y = 0;
	cub->player->plane_x = 0;

	cub->player->plane_y = 0;
	cub->player->angle = 0;
	cub->image = malloc(sizeof(t_image));
	if (!cub->image)
	{
		printf("Error: malloc failed\n");
		exit(0);
	}
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
}


int	main(int ac, char **av)
{
	t_cub cub;

	if (ac < 2)
	{
		printf("Error: map file not found\n");
		return (0);
	}
	init_struct_cub(&cub);
	get_map_and_tex(av[1], &cub);
	texture_processing(&cub);
	map_is_valid(&cub);
	init_window(cub.mlx);
	load_image(&cub);
	raycasting(&cub);
	mlx_hook(cub.mlx->win, KeyPress, KeyPressMask, ft_handle_key_press, &cub);
	mlx_hook(cub.mlx->win, 17, 0, close_game, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
	return (0);
}

