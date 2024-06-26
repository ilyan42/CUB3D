/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:39:01 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/12 17:35:22 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_window(t_minilibx *window, t_cub *cub)
{
	window->mlx_ptr = mlx_init();
	if (!window->mlx_ptr)
		print_and_exit(MALLOC_FAILED, cub, 0);
	window->win = mlx_new_window(window->mlx_ptr,
			cub->res_x, cub->res_y, "cub3d");
}

t_texture	new_sprite(t_cub *cub, int i)
{
	t_texture	*texture;
	t_texture	result;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		print_and_exit(MALLOC_FAILED, cub, 0);
	texture->reference = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			cub->texture_file->text[i], &texture->width, &texture->height);
	if (!texture->reference)
		print_and_exit(MALLOC_FAILED, cub, 0);
	texture->pixels = (unsigned char *)mlx_get_data_addr(texture->reference,
			&texture->bits_per_pixel, &texture->line_len, &texture->endian);
	result = *texture;
	free(texture);
	return (result);
}

void	init_sprite(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		cub->texture[i] = new_sprite(cub, i);
		i++;
	}
}

void	initialize_textures(t_cub *cub)
{
	cub->texture_file->text = (char **)malloc(sizeof(char *) * 5);
	if (!cub->texture_file->text)
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->texture_file->text[0] = cub->texture_file->north_path;
	cub->texture_file->text[1] = cub->texture_file->south_path;
	cub->texture_file->text[2] = cub->texture_file->west_path;
	cub->texture_file->text[3] = cub->texture_file->east_path;
	cub->texture_file->text[4] = cub->texture_file->door_path;
}

void	init_image(t_cub *cub)
{
	cub->image->img = mlx_new_image(cub->mlx->mlx_ptr, cub->res_x, cub->res_y);
	cub->image->addr = mlx_get_data_addr(cub->image->img, &cub->image
			->bits_per_pixel, &cub->image->line_length, &cub->image->endian);
}
