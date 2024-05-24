/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:09:45 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/24 17:35:47 by ilbendib         ###   ########.fr       */
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
	int tex_y;
	int color;
	int tex_x;

	y = ray->draw_start;
	printf ("ray->draw_start = %d\n", ray->draw_start);
	while (y < ray->draw_end + 1)
	{
		if (ray->line_height == 0)
			break ;
		if (ray->side == 0)
			ray->wall_x = cub->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
		else
			ray->wall_x = cub->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		printf ("la 1\n");
		tex_x = ((int)ray->wall_x * cub->image->width);
		printf ("la 2\n");
		if (ray->side == 0 && ray->ray_dir_x > 0)
			tex_x = cub->image->width - tex_x - 1;
		printf ("la 3\n");
		if (!cub->raycast->line_height)
		{
			printf ("la 3.1\n");
		}

		tex_y = (((y - (cub->res_y / 2) + (ray->line_height / 2)) * cub->image->height) / ray->line_height);
		printf ("la 4\n");
		color = get_pixel_color(cub->image, tex_x, tex_y);
		printf ("la 5\n");
		my_pixel_put(cub, x, y, color);
		printf ("la 6\n");
		y++;
	}
}


void raycasting(t_cub *cub)
{
    int x;
    t_raycast *raycasts = malloc(sizeof(t_raycast) * cub->res_x);

    // if (!raycasts) {
    //     printf("Memory allocation failed\n");
    //     return;
    // }
    x = 0;
	// int y = 0;
	printf ("cub->raycast->res_x = %d\n", cub->raycast->res_x);
	while (x < cub->res_x)
	{
		init_raycast(cub, &raycasts[x], x); // Initialisation des paramètres du rayon
		get_step_and_side_dist(cub, &raycasts[x]); // Calcul des étapes et des distances initiales
		perform_dda(cub, &raycasts[x]); // Exécution de l'algorithme DDA
		get_distance(cub, &raycasts[x]); // Calcul de la distance au mur
		cub->raycast->draw_start = (int)(cub->res_y / 2) - (int)(cub->raycast->line_height / 2); // Calcul du début du mur
		if (cub->raycast->draw_start < 0)
			cub->raycast->draw_start = 0;
		cub->raycast->draw_end = (int)(cub->raycast->line_height / 2) + (int)(cub->res_y / 2); // Calcul de la fin du mur
		if (cub->raycast->draw_end >= cub->res_y)
			cub->raycast->draw_end = cub->res_y - 1;
		draaw_line(cub, x, cub->raycast->draw_start, cub->raycast);
		draw_wall(cub, x, cub->raycast);
		x++;
	}
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win, cub->image->img, 0, 0);
}
