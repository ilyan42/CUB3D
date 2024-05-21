/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:51 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/21 14:41:34 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void init_raycast(t_cub *cub, t_raycast *raycast, int x)
{
    // Calcul de la position de la caméra pour le rayon actuel
    raycast->camera_x = 2 * x / (double)cub->map->size_x - 1;

    // Direction du rayon en utilisant la direction et le plan de la caméra
    raycast->ray_dir_x = cub->player->dir_x + cub->player->plane_x * raycast->camera_x;
    raycast->ray_dir_y = cub->player->dir_y + cub->player->plane_y * raycast->camera_x;
    
    // Position de départ du rayon sur la carte
    raycast->map_x = (int)cub->player->pos_x;
    raycast->map_y = (int)cub->player->pos_y;

    // Calcul des distances delta pour le DDA
    raycast->delta_dist_x = (raycast->ray_dir_x != 0) ? fabs(1 / raycast->ray_dir_x) : INFINITY;
    raycast->delta_dist_y = (raycast->ray_dir_y != 0) ? fabs(1 / raycast->ray_dir_y) : INFINITY;
    
    raycast->hit = 0; // Initialisation de la variable de collision
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
    }
}

void get_distance(t_cub *cub, t_raycast *raycast)
{
    if (raycast->side == 0)
    {
        raycast->distance = (raycast->map_x - cub->player->pos_x + (1 - raycast->step_x) / 2) / raycast->ray_dir_x;
    }
    else
    {
        raycast->distance = (raycast->map_y - cub->player->pos_y + (1 - raycast->step_y) / 2) / raycast->ray_dir_y;
    }
    // printf pour le débogage, peut être supprimé ou désactivé dans la version finale
    printf("raycast->distance = %f\n", raycast->distance);
}

void raycasting(t_cub *cub)
{
    int x;
    t_raycast raycast;

    x = 0;
    printf ("cub->map->size_x = %d\n", cub->map->size_x); // printf pour le débogage
    // Boucle principale pour chaque colonne de l'écran
    while (x < cub->map->size_x)
    {
        init_raycast(cub, &raycast, x); // Initialisation des paramètres du rayon
        get_step_and_side_dist(cub, &raycast); // Calcul des étapes et des distances initiales
        perform_dda(cub, &raycast); // Exécution de l'algorithme DDA
        get_distance(cub, &raycast); // Calcul de la distance au mur
        x++;
    }
}


// /*partis renderer du raycast maintenant qu'on a la disance avec les murs*/


// void get_line_height(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la hauteur de la ligne à dessiner
//     raycast->line_height = (int)(cub->map->size_y / raycast->distance);
//     // Calcul des points de début et de fin de la ligne
//     raycast->draw_start = -raycast->line_height / 2 + cub->map->size_y / 2;
//     if (raycast->draw_start < 0)
//         raycast->draw_start = 0;
//     raycast->draw_end = raycast->line_height / 2 + cub->map->size_y / 2;
//     if (raycast->draw_end >= cub->map->size_y)
//         raycast->draw_end = cub->map->size_y - 1;
// }

// void get_texture(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la texture à utiliser en fonction de la direction du rayon
//     if (raycast->side == 0)
//     {
//         if (raycast->ray_dir_x > 0)
//             raycast->tex_num = 0;
//         else
//             raycast->tex_num = 1;
//     }
//     else
//     {
//         if (raycast->ray_dir_y > 0)
//             raycast->tex_num = 2;
//         else
//             raycast->tex_num = 3;
//     }
// }

// void get_wall_x(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la position du mur sur l'axe X
//     if (raycast->side == 0)
//         raycast->wall_x = cub->player->pos_y + raycast->distance * raycast->ray_dir_y;
//     else
//         raycast->wall_x = cub->player->pos_x + raycast->distance * raycast->ray_dir_x;
//     raycast->wall_x -= floor(raycast->wall_x);
// }

// void get_tex_x(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la position du mur sur l'axe X de la texture
//     raycast->tex_x = (int)(raycast->wall_x * (double)TEX_WIDTH);
//     if (raycast->side == 0 && raycast->ray_dir_x > 0)
//         raycast->tex_x = TEX_WIDTH - raycast->tex_x - 1;
//     if (raycast->side == 1 && raycast->ray_dir_y < 0)
//         raycast->tex_x = TEX_WIDTH - raycast->tex_x - 1;
// }

// void get_tex_pos(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la position de la texture sur l'axe Y
//     raycast->step = 1.0 * TEX_HEIGHT / raycast->line_height;
//     raycast->tex_pos = (raycast->draw_start - cub->map->size_y / 2 + raycast->line_height / 2) * raycast->step;
// }

// void draw_line(t_cub *cub, t_raycast *raycast, int x)
// {
//     int y;
//     int color;

//     y = 0;
//     while (y < cub->map->size_y)
//     {
//         if (y < raycast->draw_start)
//             color = cub->color->color_ceiling;
//         else if (y >= raycast->draw_start && y <= raycast->draw_end)
//         {
//             get_tex_pos(cub, raycast);
//             get_tex_x(cub, raycast);
//             color = cub->texture->texture[raycast->tex_num][TEX_HEIGHT * raycast->tex_y + raycast->tex_x];
//             raycast->tex_y = (int)raycast->tex_pos & (TEX_HEIGHT - 1);
//         }
//         else
//             color = cub->color->color_floor;
//         cub->image->[y * cub->map->size_x + x] = color;
//         y++;
//     }
// }

// void raycasting(t_cub *cub)
// {
//     int x;
//     t_raycast raycast;

//     x = 0;
//     while (x < cub->map->size_x)
//     {
//         init_raycast(cub, &raycast, x);
//         get_step_and_side_dist(cub, &raycast);
//         perform_dda(cub, &raycast);
//         get_distance(cub, &raycast);
//         get_line_height(cub, &raycast);
//         get_texture(cub, &raycast);
//         get_wall_x(cub, &raycast);
//         draw_line(cub, &raycast, x);
//         x++;
//     }
//     mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win, cub->image->img_ptr, 0, 0);
// }
