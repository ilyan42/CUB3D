/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:03:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 19:56:49 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map)
	{
		if (map->map)
		{
			while (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
		}
		free(map);
	}
}

static void	clear_before_exit(t_cub *cub)
{
	if (cub)
	{
		if (cub->mlx)
		{
			free_mlx(cub->mlx);
			cub->mlx = NULL;
		}
		if (cub->image)
		{
			if (cub->mlx && cub->mlx->mlx_ptr)
				free_image(cub->image, cub->mlx->mlx_ptr);
			else
				free_image(cub->image, NULL);
			cub->image = NULL;
		}
		if (cub->player)
		{
			free_player(cub->player);
			cub->player = NULL;
		}
		if (cub->raycast)
		{
			free_raycast(cub->raycast);
			cub->raycast = NULL;
		}
		if (cub->key)
		{
			free_keys(cub->key);
			cub->key = NULL;
		}
		if (cub->map)
		{
			free_map(cub->map);
			cub->map = NULL;
		}
	}
}

void	print_and_exit(char *msg, t_cub *cub)
{
	ft_printf("%s", msg);
	clear_before_exit(cub);
	exit(EXIT_FAILURE);
}
