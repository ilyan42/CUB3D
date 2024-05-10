/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:20:45 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/13 10:32:23 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_d;
	char	*tmp_s;

	if (!dest && !src)
		return (NULL);
	tmp_d = (char *)dest;
	tmp_s = (char *)src;
	i = 0;
	if (tmp_d > tmp_s)
	{
		while (n-- > 0)
			tmp_d[n] = tmp_s[n];
	}
	else
	{
		while (i < n)
		{
			tmp_d[i] = tmp_s[i];
			i++;
		}
	}
	return (dest);
}
