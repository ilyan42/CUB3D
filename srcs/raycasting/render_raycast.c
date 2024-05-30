/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:09:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/30 17:02:47 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void my_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->image->addr + (y * cub->image->line_length + x * (cub->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draaw_line(t_cub *cub, int x, int draw_start, t_raycast *ray)
{
	int y;

	y = 0;
	while (y < draw_start)
	{
		my_pixel_put(cub, x, y, cub->color->color_ceiling);
		y++;
	}
	y = ray->draw_end;
	while (y < cub->res_y)
	{
		my_pixel_put(cub, x, y, cub->color->color_floor);
		y++;
	}
}

int get_pixel_color(t_image *image, int x, int y)
{
	int color;
	int index;

	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	index = (y * image->line_length + x * (image->bits_per_pixel / 8));
	color = *(unsigned int *)(image->addr + index);
	return (color);
}



void draw_wall(t_cub *cub, int x, t_raycast *ray)
{
	int y;
	// int tex_y;
	int color;
	int tex_x;

	y = ray->draw_start;
	while (y < ray->draw_end + 1)
	{
		if (ray->line_height == 0)
			break ;
		if (ray->side == 0)
			ray->wall_x = cub->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
		else
			ray->wall_x = cub->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		tex_x = ((int)ray->wall_x * cub->image->width);
		if (ray->side == 0 && ray->ray_dir_x > 0)
			tex_x = cub->image->width - tex_x - 1;
		// tex_y = (((y - (cub->res_y / 2) + (ray->line_height / 2)) * cub->image->height) / ray->line_height);
		// color = get_pixel_color(cub->image, tex_x, tex_y);
		// color = get_pixel_color(cub->image, tex_x, y);
		// //une couleur pour chaque fasse nord sud est ouest
		if (ray->side == 0 && ray->ray_dir_x > 0)
			color = 0x00FF0000; // direction = est couleur rouge
		else if (ray->side == 0 && ray->ray_dir_x < 0)
			color = 0x0000FF00; // direction = ouest couleur verte
		else if (ray->side == 1 && ray->ray_dir_y > 0)
			color = 0x000000FF; // direction = sud couleur bleu 
		else
			color = 0x00FFFF00; // direction = nord couleur jaune
		my_pixel_put(cub, x, y, color);
		y++;
	}
}

void raycasting(void *param)
{
	t_cub *cub = (t_cub *)param;
	int x;

	x = 0;
	ft_handle_key_press(cub);
	while (x < cub->res_x)
	{
		init_raycast(cub, cub->raycast, x);
		get_step_and_side_dist(cub, cub->raycast);
		perform_dda(cub, cub->raycast);
		get_distance(cub, cub->raycast);
		cub->raycast->draw_start = (int)(cub->res_y / 2) - (int)(cub->raycast->line_height / 2);
		if (cub->raycast->draw_start < 0)
			cub->raycast->draw_start = 0;
		cub->raycast->draw_end = (int)(cub->raycast->line_height / 2) + (int)(cub->res_y / 2);
		if (cub->raycast->draw_end >= cub->res_y)
			cub->raycast->draw_end = cub->res_y - 1;
		draaw_line(cub, x, cub->raycast->draw_start, cub->raycast);
		draw_wall(cub, x, cub->raycast);
		x++;
	}
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win, cub->image->img, 0, 0);
}
