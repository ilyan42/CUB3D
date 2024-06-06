/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:03:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 14:55:45 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	clear_before_exit(t_cub *cub)
{
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->image->img);
	mlx_clear_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_display(cub->mlx->mlx_ptr);
	free(cub->mlx->mlx_ptr);
}

void	print_and_exit(char *msg, t_cub *cub)
{
	ft_printf("%s", msg);
	clear_before_exit(cub);
	exit(EXIT_FAILURE);
}