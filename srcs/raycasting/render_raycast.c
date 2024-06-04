/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:09:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/04 16:24:53 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_pixel_color(t_texture *texture, int x, int y)
{
	unsigned char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (printf("Invalid texture coordinates: x = %d, y = %d\n",
				x, y), 0);
	dst = texture->pixels + (y * texture->line_len + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_texture	get_player_direction(t_cub *cub, t_raycast *ray, t_texture texture)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			texture = cub->texture[3];
		else
			texture = cub->texture[2];
	}
	else
	{
		if (ray->ray_dir_y > 0)
			texture = cub->texture[1];
		else
			texture = cub->texture[0];
	}
	return (texture);
}

void	ray_wall_x_init(t_cub *cub, t_raycast *ray)
{
	if (ray->side == 0)
		ray->wall_x = cub->player->pos_y + ray->distance * ray->ray_dir_y;
	else
		ray->wall_x = cub->player->pos_x + ray->distance * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	draw_wall(t_cub *cub, int x, t_raycast *ray)
{
	int			y;
	int			color;
	int			tex_x;
	int			tex_y;
	t_texture	texture;

	texture = get_player_direction(cub, ray, texture);
	ray_wall_x_init(cub, ray);
	tex_x = (int)(ray->wall_x * (double)(texture.width));
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		tex_x = texture.width - tex_x - 1;
	y = ray->draw_start;
	while (y < ray->draw_end + 1)
	{
		cub->d = y * 256 - cub->res_y * 128 + ray->line_height * 128;
		tex_y = ((cub->d * texture.height) / ray->line_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture.height)
			tex_y = texture.height - 1;
		color = get_pixel_color(&texture, tex_x, tex_y);
		my_pixel_put(cub->image, x, y, color);
		y++;
	}
}
