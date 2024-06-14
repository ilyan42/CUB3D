/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanson <elanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:25:33 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:35:59 by elanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_gun(t_cub *cub)
{
	cub->gun_[0] = malloc(sizeof(t_image));
	if (!cub->gun_[0])
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->gun_[0]->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			"texture/1.xpm", &cub->gun_[0]->width, &cub->gun_[0]->height);
	cub->gun_[0]->addr = mlx_get_data_addr(cub->gun_[0]->img, &cub->gun_[0]
			-> bits_per_pixel, &cub->gun_[0]->line_length,
			&cub->gun_[0]->endian);
	cub->gun_[1] = malloc(sizeof(t_image));
	if (!cub->gun_[1])
		print_and_exit(MALLOC_FAILED, cub, 0);
	cub->gun_[1]->img = mlx_xpm_file_to_image(cub->mlx->mlx_ptr,
			"texture/2.xpm", &cub->gun_[1]->width, &cub->gun_[1]->height);
	cub->gun_[1]->addr = mlx_get_data_addr(cub->gun_[1]->img, &cub->gun_[1]
			-> bits_per_pixel, &cub->gun_[1]->line_length,
			&cub->gun_[1]->endian);
	cub->gun_[2] = malloc(sizeof(t_image));
	if (!cub->gun_[2])
		print_and_exit(MALLOC_FAILED, cub, 0);
}

void	draw_pixel(t_image *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

void	draw_gunn(t_image *img, t_image *gun, int x, int y)
{
	int				j;
	int				i;
	unsigned int	color;

	i = 0;
	j = 0;
	color = *(int *)(gun->addr + y * gun->line_length + x
			* (gun->bits_per_pixel / 8));
	if (color != 0xFF000000)
	{
		while (i < 2)
		{
			while (j < 2)
			{
				draw_pixel(img, (x * 2 + j) + SCREEN_WIDTH / 2,
					(y * 2 + i) + SCREEN_HEIGHT - 128 * 2, color);
				j++;
			}
			j = 0;
			i++;
		}
	}
}

void	select_image(t_cub *cub, t_image **gun)
{
	static int	i;
	int			tmp;

	tmp = i / 5;
	if (tmp == 0)
		*gun = cub->gun_[1];
	else if (tmp == 1)
		*gun = cub->gun_[2];
	else if (tmp == 2)
		*gun = cub->gun_[3];
	else if (tmp == 3)
		*gun = cub->gun_[4];
	else if (tmp == 4)
	{
		*gun = cub->gun_[0];
		cub ->shoot = _false;
		i = -1;
	}
	i++;
}

void	draw(t_cub *cub, t_image *img)
{
	int			x;
	int			y;
	t_image		*gun;

	x = 0;
	y = 0;
	cub->gun_index = 0;
	if (cub->shoot == _true)
		select_image(cub, &gun);
	else
		gun = cub->gun_[0];
	while (y < 128)
	{
		while (x < 128)
		{
			draw_gunn(img, gun, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
