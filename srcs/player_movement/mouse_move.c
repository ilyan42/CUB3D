/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:10:44 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/07 11:44:37 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	mouse_move(int x, int y, t_cub *cub)
{
	static int	last_x = -1;
	int			delta_x;

	(void)y;
	if (last_x == -1)
	{
		last_x = x;
		return (0);
	}
	delta_x = x - last_x;
	last_x = x;
	if (delta_x > 0)
		cam_rotate_right(cub, delta_x * MOUSE_SENSITIVITY);
	else if (delta_x < 0)
		cam_rotate_left(cub, -delta_x * MOUSE_SENSITIVITY);
	return (0);
}
