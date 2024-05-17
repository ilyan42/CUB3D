/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/17 19:03:39 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

// void handle_get_ceilling_color(t_cub *cub, char *line, int x)
// {
	
// }


void parsing_texture(t_cub *cub)
{
	int y = 0;
	int x = 0;
	int check = 0;

	while (cub->texture->texture[y])
	{
		char *line = cub->texture->texture[y];
		x = 0;
		while (line[x])
		{
			if (line[x] == 'N' && line[x + 1] == 'O')
			{
				parse_north_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'S' && line[x + 1] == 'O')
			{
				parse_south_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'W' && line[x + 1] == 'E')
			{
				parse_west_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'E' && line[x + 1] == 'A')
			{
				parse_east_texture(cub, line, x);
				check++;
			}
			else if (line[x] == 'F' && line[x + 1] == ' ')
			{
				parse_floor_color(cub, line);
				check++;
			}
			else if (line[x] == 'C' && line[x + 1] == ' ')
			{
				parse_ceiling_color(cub, line);
				check++;
			}
			x++;
		}
		y++;
	}
	if (check != 6)
		print_and_exit(WRONG_NUMBER_OK_TEXTURES);
	printf ("\n%s\n", cub->texture->north);
	printf ("%s\n", cub->texture->south);
	printf ("%s\n", cub->texture->west);
	printf ("%s\n", cub->texture->east);
	printf ("%d\n", cub->color->F_r);
	printf ("%d\n", cub->color->F_g);
	printf ("%d\n", cub->color->F_b);
	printf ("%d\n", cub->color->C_r);
	printf ("%d\n", cub->color->C_g);
	printf ("%d\n", cub->color->C_b);
}

int open_texture(t_cub *cub)
{
	int fd;
	
	fd = open(cub->texture->north, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_NORTH_TEXTURE);
	close(fd);
	fd = open(cub->texture->south, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_SOUTH_TEXTURE);
	close(fd);
	fd = open(cub->texture->west, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_WEST_TEXTURE);
	close(fd);
	fd = open(cub->texture->east, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_EAST_TEXTURE);
	close(fd);
	return (1);
}


void texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (open_texture(cub) == 0)
		exit(EXIT_FAILURE);
}

// void	load_texture_detatils()
// {
// 	mlx_xpm_file_to_image(mlx_ptr, cub->texture->south, &width, &height);
// }

// mlx_xpm_file_to_image(mlx_ptr, "path.xpm", &width, &height);