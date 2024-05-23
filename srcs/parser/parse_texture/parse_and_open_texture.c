/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_open_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:50:55 by ilbendib          #+#    #+#             */
/*   Updated: 2024/05/23 19:17:46 by ilbendib         ###   ########.fr       */
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

	// if (cub->texture->texture[y] == NULL)
	// 	print_and_exit("bababab");
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
	printf ("\n%s\n", cub->texture->north_path);
	printf ("%s\n", cub->texture->south_path);
	printf ("%s\n", cub->texture->west_path);
	printf ("%s\n", cub->texture->east_path);
	printf ("%x\n", cub->color->color_floor);
	printf ("%x\n", cub->color->color_ceiling);
}

int open_texture(t_cub *cub)
{
	int fd;
	
	fd = open(cub->texture->north_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_NORTH_TEXTURE);
	close(fd);
	fd = open(cub->texture->south_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_SOUTH_TEXTURE);
	close(fd);
	fd = open(cub->texture->west_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_WEST_TEXTURE);
	close(fd);
	fd = open(cub->texture->east_path, O_RDONLY);
	if (fd == -1)
		print_and_exit(OPEN_EAST_TEXTURE);
	close(fd);
	return (1);
}

void check_extention_texture(char *path)
{
	int i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
		{
			if (path[i + 1] == 'x' && path[i + 2] == 'p' && path[i + 3] == 'm')
				return ;
		}
		i++;
	}
	print_and_exit(WRONG_TEXTURE_EXTENTION);
}

void load_image(t_cub *cub)
{
	int width;
	int height;
	
	cub->image->NO_img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, cub->texture->north_path, &width, &height);
	cub->image->SO_img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, cub->texture->south_path, &width, &height);
	cub->image->WE_img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, cub->texture->west_path, &width, &height);
	cub->image->EA_img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr, cub->texture->east_path, &width, &height);
	printf ("la\n");
	cub->image->img = mlx_new_image(cub->mlx->mlx_ptr, 1920, 1080);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image->bits_per_pixel, &cub->image->line_length, &cub->image->endian);
	printf ("ici\n");
}

void texture_processing(t_cub *cub)
{
	parsing_texture(cub);
	if (!cub->texture->north_path || !cub->texture->south_path || !cub->texture->west_path || !cub->texture->east_path)
		exit(EXIT_FAILURE);
	check_extention_texture(cub->texture->north_path);
	check_extention_texture(cub->texture->south_path);
	check_extention_texture(cub->texture->west_path);
	check_extention_texture(cub->texture->east_path);
	if (open_texture(cub) == 0)
		exit(EXIT_FAILURE);
}