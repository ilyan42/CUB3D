/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mini_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:20:59 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/06 18:21:50 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	draw_mini_map_door(t_cub *cub, t_mini_map *mini_map, int x, int y)
{
	mini_map->i = 0;
	mini_map->j = 0;
	while (mini_map->i < mini_map->map_block_size)
	{
		while (mini_map->j < mini_map->map_block_size)
		{
			mini_map->srceen_x = x * mini_map->map_block_size + mini_map->j;
			mini_map->screen_y = y * mini_map->map_block_size + mini_map->i;
			my_pixel_put(cub->image, mini_map->srceen_x,
				mini_map->screen_y, 0x00FF0000);
			mini_map->j++;
		}
		mini_map->j = 0;
		mini_map->i++;
	}
}
