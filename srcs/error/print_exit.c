/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:15:14 by ilbendib          #+#    #+#             */
/*   Updated: 2024/06/14 11:11:04 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_and_exit(char *msg, t_cub *cub, int err)
{
	ft_printf("%s", msg);
	if (cub->texture->texture)
		free_textures(cub);
	clear_before_exit(cub, err);
	exit(EXIT_FAILURE);
}
