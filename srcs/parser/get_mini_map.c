/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:49:33 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/29 18:29:01 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_struct_mini_map(t_mini_map *mini_map)
{
	mini_map->map_block_size = 16;
	mini_map->player_size = mini_map->map_block_size / 2;
	mini_map->player_color = 0x0000FF00;
	mini_map->i = 0;
	mini_map->j = 0;
	mini_map->srceen_x = 0;
	mini_map->screen_y = 0;
	mini_map->player_center_x = 0;
	mini_map->player_center_y = 0;
}

void	draw_mini_map_wall(t_cub *cub, t_mini_map *mini_map, int x, int y)
{
	mini_map->i = 0;
	mini_map->j = 0;
	while (mini_map->i < mini_map->map_block_size)
	{
		while (mini_map->j < mini_map->map_block_size)
		{
			mini_map->srceen_x = x * mini_map->map_block_size + mini_map->j;
			mini_map->screen_y = y * mini_map->map_block_size + mini_map->i;
			my_pixel_put(cub, mini_map->srceen_x,
				mini_map->screen_y, 0x00FF0000);
			mini_map->j++;
		}
		mini_map->j = 0;
		mini_map->i++;
	}
}

void	draw_mini_map_floor(t_cub *cub, t_mini_map *mini_map, int x, int y)
{
	mini_map->i = 0;
	mini_map->j = 0;
	while (mini_map->i < mini_map->map_block_size)
	{
		while (mini_map->j < mini_map->map_block_size)
		{
			mini_map->srceen_x = x * mini_map->map_block_size + mini_map->j;
			mini_map->screen_y = y * mini_map->map_block_size + mini_map->i;
			my_pixel_put(cub, mini_map->srceen_x,
				mini_map->screen_y, 0xFFFFFFFF);
			mini_map->j++;
		}
		mini_map->j = 0;
		mini_map->i++;
	}
}

void	draw_mini_map_player(t_cub *cub, t_mini_map *mini_map)
{
	mini_map->player_center_x = cub->player->pos_x * mini_map->map_block_size;
	mini_map->player_center_y = cub->player->pos_y * mini_map->map_block_size;
	mini_map->start_x = mini_map->player_center_x - mini_map->player_size / 2;
	mini_map->start_y = mini_map->player_center_y - mini_map->player_size / 2;
	mini_map->i = 0;
	mini_map->j = 0;
	while (mini_map->i < mini_map->player_size)
	{
		while (mini_map->j < mini_map->player_size)
		{
			mini_map->srceen_x = mini_map->start_x + mini_map->j;
			mini_map->screen_y = mini_map->start_y + mini_map->i;
			my_pixel_put(cub, mini_map->srceen_x,
				mini_map->screen_y, mini_map->player_color);
			mini_map->j++;
		}
		mini_map->j = 0;
		mini_map->i++;
	}
}

void	display_map_pixel_color(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	init_struct_mini_map(cub->mini_map);
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == '1')
				draw_mini_map_wall(cub, cub->mini_map, x, y);
			else if (cub->map->map[y][x] == '0')
				draw_mini_map_floor(cub, cub->mini_map, x, y);
			x++;
		}
		y++;
	}
	draw_mini_map_player(cub, cub->mini_map);
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win,
		cub->image->img, 0, 0);
}
