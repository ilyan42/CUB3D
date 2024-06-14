/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:57:53 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:43:56 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	raycasting(void *param)
{
	t_cub	*cub;
	int		x;

	cub = (t_cub *)param;
	x = 0;
	ft_handle_key_press(cub);
	while (x < cub->res_x)
	{
		init_raycast(cub, cub->raycast, x);
		get_step_and_side_dist(cub, cub->raycast);
		perform_dda(cub, cub->raycast);
		get_distance(cub, cub->raycast);
		init_draw_start_end(cub);
		draw_floor_ceilling(cub, x, cub->raycast->draw_start, cub->raycast);
		draw_wall(cub, x, cub->raycast);
		x++;
	}
	draw(cub, cub->image);
	mlx_put_image_to_window(cub->mlx->mlx_ptr,
		cub->mlx->win, cub->image->img, 0, 0);
}
