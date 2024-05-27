/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:24 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/27 12:57:05 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool valide_position(t_cub *cub, int x, int y)
{
    return (x >= 0 && y >= 0 && x < cub->map->size_x && y < cub->map->size_y);
}

static bool ft_check_around_floor(t_cub *cub, int x, int y)
{
    if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == '\n') ||
        (valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == '\n') ||
        (valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == '\n') ||
        (valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == '\n'))
        return false;
    if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
        (valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' ') ||
        (valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == ' ') ||
        (valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == ' '))
        return false;
    if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == '\0') ||
        (valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == '\0') ||
        (valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == '\0') ||
        (valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == '\0'))
        return false;
    return true;
}

static bool ft_check_around_wall(t_cub *cub, int x, int y)
{
    if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
        (valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' ') ||
        (valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == ' ') ||
        (valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == ' ')) {
        return true;
    }

    return true;
}

void get_size_map(t_cub *cub)
{
    int x;
    int y;

    y = 0;
    cub->map->size_x = 0;
    while (cub->map->map[y])
    {
        x = 0;
        while (cub->map->map[y][x])
        {
            x++;
        }
        if (x > cub->map->size_x) {
            cub->map->size_x = x;
        }
        y++;
    }
    cub->map->size_y = y;
}

void init_player(t_cub *cub, int x, int y)
{
    if (cub->map->map[y][x] == 'N')
        cub->player->angle = -M_PI_2;
    else if (cub->map->map[y][x] == 'S')
        cub->player->angle = M_PI_2;
    else if (cub->map->map[y][x] == 'E')
        cub->player->angle = 0.0;
    else if (cub->map->map[y][x] == 'W')
        cub->player->angle = M_PI;
    cub->player->pos_x = x;
    cub->player->pos_y = y;
    cub->player->dir_x = cos(cub->player->angle);
    cub->player->dir_y = sin(cub->player->angle);
    cub->player->plane_x = cos(cub->player->angle + M_PI_2);
    cub->player->plane_y = sin(cub->player->angle + M_PI_2);
    cub->map->map[y][x] = '0';
}


void get_player_position(t_cub *cub)
{
	int x;
	int y;

	y = 0;
	while (cub->map->map[y])
	{
		x = 0;
		while (cub->map->map[y][x])
		{
			if (cub->map->map[y][x] == 'N' || cub->map->map[y][x] == 'S' || cub->map->map[y][x] == 'E' || cub->map->map[y][x] == 'W')
			{
				// cub->player->pos_x = x;
				// cub->player->pos_y = y;
				// cub->player->angle = cub->map->map[y][x];
                // cub->player->plane_x = FOV_RAD;
                // cub->player->plane_y = FOV_RAD;
                // cub->map->map[y][x] = '0';
                init_player(cub, x, y);
				return;
			}
			x++;
		}
		y++;
	}
}

// void init_dir_player(t_player *player)
// {
//     if (player->angle == 'N')
//     {
//         player->dir_x = 0;
//         player->dir_y = -1;
//     }
//     else if (player->angle == 'S')
//     {
//         player->dir_x = 0;
//         player->dir_y = 1;
//     }
//     else if (player->angle == 'E')
//     {
//         player->dir_x = 1;
//         player->dir_y = 0;
//     }
//     else if (player->angle == 'W')
//     {
//         player->dir_x = -1;
//         player->dir_y = 0;
//     }
// }

void check_first_colone(t_cub *cub)
{
    int y;

    y = 0;
    while (cub->map->map[y])
    {
        if (cub->map->map[y][0] != '1')
        {
           print_and_exit(MAP_IS_NOT_VALID);
        }
        y++;
    }
}



void display_map_pixel_color(t_cub *cub)
{
    int map_block_size = 16; // Taille d'un bloc de la carte en pixels
    int x, y, i, j;

    y = 0;
    while (cub->map->map[y])
    {
        x = 0;
        while (cub->map->map[y][x])
        {
            for (i = 0; i < map_block_size; i++)
            {
                for (j = 0; j < map_block_size; j++)
                {
                    int screen_x = x * map_block_size + j;
                    int screen_y = y * map_block_size + i;
                    if (cub->map->map[y][x] == '1')
                    {
                        int color = 0x00FF0000; // Rouge pour les murs
                        mlx_pixel_put(cub->mlx->mlx_ptr, cub->mlx->win, screen_x, screen_y, color);
                    }
                    else if (cub->map->map[y][x] == '0')
                    {
                        int color2 = 0xFFFFFFFF; // Bleu pour les espaces vides
                        mlx_pixel_put(cub->mlx->mlx_ptr, cub->mlx->win, screen_x, screen_y, color2);
                    }
                }
            }
            int player_center_x = cub->player->pos_x * map_block_size;
            int player_center_y = cub->player->pos_y * map_block_size;
            int player_size = map_block_size / 2;
            int player_color = 0x0000FF00;
            int start_x = player_center_x - player_size / 2;
            int start_y = player_center_y - player_size / 2;
            for (int i = 0; i < player_size; i++)
            {
                for (int j = 0; j < player_size; j++)
                {
                    mlx_pixel_put(cub->mlx->mlx_ptr, cub->mlx->win, start_x + j, start_y + i, player_color);
                }
            }
            x++;
        }
        y++;
    }

}

void map_is_valid(t_cub *cub)
{
    int x;
    int y;

    get_size_map(cub);
    check_first_colone(cub);
    x = 0;
    y = 0;
    while (cub->map->map[y])
    {
        while (cub->map->map[y][x])
        {
            if (cub->map->map[y][x] == '0')
            {
                if (ft_check_around_floor(cub, x, y) == false)
                    print_and_exit(MAP_IS_NOT_VALID);
            }
            else if (cub->map->map[y][x] == '1')
            {
                if (ft_check_around_wall(cub, x, y) == false)
                    print_and_exit(MAP_IS_NOT_VALID);
            }
            x++;
        }
        x = 0;
        y++;
    }
    get_player_position(cub);
}


