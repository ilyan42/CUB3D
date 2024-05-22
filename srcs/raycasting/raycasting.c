/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:25:51 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/22 18:40:51 by ilbendib         ###   ########.fr       */
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


// void my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
// {
//     char *dst;

//     if (x < 0 || x >= cub->map->size_x || y < 0 || y >= cub->map->size_y)
//         return;
//     // Calcul de l'adresse du pixel
//     dst = cub->image->addr + (y * cub->image->line_length + x * (cub->image->bits_per_pixel / 8));
//     // Écriture de la couleur du pixel
//     *(unsigned int *)dst = color;
// }

// float normalize_angle(float angle)
// {
//     if (angle < 0)
//         angle += (2 * M_PI);
//     if (angle > (2 * M_PI))
//         angle -= (2 * M_PI);
//     return angle;
// }

// void draw_floor_ceilling(t_cub *cub, int ray, int t_pix, int b_pix)
// {
//     int i;

//     i = b_pix;
//     while (i < cub->map->size_y)
//     {
//         my_mlx_pixel_put(cub, ray, i, cub->color->color_floor);
//         i++;
//     }
//     i = 0;
//     while (i < t_pix)
//     {
//         my_mlx_pixel_put(cub, ray, i, cub->color->color_ceiling);
//         i++;
//     }
// }

// int get_color_wall(t_cub *cub, int flag)
// {
//     cub->raycast->ray_angle = normalize_angle(cub->raycast->ray_angle);
//     if (flag == 0)
//     {
//         if (cub->raycast->ray_angle > M_PI / 2 && cub->raycast->ray_angle < (3 * M_PI / 2))
//             return cub->texture->texture[1][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
//         else
//             return cub->texture->texture[0][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
//     }
//     else
//     {
//         if (cub->raycast->ray_angle > 0 && cub->raycast->ray_angle < M_PI)
//             return cub->texture->texture[3][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
//         else
//             return cub->texture->texture[2][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
//     }
// }

// void draw_wall(t_cub *cub, int ray, int t_pix, int b_pix)
// {
//     int color;

//     while (t_pix < b_pix)
//     {
//         cub->raycast->tex_y = (int)cub->raycast->tex_pos & (TEX_HEIGHT - 1);
//         cub->raycast->tex_pos += cub->raycast->step;
//         color = get_color_wall(cub, cub->raycast->side);
//         my_mlx_pixel_put(cub, ray, t_pix, color);
//         t_pix++;
//     }
// }

// void renderer_wall(t_cub *cub, int ray)
// {
//     double wall_h;
//     double b_pix;
//     double t_pix;

//     printf ("ici\n");
//     if (cub->raycast->ray_angle)
//         printf ("ray_angle = 0\n");
//     else 
//         printf ("ray_angle\n");
//     if (!cub->player->angle)
//         printf ("angle = 0\n");
//     else 
//         printf ("angle\n");
//     printf ("ici\n");
//     cub->raycast->distance = cub->raycast->distance * cos(cub->raycast->ray_angle - cub->player->angle);
//     printf ("ici\n");
//     wall_h = (TILE_SIZE / cub->raycast->distance) * (SCREEN_WIDTH / 2) / tan(cub->player->fov_angle / 2);
//     printf ("wall_h = %f\n", wall_h);
//     b_pix = (cub->map->size_y / 2) + (wall_h / 2);
//     printf ("b_pix = %f\n", b_pix);
//     t_pix = (cub->map->size_y / 2) - (wall_h / 2);
//     printf ("t_pix = %f\n", t_pix);
//     draw_wall(cub, ray, t_pix, b_pix);
//     draw_floor_ceilling(cub, ray, t_pix, b_pix);
// }

void my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
    char *dst;

    if (!cub || !cub->image || !cub->image->addr)
        return;
    if (x < 0 || x >= cub->map->size_x || y < 0 || y >= cub->map->size_y)
        return;
    dst = cub->image->addr + (y * cub->image->line_length + x * (cub->image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

float normalize_angle(float angle)
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return angle;
}

void draw_floor_ceilling(t_cub *cub, int ray, int t_pix, int b_pix)
{
    int i;

    if (!cub || !cub->map || !cub->color)
        return;

    i = b_pix;
    while (i < cub->map->size_y)
    {
        my_mlx_pixel_put(cub, ray, i, cub->color->color_floor);
        i++;
    }
    i = 0;
    while (i < t_pix)
    {
        my_mlx_pixel_put(cub, ray, i, cub->color->color_ceiling);
        i++;
    }
}

int get_color_wall(t_cub *cub, int flag)
{
    if (!cub || !cub->raycast || !cub->texture)
        return 0;

    cub->raycast->ray_angle = normalize_angle(cub->raycast->ray_angle);
    if (flag == 0)
    {
        if (cub->raycast->ray_angle > M_PI / 2 && cub->raycast->ray_angle < (3 * M_PI / 2))
            return cub->texture->texture[1][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
        else
            return cub->texture->texture[0][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
    }
    else
    {
        if (cub->raycast->ray_angle > 0 && cub->raycast->ray_angle < M_PI)
            return cub->texture->texture[3][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
        else
            return cub->texture->texture[2][TEX_HEIGHT * cub->raycast->tex_y + cub->raycast->tex_x];
    }
}

void draw_wall(t_cub *cub, int ray, int t_pix, int b_pix)
{
    int color;

    if (!cub || !cub->raycast)
        return;

    while (t_pix < b_pix)
    {
        cub->raycast->tex_y = (int)cub->raycast->tex_pos & (TEX_HEIGHT - 1);
        cub->raycast->tex_pos += cub->raycast->step;
        color = get_color_wall(cub, cub->raycast->side);
        my_mlx_pixel_put(cub, ray, t_pix, color);
        t_pix++;
    }
}

void renderer_wall(t_cub *cub, int ray)
{
    double wall_h;
    double b_pix;
    double t_pix;

    cub->raycast = malloc(sizeof(t_raycast));
    
    if (!cub->raycast)
        printf ("bababa\n");

    printf ("ici\n");
    if (cub->raycast->ray_angle)
        printf ("ray_angle = 0\n");
    else 
        printf ("ray_angle\n");
    if (!cub->player->angle)
        printf ("angle = 0\n");
    else 
        printf ("angle\n");
    printf ("ici\n");
    cub->raycast->distance = cub->raycast->distance * cos(cub->raycast->ray_angle - cub->player->angle);
    printf ("ici\n");
    wall_h = (TILE_SIZE / cub->raycast->distance) * (SCREEN_WIDTH / 2) / tan(cub->player->fov_angle / 2);
    printf ("wall_h = %f\n", wall_h);
    b_pix = (cub->map->size_y / 2) + (wall_h / 2);
    printf ("b_pix = %f\n", b_pix);
    t_pix = (cub->map->size_y / 2) - (wall_h / 2);
    printf ("t_pix = %f\n", t_pix);
    draw_wall(cub, ray, t_pix, b_pix);
    draw_floor_ceilling(cub, ray, t_pix, b_pix);
}


// // // /*partis renderer du raycast maintenant qu'on a la disance avec les murs*/


// void get_line_height(t_cub *cub, t_raycast *raycast)
// {
//     // Calcul de la hauteur de la ligne à dessiner
//     raycast->line_height = (int)(cub->map->size_y / raycast->distance);
//     // Calcul des points de début et de fin de la ligne
//     raycast->draw_start = raycast->line_height / 2 + cub->map->size_y / 2;
//     if (raycast->draw_start < 0)
//         raycast->draw_start = 0;
//     raycast->draw_end = raycast->line_height / 2 + cub->map->size_y / 2;
//     if (raycast->draw_end >= cub->map->size_y)
//         raycast->draw_end = cub->map->size_y - 1;
// }

// void get_texture(t_raycast *raycast)
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

// void get_tex_x(t_raycast *raycast)
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
//     // printf ("raycast->draw_start = %d\n", raycast->draw_start);
    
//     // Vérifications des bornes de draw_start et draw_end
//     if (raycast->draw_start < 0 || raycast->draw_start >= cub->map->size_y)
//     {
//         // printf("Error: raycast->draw_start is out of bounds: %d\n", raycast->draw_start);
//         return;
//     }
//     if (raycast->draw_end < 0 || raycast->draw_end >= cub->map->size_y)
//     {
//         // printf("Error: raycast->draw_end is out of bounds: %d\n", raycast->draw_end);
//         return;
//     }

//     while (y < cub->map->size_y)
//     {
//         if (y < raycast->draw_start)
//         {
//             color = cub->color->color_ceiling;
//             // printf("color1 = %x\n", color);
//         }
//         else if (y >= raycast->draw_start && y <= raycast->draw_end)
//         {
//             get_tex_pos(cub, raycast);
            
//             // Vérification de tex_pos
//             if (raycast->tex_pos < 0 || raycast->tex_pos >= TEX_HEIGHT)
//             {
//                 // printf("Error: raycast->tex_pos is out of bounds: %f\n", raycast->tex_pos);
//                 return;
//             }
//             // printf("raycast->tex_pos = %f\n", raycast->tex_pos);

//             get_tex_x(raycast);
            
//             // Vérification de tex_x
//             if (raycast->tex_x < 0 || raycast->tex_x >= TEX_WIDTH)
//             {
//                 // printf("Error: raycast->tex_x is out of bounds: %d\n", raycast->tex_x);
//                 return;
//             }
//             // printf("raycast->tex_x = %d\n", raycast->tex_x);

//             // Vérification de tex_num
//             if (raycast->tex_num < 0 || raycast->tex_num >= NUM_TEXTURES)
//             {
//                 // printf("Error: raycast->tex_num is out of bounds: %d\n", raycast->tex_num);
//                 return;
//             }
//             if (!cub->texture->texture[raycast->tex_num])
//             {
//                 // printf("Error: texture for tex_num %d is NULL\n", raycast->tex_num);
//                 return;
//             }

//             color = cub->texture->texture[raycast->tex_num][TEX_HEIGHT * raycast->tex_y + raycast->tex_x];
//             raycast->tex_y = (int)raycast->tex_pos & (TEX_HEIGHT - 1);
//             // printf("color4 = %x\n", color);
//         }
//         else
//         {
//             color = cub->color->color_floor;
//             // printf("color2 = %x\n", color);
//         }

//         // printf("color3 = %x\n", color);

//         // Vérification de cub->image->addr avant utilisation
//         if (!cub->image->addr)
//         {
//             // printf("cub->image->addr is NULL\n");
//             return;
//         }
//         cub->image->addr[y * cub->image->line_length / 2 + x] = color;
//         // printf("cub->image->addr[y * cub->image->line_length / 4 + x] = %x\n", cub->image->addr[y * cub->image->line_length / 4 + x]);
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
//         get_texture(&raycast);
//         get_wall_x(cub, &raycast);
//         draw_line(cub, &raycast, x);
//         x++;
//     }
// }
