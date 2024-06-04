/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:24:20 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 16:36:30 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_ceilling(t_cub *cub, int x, int draw_start, t_raycast *ray)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		my_pixel_put(cub->image, x, y, cub->color->color_ceiling);
		y++;
	}
	y = ray->draw_end;
	while (y < cub->res_y)
	{
		my_pixel_put(cub->image, x, y, cub->color->color_floor);
		y++;
	}
}

void init_draw_start_end(t_cub *cub)
{
	cub->raycast->draw_start = (int)(cub->res_y / 2) 
		- (int)(cub->raycast->line_height / 2);
	if (cub->raycast->draw_start < 0)
		cub->raycast->draw_start = 0;
	cub->raycast->draw_end = (int)(cub->raycast->line_height / 2)
		+ (int)(cub->res_y / 2);
	if (cub->raycast->draw_end >= cub->res_y)
		cub->raycast->draw_end = cub->res_y - 1;
}