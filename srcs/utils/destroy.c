/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:12:42 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/07 19:13:08 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_destroy_utils(t_cub *cub)
{
	int	i;

	i = 0;
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
}

void	ft_destroy(t_cub *cub)
{
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->image->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[0].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[1].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[2].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[3].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->texture[4].reference);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[0]->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[1]->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[2]->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[3]->img);
	mlx_destroy_image(cub->mlx->mlx_ptr, cub->gun_[4]->img);
	mlx_clear_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_window(cub->mlx->mlx_ptr, cub->mlx->win);
	mlx_destroy_display(cub->mlx->mlx_ptr);
	free(cub->mlx->mlx_ptr);
	if (cub->key->good)
		free(cub->key->good);
	if (cub->texture_file->text)
		free(cub->texture_file->text);
	if (cub->mini_map)
		free(cub->mini_map);
	free(cub->key);
	free(cub->player);
	free(cub->mlx);
	free(cub->image);
}
