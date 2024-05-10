/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:18:51 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/15 10:23:52 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;

	if (!dest && !src)
		return (dest);
	tmp_d = (unsigned char *)dest;
	tmp_s = (unsigned char *)src;
	while (n > 0)
	{
		*(tmp_d++) = *(tmp_s++);
		n--;
	}
	return (dest);
}
