/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:54:24 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/17 13:49:54 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

bool valide_position(t_cub *cub, int x, int y)
{
    return (x >= 0 && y >= 0 && x < cub->map->size_x && y < cub->map->size_y);
}

static bool ft_check_around_floor(t_cub *cub, int x, int y) {
    if ((valide_position(cub, x + 1, y) && cub->map->map[y][x + 1] == ' ') ||
        (valide_position(cub, x - 1, y) && cub->map->map[y][x - 1] == ' ') ||
        (valide_position(cub, x, y + 1) && cub->map->map[y + 1][x] == ' ') ||
        (valide_position(cub, x, y - 1) && cub->map->map[y - 1][x] == ' ')) {
        return false;
    }
    return true;
}

static bool ft_check_around_wall(t_cub *cub, int x, int y)
{
    printf("ft_check_around_wall\n");

    if (valide_position(cub, x + 1, y)) {
        printf("%c\n", cub->map->map[y][x + 1]);
    }
    if (valide_position(cub, x - 1, y)) {
        printf("%c\n", cub->map->map[y][x - 1]);
    }
    if (valide_position(cub, x, y + 1)) {
        printf("%c\n", cub->map->map[y + 1][x]);
    }
    if (valide_position(cub, x, y - 1)) {
        printf("%c\n", cub->map->map[y - 1][x]);
    }

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
    cub->map->size_x = 0; // Initialisation de la taille x à 0
    while (cub->map->map[y])
    {
        x = 0;
        while (cub->map->map[y][x])
        {
            x++;
        }
        if (x > cub->map->size_x) {
            cub->map->size_x = x; // Mettre à jour la taille x si la ligne actuelle est plus longue
        }
        y++;
    }
    cub->map->size_y = y; // Mettre à jour la taille y après avoir compté toutes les lignes
}

void map_is_valid(t_cub *cub)
{
    int x;
    int y;

    get_size_map(cub); // Assurez-vous de calculer la taille de la carte avant de vérifier la validité

    x = 0;
    y = 0;
    printf("map_is_valid\n");
    while (cub->map->map[y])
    {
        printf("map_is_valid\n");
        while (cub->map->map[y][x])
        {
            printf("map_is_valid\n");
            if (cub->map->map[y][x] == '0')
            {
                printf("je suis dans le 0\n");
                if (ft_check_around_floor(cub, x, y) == false)
                {
                    printf("Error\n -> Map is not valid\n");
                    exit(EXIT_FAILURE);
                }
            }
            else if (cub->map->map[y][x] == '1')
            {
                printf("je suis dans le 1\n");
                if (ft_check_around_wall(cub, x, y) == false)
                {
                    printf("Error\n -> Map is not valid\n");
                    exit(EXIT_FAILURE);
                }
            }
            x++;
        }
        x = 0;
        y++;
    }
}
