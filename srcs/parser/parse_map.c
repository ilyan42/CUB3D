/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:05 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/16 18:19:26 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void count_map_height(t_cub *cub, int fd)
{
	cub->line = get_next_line_map(fd);
	cub->map->height = 1;
	while (cub->line)
	{
		cub->map->height++;
		free(cub->line);
		cub->line = get_next_line_map(fd);
	}
}

char **allocate_and_fill_map(t_cub *cub, int fd)
{
	int i;

	i = 1;
	cub->map->map = malloc(sizeof(char *) * (cub->map->height + 1));
	cub->map->map[0] = cub->line;
	cub->line = get_next_line_map(fd);
	while (cub->line && i <= cub->map->height)
	{
		cub->map->map[i] = ft_strdup(cub->line);
		free(cub->line);
		cub->line = get_next_line_map(fd);
		i++;
	}
	cub->map->map[i] = NULL;
	return (cub->map->map);
}

void is_cub_file(char *map)
{
	char	*extensions_check;

	extensions_check = ft_strnstr(map, ".cub", ft_strlen(map));
	if (extensions_check == NULL || ft_strlen(extensions_check) != 4)
	{
		ft_printf("Error\nExtensions check\n");
		exit(EXIT_FAILURE);
	}
}

void	get_map_and_tex(char *file, t_cub *cub)
{
	int fd;

	cub->line = NULL;
	is_cub_file(file);
	fd = open(file, O_RDONLY);
	count_texture_height(cub, fd);
	count_map_height(cub, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	cub->texture->texture = parse_texture_file(cub, fd);
	// int i = -1;
	// while (cub->texture->texture[++i])
	// 	printf ("%s", cub->texture->texture[i]);
	cub->map->map = allocate_and_fill_map(cub, fd);
	// int j = -1;
	// while (cub->map->map[++j])
	// 	printf ("%s", cub->map->map[j]);
	close(fd);
}

// void parsing_texture(t_cub *cub)
// {
// 	int check;	
// 	int y;
// 	int x;

// 	x = 0;
// 	y = 0;
// 	char *line = cub->texture->texture[y];
// 	check = 0;
// 	char *path_start = ft_strchr(&line[x], '.');
// 	char *path_end = ft_strchr(&line[x], '\n');
// 	size_t path_len = path_end - path_start;
// 	while (cub->texture->texture[y])
// 	{
// 		while (cub->texture->texture[y][x])
// 		{
// 			if (cub->texture->texture[y][x] == 'N' && cub->texture->texture[y][x + 1] == 'O')
// 			{
// 				cub->texture->north = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->north)
// 				{
// 					strncpy(cub->texture->north, path_start, path_len);
// 					cub->texture->north[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			if (cub->texture->texture[y][x] == 'S' && cub->texture->texture[y][x + 1] == 'O')
// 			{
// 				cub->texture->south = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->south)
// 				{
// 					strncpy(cub->texture->south, path_start, path_len);
// 					cub->texture->south[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			if (cub->texture->texture[y][x] == 'W' && cub->texture->texture[y][x + 1] == 'E')
// 			{
// 				cub->texture->west = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->west)
// 				{
// 					strncpy(cub->texture->west, path_start, path_len);
// 					cub->texture->west[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			if (cub->texture->texture[y][x] == 'E' && cub->texture->texture[y][x + 1] == 'A')
// 			{
// 				cub->texture->east = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->east)
// 				{
// 					strncpy(cub->texture->east, path_start, path_len);
// 					cub->texture->east[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			if (cub->texture->texture[y][x] == 'F')
// 			{
// 				cub->texture->floor = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->floor)
// 				{
// 					strncpy(cub->texture->floor, path_start, path_len);
// 					cub->texture->floor[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			if (cub->texture->texture[y][x] == 'C')
// 			{
// 				cub->texture->ceiling = malloc(sizeof(char) * path_len + 1);
// 				if (cub->texture->ceiling)
// 				{
// 					strncpy(cub->texture->ceiling, path_start, path_len);
// 					cub->texture->ceiling[path_len] = '\0';
// 					check++;
// 				}
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	printf ("%s\n", cub->texture->north);
// 	printf ("%s\n", cub->texture->south);
// 	// printf ("%s\n", cub->texture->west);
// 	// printf ("%s\n", cub->texture->east);
// 	// printf ("%s\n", cub->texture->floor);
// 	// printf ("%s\n", cub->texture->ceiling);
// 	if (check != 6)
// 	{
// 		printf("Error\n -> wrong number of textures\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

void parsing_texture(t_cub *cub)
{
    int check = 0;
    int y = 0;
    int x = 0;

    while (cub->texture->texture[y])
    {
        char *line = cub->texture->texture[y];
        x = 0; // Réinitialiser x à chaque itération de la boucle extérieure
        char *path_start;
        char *path_end;
        size_t path_len;

        while (line[x])
        {
            if (line[x] == 'N' && line[x + 1] == 'O')
            {
                path_start = strchr(&line[x], '.'); // Trouver le début du chemin
                path_end = strchr(&line[x], '\n');      // Trouver la fin du chemin
                if (path_start && path_end)
                {
                    path_len = path_end - path_start;
                    cub->texture->north = malloc(path_len + 1); // Allouer de la mémoire pour le chemin
                    if (cub->texture->north)
                    {
                        strncpy(cub->texture->north, path_start, path_len);
                        cub->texture->north[path_len] = '\0'; // Ajouter le caractère de fin de chaîne
                        check++;
                    }
                    else
                    {
                        printf("Error: Memory allocation failed for the north texture\n");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    printf("Error: Invalid north texture format\n");
                    exit(EXIT_FAILURE);
                }
            }
			else if (line[x] == 'S' && line[x + 1] == 'O')
			{
				// Traiter la texture sud de la même manière...
				path_start = strchr(&line[x], '.');
				path_end = strchr(&line[x], '\n');
				if (path_start && path_end)
				{
					path_len = path_end - path_start;
					cub->texture->south = malloc(path_len + 1);
					if (cub->texture->south)
					{
						strncpy(cub->texture->south, path_start, path_len);
						cub->texture->south[path_len] = '\0';
						check++;
					}
					else
					{
						printf("Error: Memory allocation failed for the south texture\n");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("Error: Invalid south texture format\n");
					exit(EXIT_FAILURE);
				}
			}
			else if (line[x] == 'W' && line[x + 1] == 'E')
			{
				// Traiter la texture ouest de la même manière...
				path_start = strchr(&line[x], '.');
				path_end = strchr(&line[x], '\n');
				if (path_start && path_end)
				{
					path_len = path_end - path_start;
					cub->texture->west = malloc(path_len + 1);
					if (cub->texture->west)
					{
						strncpy(cub->texture->west, path_start, path_len);
						cub->texture->west[path_len] = '\0';
						check++;
					}
					else
					{
						printf("Error: Memory allocation failed for the west texture\n");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("Error: Invalid west texture format\n");
					exit(EXIT_FAILURE);
				}
			}
			else if (line[x] == 'E' && line[x + 1] == 'A')
			{

				// Traiter la texture est de la même manière...
				path_start = strchr(&line[x], '.');
				path_end = strchr(&line[x], '\n');
				if (path_start && path_end)
				{
					path_len = path_end - path_start;
					cub->texture->east = malloc(path_len + 1);
					if (cub->texture->east)
					{
						strncpy(cub->texture->east, path_start, path_len);
						cub->texture->east[path_len] = '\0';
						check++;
					}
					else
					{
						printf("Error: Memory allocation failed for the east texture\n");

						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("Error: Invalid east texture format\n");
					exit(EXIT_FAILURE);
				}
			}
			else if (line[x] == 'F')
			{
				// Traiter la texture du sol de la même manière...
				path_start = strchr(&line[x], '.');
				path_end = strchr(&line[x], '\n');
				if (path_start && path_end)
				{
					path_len = path_end - path_start;
					cub->texture->floor = malloc(path_len + 1);
					if (cub->texture->floor)
					{
						strncpy(cub->texture->floor, path_start, path_len);
						cub->texture->floor[path_len] = '\0';
						check++;
					}
					else
					{
						printf("Error: Memory allocation failed for the floor texture\n");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("Error: Invalid floor texture format\n");
					exit(EXIT_FAILURE);
				}
			}
			else if (line[x] == 'C')
			{
				// Traiter la texture du plafond de la même manière...
				path_start = strchr(&line[x], '.');
				path_end = strchr(&line[x], '\n');
				if (path_start && path_end)
				{
					path_len = path_end - path_start;
					cub->texture->ceiling = malloc(path_len + 1);
					if (cub->texture->ceiling)
					{
						strncpy(cub->texture->ceiling, path_start, path_len);
						cub->texture->ceiling[path_len] = '\0';
						check++;
					}
					else
					{
						printf("Error: Memory allocation failed for the ceiling texture\n");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					printf("Error: Invalid ceiling texture format\n");
					exit(EXIT_FAILURE);
				}
			}
            x++;
        }
        y++;
    }

    // Afficher les textures
    printf ("%s\n", cub->texture->north);
    printf ("%s\n", cub->texture->south);
    printf ("%s\n", cub->texture->west);
    printf ("%s\n", cub->texture->east);
    printf ("%s\n", cub->texture->floor);
    printf ("%s\n", cub->texture->ceiling);

    // Vérifier le nombre de textures
    if (check != 6)
    {
        printf("Error: Wrong number of textures\n");
        exit(EXIT_FAILURE);
    }
}


int open_texture(t_cub *cub)
{
	int fd;
	
	fd = open(cub->texture->north, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n -> open north texture\n");
		return (0);
	}
	close(fd);
	return (1);
}



void texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (open_texture(cub) == 0)
		exit(EXIT_FAILURE);
}