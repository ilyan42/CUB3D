/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/05 18:23:28 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_destroy(t_cub *cub)
{
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->image->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[0].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[1].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[2].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[3].reference);
	mlx_clear_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_display(cub->mlx->mlx_ptr);
	free(cub->mlx->mlx_ptr);
	if (cub->key->good)
		free(cub->key->good);
	if (cub->texture_file->text)
		free(cub->texture_file->text);
	free(cub->key);
	free(cub->player);
	free(cub->mlx);
	free(cub->image);
}

int	close_game(t_cub *cub)
{
	int	i;

	i = 0;
	ft_destroy(cub);
	while (cub->map->map[i])
	{
		free(cub->map->map[i]);
		i++;
	}
	free(cub->map->map);
	free(cub->map);
	free(cub->raycast);
	free(cub->texture_file->north_path);
	free(cub->texture_file->south_path);
	free(cub->texture_file->west_path);
	free(cub->texture_file->east_path);
	free(cub->texture_file);
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
