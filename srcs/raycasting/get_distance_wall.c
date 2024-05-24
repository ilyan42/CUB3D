/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:01:43 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/24 17:30:43 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void init_raycast(t_cub *cub, t_raycast *raycast, int x)
{
	printf ("cub->player->pos_x = %f\n", cub->player->pos_x);
	printf ("cub->player->pos_y = %f\n", cub->player->pos_y);
	printf ("cub->player->dir_x = %f\n", cub->player->dir_x);
	printf ("cub->player->dir_y = %f\n", cub->player->dir_y);
	printf ("cub->player->plane_x = %f\n", cub->player->plane_x);
	printf ("cub->player->plane_y = %f\n", cub->player->plane_y);
	printf ("cub->map->size_x = %d\n", cub->map->size_x);
	printf ("cub->map->size_y = %d\n", cub->map->size_y);
	printf ("x = %d\n", x);
	
	// Calcul de la position de la caméra pour le rayon actuel
	raycast->camera_x = 2 * x / cub->res_x - 1;
	// Direction du rayon en utilisant la direction et le plan de la caméra
	raycast->ray_dir_x = cub->player->dir_x + cub->player->plane_x * raycast->camera_x;
	raycast->ray_dir_y = cub->player->dir_y + cub->player->plane_y * raycast->camera_x;
	printf ("raycast->ray_dir_x = %f\n", raycast->ray_dir_x);
	printf ("raycast->ray_dir_y = %f\n", raycast->ray_dir_y);
	// Position de départ du rayon sur la carte (position du joueur)
	raycast->map_x = cub->player->pos_x;
	raycast->map_y = cub->player->pos_y;
	// Calcul des distances delta pour le DDA
	if (raycast->ray_dir_x != 0)
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	else
		raycast->delta_dist_x = INFINITY;
	if (raycast->ray_dir_y != 0)
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	else
		raycast->delta_dist_y = INFINITY;
	raycast->hit = 0;
}

void draw_filled_square(t_cub *cub, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mlx_pixel_put(cub->mlx->mlx_ptr, cub->mlx->win, x + i, y + j, color);
		}
	}
}

void get_step_and_side_dist(t_cub *cub, t_raycast *raycast)
{
	// Calcul des étapes et des distances initiales pour le DDA
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (cub->player->pos_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0 - cub->player->pos_x) * raycast->delta_dist_x;
	}

	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (cub->player->pos_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0 - cub->player->pos_y) * raycast->delta_dist_y;
	}
}

void draw_line(t_cub *cub, int x0, int y0, int x1, int y1, int color, int thickness)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		draw_filled_square(cub, x0 - thickness / 2, y0 - thickness / 2, thickness, color);

		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// void perform_dda(t_cub *cub, t_raycast *raycast)
// {
// 	int thickness = 1; // Définir l'épaisseur de la ligne (taille du carré)
// 	int start_pixel_x = raycast->map_x * TILE_SIZE;
// 	int start_pixel_y = raycast->map_y * TILE_SIZE;
// 	int prev_pixel_x = start_pixel_x;
// 	int prev_pixel_y = start_pixel_y;

// 	// Boucle DDA pour trouver l'intersection avec un mur
// 	while (raycast->hit == 0)
// 	{
// 		int next_map_x = raycast->map_x;
// 		int next_map_y = raycast->map_y;

// 		if (raycast->side_dist_x < raycast->side_dist_y)
// 		{
// 			raycast->side_dist_x += raycast->delta_dist_x;
// 			next_map_x += raycast->step_x;
// 			raycast->side = 0; // Mur touché sur l'axe X
// 		}
// 		else
// 		{
// 			raycast->side_dist_y += raycast->delta_dist_y;
// 			next_map_y += raycast->step_y;
// 			raycast->side = 1; // Mur touché sur l'axe Y
// 		}
// 		// Vérification de la collision avec un mur
// 		if (cub->map->map[next_map_y][next_map_x] == '1')
// 		{
// 			raycast->hit = 1;
// 		}
		
// 		// Calculer les nouvelles coordonnées en pixels
// 		int pixel_x = next_map_x * TILE_SIZE;
// 		int pixel_y = next_map_y * TILE_SIZE;

// 		// Dessiner une ligne uniquement si les points sont adjacents
// 		if (abs(next_map_x - raycast->map_x) <= 1 && abs(next_map_y - raycast->map_y) <= 1)
// 		{
// 			draw_line(cub, prev_pixel_x, prev_pixel_y, pixel_x, pixel_y, 0x0000FF, thickness);
// 		}

// 		// Mettre à jour les coordonnées précédentes
// 		prev_pixel_x = pixel_x;
// 		prev_pixel_y = pixel_y;

// 		// Mettre à jour les coordonnées de la grille
// 		raycast->map_x = next_map_x;
// 		raycast->map_y = next_map_y;
// 	}
// }


void perform_dda(t_cub *cub, t_raycast *raycast)
{

    // Boucle DDA pour trouver l'intersection avec un mur
    while (raycast->hit == 0)
    {
        if (raycast->side_dist_x < raycast->side_dist_y)
        {
            raycast->side_dist_x += raycast->delta_dist_x;
            raycast->map_x += raycast->step_x;
            raycast->side = 0; // Mur touché sur l'axe X
        }
        else
        {
            raycast->side_dist_y += raycast->delta_dist_y;
            raycast->map_y += raycast->step_y;
            raycast->side = 1; // Mur touché sur l'axe Y
        }
        // Vérification de la collision avec un mur
        if (cub->map->map[raycast->map_y][raycast->map_x] == '1')
        {
            raycast->hit = 1;
        }
		else 
		{
			raycast->hit = 0;
		}
    }
}

void get_distance(t_cub *cub, t_raycast *raycast)
{
	if (raycast->side == 0)
	{
		cub->raycast->distance = raycast->side_dist_x - raycast->delta_dist_x;
	}
	else
	{
		cub->raycast->distance = raycast->side_dist_y - raycast->delta_dist_y;
	}
	cub->raycast->line_height = (int)(cub->res_y / cub->raycast->distance);
	cub->raycast->draw_start = (int)(-cub->raycast->line_height / 2) + ((int)cub->res_y / 2);
	printf ("distance = %f\n", raycast->distance);
}