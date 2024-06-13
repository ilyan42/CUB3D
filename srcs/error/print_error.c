/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:03:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/13 18:17:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map(t_map *map)
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

void	free_texture_file(t_texture_file *texture_file)
{
	if (texture_file->north_path)
	{
		free(texture_file->north_path);
		texture_file->north_path = NULL;
	}
	if (texture_file->south_path)
	{
		free(texture_file->south_path);
		texture_file->south_path = NULL;
	}
	if (texture_file->west_path)
	{
		free(texture_file->west_path);
		texture_file->west_path = NULL;
	}
	if (texture_file->east_path)
	{
		free(texture_file->east_path);
		texture_file->east_path = NULL;
	}
	if (texture_file->door_path)
	{
		free(texture_file->door_path);
		texture_file->door_path = NULL;
	}
}

void	clear_before_exit_3(t_cub *cub)
{
	if (cub->image)
	{
		if (cub->mlx && cub->mlx->mlx_ptr)
			free_image(cub->image, cub->mlx->mlx_ptr);
		else
			free(cub->image);
		cub->image = NULL;
	}
	if (cub->player)
	{
		free_player(cub->player);
		cub->player = NULL;
	}
}

void	clear_before_exit_2(t_cub *cub)
{
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

void	clear_before_exit(t_cub *cub, int err)
{
	if (cub)
	{
		clear_before_exit_3(cub);
		clear_before_exit_2(cub);
		if (cub->texture_file)
		{
			free_texture_file(cub->texture_file);
			free(cub->texture_file);
			cub->texture_file = NULL;
		}
		if (cub->gun_ && err == 1)
			free_gun(cub);
		if (cub->order_tex)
		{
			free(cub->order_tex);
			cub->order_tex = NULL;
		}
		if (cub->mlx)
		{
			free_mlx(cub->mlx);
			cub->mlx = NULL;
		}
	}
}
