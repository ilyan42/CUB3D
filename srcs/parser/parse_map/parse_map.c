/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:24 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/21 19:26:41 by ilbendib         ###   ########.fr       */
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
				cub->player->pos_x = x;
				cub->player->pos_y = y;
				cub->player->angle = cub->map->map[y][x];
                cub->player->plane_x = 0;
                cub->player->plane_y = 0.66;
				return;
			}
			x++;
		}
		y++;
	}
}

void init_dir_player(t_player *player)
{
    if (player->angle == 'N')
    {
        player->dir_x = -1;
        player->dir_y = 0;
    }
    else if (player->angle == 'S')
    {
        player->dir_x = 1;
        player->dir_y = 0;
    }
    else if (player->angle == 'E')
    {
        player->dir_x = 0;
        player->dir_y = 1;
    }
    else if (player->angle == 'W')
    {
        player->dir_x = 0;
        player->dir_y = -1;
    }
}

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
    init_dir_player(cub->player);
    printf("player->pos_x = %f\n", cub->player->pos_x);
    printf("player->pos_y = %f\n", cub->player->pos_y);
}
