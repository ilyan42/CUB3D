/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:46:18 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 19:48:49 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_image(t_image *image, void *mlx_ptr)
{
	if (image)
	{
		if (image->img)
		{
			mlx_destroy_image(mlx_ptr, image->img);
			image->img = NULL;
		}
		free(image);
	}
}

void	free_mlx(t_minilibx *mlx)
{
	if (mlx)
	{
		if (mlx->win)
		{
			mlx_destroy_window(mlx->mlx_ptr, mlx->win);
			mlx->win = NULL;
		}
		if (mlx->mlx_ptr)
		{
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
			mlx->mlx_ptr = NULL;
		}
		free(mlx);
	}
}

void	free_player(t_player *player)
{
	if (player)
	{
		free(player);
	}
}

void	free_raycast(t_raycast *raycast)
{
	if (raycast)
	{
		free(raycast);
	}
}

void	free_keys(t_key *keys)
{
	if (keys)
	{
		if (keys->good)
		{
			free(keys->good);
		}
		free(keys);
	}
}
