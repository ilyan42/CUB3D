/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:50 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/10 19:05:46 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int close_game(t_minilibx *game)
{
	(void)game;
	printf("Programme terminé.\n");
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

void init_window(t_minilibx *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		printf("Error: environement not set\n");
		return (exit(0), (void)0);
	}
	window->win = mlx_new_window(window->mlx, 1920, 1080, "cub3d");
}

int	main(void)
{
	t_minilibx minilib;

	init_window(&minilib);
	mlx_hook(minilib.win, 17, 0, close_game, (void *)&minilib);
	mlx_hook(minilib.win, KeyPress, KeyPressMask, ft_handle_key_press,
		(void *)&minilib);
	mlx_loop(minilib.mlx);
}

