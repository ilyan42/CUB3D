/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 17:38:59 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_gun(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (cub->gun_[i])
		{
			if (cub->gun_[i]->img && cub->mlx->mlx_ptr)
				mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[i]->img);
			else
				free(cub->gun_[i]->img);
			free(cub->gun_[i]);
		}
		i++;
	}
}

int	close_game(t_cub *cub)
{
	ft_destroy(cub);
	ft_destroy_utils(cub);
	free(cub->gun_[0]);
	free(cub->gun_[1]);
	free(cub->gun_[2]);
	free(cub->gun_[3]);
	free(cub->gun_[4]);
	if (cub->order_tex)
		free(cub->order_tex);
	printf("Program completed.\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	update(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	raycasting(cub);
	if (cub->map->size_y <= 60 && cub->map->size_x <= 120)
	{
		if (cub->key->map_displayed)
			display_map_pixel_color(cub);
	}
	cub->key->good->good = _false;
	return (0);
}

void	parsing(t_cub *cub, char **av)
{
	init_struct_cub(cub);
	if (cub->res_x != 1920 || cub->res_y != 1080)
		print_and_exit("Error: resolution must be 1920x1080\n", cub, 0);
	get_map_and_tex(av[1], cub);
	map_is_valid(cub);
	init_window(cub->mlx, cub);
	init_image(cub);
	init_gun(cub);
	init_weapon_utils(cub);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac < 2)
	{
		printf("Error: map file not found\n");
		return (0);
	}
	parsing(&cub, av);
	texture_processing(&cub);
	initialize_textures(&cub);
	init_sprite(&cub);
	raycasting(&cub);
	mlx_loop_hook(cub.mlx->mlx_ptr, update, &cub);
	mlx_hook(cub.mlx->win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx->win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.mlx->win, 6, 1L << 6, mouse_move, &cub);
	mlx_hook(cub.mlx->win, 4, 1L << 2, mousepress, &cub);
	mlx_hook(cub.mlx->win, 17, 0, close_game, &cub);
	mlx_loop(cub.mlx->mlx_ptr);
	return (0);
}
