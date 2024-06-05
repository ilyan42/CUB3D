/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/05 17:28:59 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_game(t_cub *game)
{
	mlx_destroy_image(game->mlx->mlx_ptr, game->image->img);
	mlx_destroy_image(game->mlx->mlx_ptr, game->texture[0].reference);
	mlx_destroy_image(game->mlx->mlx_ptr, game->texture[1].reference);
	mlx_destroy_image(game->mlx->mlx_ptr, game->texture[2].reference);
	mlx_destroy_image(game->mlx->mlx_ptr, game->texture[3].reference);
	mlx_clear_window(game->mlx->mlx_ptr, game->mlx->win);
	mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx_ptr);
	free(game->mlx->mlx_ptr);
	if (game->key->good) {
		free(game->key->good);
	}
	if (game->texture_file->text) {
		free(game->texture_file->text);
	}
	free(game->key);
	free(game->player);
	free(game->mlx);
	free(game->image);
	for (int i = 0; game->map->map[i]; i++)
		free(game->map->map[i]);
	free(game->map->map);
	free(game->map);
	free(game->raycast);
	free(game->texture_file->north_path);
	free(game->texture_file->south_path);
	free(game->texture_file->west_path);
	free(game->texture_file->east_path);
	free(game->texture_file);
	printf("Programme terminé.\n");
	exit(EXIT_SUCCESS);
	return (0);
}


int	update(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	raycasting(cub);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac < 2)
	{
		printf("Error: map file not found\n");
		return (0);
	}
	init_struct_cub(&cub);
	get_map_and_tex(av[1], &cub);
	map_is_valid(&cub);
	init_window(cub.mlx, &cub);
	init_image(&cub);
	texture_processing(&cub);
	for (int i = 0; cub.texture->texture[i]; i++)
	{
		free(cub.texture->texture[i]);
	}
	free(cub.texture->texture);
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
