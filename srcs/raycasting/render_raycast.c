/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:09:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/03 18:33:26 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void my_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void pixel_put(t_cub *cub, int x, int y, int color)
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
void load_texture(t_cub *cub, t_texture *texture, char *file_path) {
    texture->reference = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, file_path, &texture->width, &texture->height);


    texture->pixels = (unsigned char *)mlx_get_data_addr(texture->reference, &texture->bits_per_pixel, &texture->line_len, &texture->endian);
}

int get_pixel_color(t_texture *texture, int x, int y) {
    if (x < 0 || x >= texture->width || y < 0 || y >= texture->height) {
        printf("Invalid texture coordinates: x = %d, y = %d\n", x, y);
        return (0);
    }
    unsigned char *dst = texture->pixels + (y * texture->line_len + x * (texture->bits_per_pixel / 8));
    return *(unsigned int *)dst;
}


void draw_wall(t_cub *cub, int x, t_raycast *ray)
{
    int y;
    int color;
    int tex_x, tex_y;
    t_texture texture;

    if (ray->side == 0) {
        if (ray->ray_dir_x > 0) {
            texture = cub->texture[0]; // Est
        } else {
            texture = cub->texture[1]; // Ouest
        }
    } else {
        if (ray->ray_dir_y > 0) {
            texture = cub->texture[2]; // Sud
        } else {
            texture = cub->texture[3]; // Nord
        }
    }

    if (ray->side == 0) {
        ray->wall_x = cub->player->pos_y + ray->distance * ray->ray_dir_y;
    } else {
        ray->wall_x = cub->player->pos_x + ray->distance * ray->ray_dir_x;
    }
    ray->wall_x -= floor(ray->wall_x);

    tex_x = (int)(ray->wall_x * (double)(texture.width));
    if (ray->side == 0 && ray->ray_dir_x > 0) {
        tex_x = texture.width - tex_x - 1;
    }

    if (ray->side == 1 && ray->ray_dir_y < 0) {
        tex_x = texture.width - tex_x - 1;
    }

    y = ray->draw_start;
	while (y < ray->draw_end + 1) {
		int d = y * 256 - cub->res_y * 128 + ray->line_height * 128;
		tex_y = ((d * texture.height) / ray->line_height) / 256;
		if (tex_y < 0) tex_y = 0;
        if (tex_y >= texture.height) tex_y = texture.height - 1;
		color = get_pixel_color(&texture, tex_x, tex_y);
		my_pixel_put(cub->image, x, y, color);
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
