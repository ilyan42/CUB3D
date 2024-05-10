/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:41 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/10 11:23:13 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	tmp_c;

	i = 0;
	tmp_c = (unsigned char)c;
	tmp = (unsigned char *)s;
	while (i < n)
	{
		if (tmp[i] == tmp_c)
			return ((void *)&tmp[i]);
		i++;
	}
	return (NULL);
}
