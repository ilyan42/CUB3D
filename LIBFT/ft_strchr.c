/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:31:21 by ilbendib          #+#    #+#             */
/*   Updated: 2023/11/10 14:34:33 by ilbendib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = (char)c;
	while (s[i])
	{
		if (s[i] == tmp)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == tmp)
		return ((char *)s + i);
	return (0);
}
