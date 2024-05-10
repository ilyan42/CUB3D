/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:25:08 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/09 10:49:39 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	srcl;
	unsigned int	desl;

	i = 0;
	j = 0;
	while (dst[i])
	{
		i++;
	}
	desl = i;
	srcl = ft_strlen(src);
	if (size == 0 || size <= i)
		return (size + srcl);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (desl + srcl);
}
